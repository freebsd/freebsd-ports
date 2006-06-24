--- BitTorrent/launchmanycore.py.orig	Mon Jun 12 22:45:59 2006
+++ BitTorrent/launchmanycore.py	Sat Jun 24 14:47:28 2006
@@ -13,28 +13,33 @@
 # Original version written by John Hoffman, heavily modified for different
 # multitorrent architecture by Uoti Urpala (over 40% shorter than original)
 
-raise ImportError("launchmanycore has not been ported to the 5.0 backend. Please look for it in a future release. Thanks for your patience.")
-
 import os
 from cStringIO import StringIO
 from traceback import print_exc
 from BitTorrent.translation import _
 
+from BitTorrent import BTFailure
 from BitTorrent import configfile
-from BitTorrent.parsedir import parsedir
-from BitTorrent.download import Multitorrent, Feedback
+from BitTorrent import zurllib
+from BitTorrent.AutoUpdateButler import AutoUpdateButler
 from BitTorrent.ConvertedMetainfo import ConvertedMetainfo
-from BitTorrent import BTFailure
+from BitTorrent.MultiTorrent import MultiTorrent, TorrentAlreadyRunning, TorrentAlreadyInQueue, TorrentNotInitialized
+from BitTorrent.RawServer_twisted import RawServer
+from BitTorrent.Torrent import Torrent
+from BitTorrent.TorrentPolicy import Policy
+from BitTorrent.defer import DeferredEvent
+from BitTorrent.parsedir import parsedir
+from BitTorrent.prefs import Preferences
 
-from threading import Event
 from time import time
 
-
-class LaunchMany(Feedback):
+class LaunchMany(Policy):
 
     def __init__(self, config, output, configfile_key):
+        zurllib.add_unsafe_thread()
+
         try:
-            self.config = config
+            self.config = Preferences().initWithDict(config)
             self.output = output
             self.configfile_key = configfile_key
 
@@ -45,15 +50,30 @@
 
             self.torrent_list = []
             self.downloads = {}
-            self.doneflag = Event()
+
+            self.doneflag = DeferredEvent()
+            self.rawserver_doneflag = DeferredEvent()
 
             self.hashcheck_queue = []
             self.hashcheck_store = {}
-            self.hashcheck_current = None
 
-            self.multitorrent = MultiTorrent(config, self.doneflag,
-                                             self.global_error)
-            self.rawserver = self.multitorrent.rawserver
+            self.rawserver = RawServer(self.config)
+            zurllib.set_zurllib_rawserver(self.rawserver)
+            self.rawserver.associate_thread()
+
+            data_dir = self.config['data_dir']
+            self.multitorrent = \
+                MultiTorrent(self.config, self.doneflag, self.rawserver, data_dir)
+
+            # to handle the callbacks
+            self.multitorrent.add_policy(self)
+
+#            auto_update_butler = AutoUpdateButler(self.multitorrent, self.rawserver,
+#                                                  test_new_version=self.config['new_version'],
+#                                                  test_current_version=self.config['current_version'])
+#            self.multitorrent.add_auto_update_policy(auto_update_butler)
+#            self.rawserver.add_task(0, auto_update_butler.check_version)
+
 
             self.rawserver.add_task(0, self.scan)
             self.rawserver.add_task(0, self.stats)
@@ -63,23 +83,40 @@
                 def handler(signum, frame):
                     self.rawserver.external_add_task(0, self.read_config)
                 signal.signal(signal.SIGHUP, handler)
-                self.rawserver.install_sigint_handler()
+                self.rawserver.install_sigint_handler(self.doneflag)
             except Exception, e:
                 self.output.message(_("Could not set signal handler: ") + str(e))
 
-            self.rawserver.listen_forever()
+            def shutdown():
+                self.output.message(_("shutting down"))
+                for infohash in self.torrent_list:
+                    self.output.message(_('dropped "%s"') %
+                        self.torrent_cache[infohash]['path'])
+                    torrent = self.downloads[infohash]
+                    if torrent is not None:
+                        torrent.shutdown()
+                if self.multitorrent:
+                    df = self.multitorrent.shutdown()
+                set_flag = lambda *a : self.rawserver_doneflag.set()
+                df.addCallbacks(set_flag, set_flag)
+
+            self.rawserver.add_task(0, self.doneflag.addCallback, \
+                lambda r: self.rawserver.external_add_task(0, shutdown))
+
+            try:
+                self.rawserver.listen_forever(self.rawserver_doneflag)
+            except AttributeError, e:
+                output.message(str(e))
+                raise
+            except KeyboardInterrupt:
+                raise
 
-            self.output.message(_("shutting down"))
-            for infohash in self.torrent_list:
-                self.output.message(_('dropped "%s"') %
-                                    self.torrent_cache[infohash]['path'])
-                torrent = self.downloads[infohash]
-                if torrent is not None:
-                    torrent.shutdown()
         except:
             data = StringIO()
             print_exc(file = data)
             output.exception(data.getvalue())
+            self.doneflag.set()
+            self.rawserver_doneflag.set()
 
     def scan(self):
         self.rawserver.add_task(self.config['parse_dir_interval'], self.scan)
@@ -122,17 +159,16 @@
             upamt = 0
             dnamt = 0
             t = 0
-            msg = ''
             if d is None:
                 status = _("waiting for hash check")
             else:
                 stats = d.get_status()
                 status = stats['activity']
                 progress = '%.1f%%' % (int(stats['fractionDone']*1000)/10.0)
-                if d.started and not d.closed:
+                if d.is_running() and d.is_context_valid():
                     s = stats
-                    dist = s['numCopies']
-                    if d.is_seed:
+                    dist = int(s['distributed_copies'])
+                    if d.is_seeding():
                         seeds = 0 # s['numOldSeeds']
                         seedsmsg = "s"
                     else:
@@ -152,11 +188,9 @@
                     uprate = stats['upRate']
                     upamt = s['upTotal']
                     dnamt = s['downTotal']
-                if d.errors and (d.closed or d.errors[-1][0] + 300 > time()):
-                    msg = d.errors[-1][2]
 
             data.append(( name, status, progress, peers, seeds, seedsmsg, dist,
-                          uprate, dnrate, upamt, dnamt, size, t, msg ))
+                          uprate, dnrate, upamt, dnamt, size, t ))
         stop = self.output.display(data)
         if stop:
             self.doneflag.set()
@@ -176,22 +210,55 @@
         self.check_hashcheck_queue()
 
     def check_hashcheck_queue(self):
-        if self.hashcheck_current is not None or not self.hashcheck_queue:
+        if not self.hashcheck_queue:
+           return
+        infohash = self.hashcheck_queue.pop(0)
+        x = self.hashcheck_store[infohash]
+        metainfo = ConvertedMetainfo(x)
+        del self.hashcheck_store[infohash]
+
+        if not self.torrent_cache[infohash] or self.torrent_cache[infohash] is None:
+            raise
+
+        if not self.multitorrent.torrent_known(infohash):
+            try:
+                (save_as, save_incomplete_as) = self.determine_filename(infohash)
+                df = self.multitorrent.create_torrent(metainfo, save_incomplete_as, save_as)
+            except (TorrentAlreadyRunning, TorrentAlreadyInQueue):
+                pass
+            except:
+                raise
+
+        try:
+            if not self.multitorrent.torrent_running(infohash):
+                df = self.multitorrent.start_torrent(infohash)
+        except TorrentAlreadyRunning:
+            pass
+        except TorrentNotInitialized:
+            # requeue
+            self.remove(infohash)
+            data = self.torrent_cache[infohash]
+            if self.config['launch_delay'] > 0:
+                self.rawserver.add_task(self.config['launch_delay'], self.add, infohash, data)
+            else:
+                # wait at least 1
+                self.rawserver.add_task(1, self.add, infohash, data)
             return
-        self.hashcheck_current = self.hashcheck_queue.pop(0)
-        metainfo = self.hashcheck_store[self.hashcheck_current]
-        del self.hashcheck_store[self.hashcheck_current]
-        filename = self.determine_filename(self.hashcheck_current)
-        self.downloads[self.hashcheck_current] = self.multitorrent. \
-                          start_torrent(ConvertedMetainfo(metainfo),
-                                        self.config, self, filename)
+        except:
+            raise
+
+        # record if everything has gone right
+        self.downloads[infohash] = \
+            self.multitorrent.get_torrent(infohash)
 
     def determine_filename(self, infohash):
         x = self.torrent_cache[infohash]
         name = x['name']
         savein = self.config['save_in']
+        saveincompletein = self.config['save_incomplete_in']
         isdir = not x['metainfo']['info'].has_key('length')
         style = self.config['saveas_style']
+
         if style == 4:
             torrentname   = os.path.split(x['path'][:-8])[1]
             suggestedname = name
@@ -202,17 +269,27 @@
 
         if style == 1 or style == 3:
             if savein:
-                saveas = os.path.join(savein,x['file'][:-8]) # strip '.torrent'
+                saveas = os.path.join(savein, x['file'][:-8]) # strip '.torrent'
             else:
                 saveas = x['path'][:-8] # strip '.torrent'
+            if saveincompletein:
+                saveincompleteas = os.path.join(saveincompletein, x['file'][:-8]) # strip '.torrent'
+            else:
+                saveincompleteas = x['path'][:-8] # strip '.torrent'
             if style == 3 and not isdir:
                 saveas = os.path.join(saveas, name)
+                saveincompleteas = os.path.join(saveincompleteas, name)
         else:
             if savein:
                 saveas = os.path.join(savein, name)
             else:
                 saveas = os.path.join(os.path.split(x['path'])[0], name)
-        return saveas
+            if saveincompletein:
+                saveincompleteas = os.path.join(saveincompletein, name)
+            else:
+                saveincompleteas = os.path.join(os.path.split(x['path'])[0], name)
+
+        return saveas, saveincompleteas
 
     def was_stopped(self, infohash):
         try:
@@ -221,8 +298,6 @@
             pass
         else:
             del self.hashcheck_store[infohash]
-        if self.hashcheck_current == infohash:
-            self.hashcheck_current = None
         self.check_hashcheck_queue()
 
     def global_error(self, level, text):
@@ -253,7 +328,6 @@
     # rest are callbacks from torrent instances
 
     def started(self, torrent):
-        self.hashcheck_current = None
         self.check_hashcheck_queue()
 
     def failed(self, torrent):
