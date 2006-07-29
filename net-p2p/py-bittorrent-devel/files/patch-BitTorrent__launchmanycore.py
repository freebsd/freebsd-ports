--- ./BitTorrent/launchmanycore.py.orig	Wed Jul 12 02:18:34 2006
+++ ./BitTorrent/launchmanycore.py	Fri Jul 28 23:45:22 2006
@@ -22,14 +22,17 @@
 from traceback import print_exc
 import logging
 from BitTorrent import configfile
+from BitTorrent import platform
 from BitTorrent.parsedir import parsedir
-from BitTorrent.MultiTorrent import MultiTorrent, Feedback
+from BitTorrent.MultiTorrent import MultiTorrent, Feedback, TorrentAlreadyRunning, TorrentAlreadyInQueue, TorrentNotInitialized
 from BitTorrent.ConvertedMetainfo import ConvertedMetainfo
 from BitTorrent import BTFailure, UserFailure
 from BitTorrent.RawServer_twisted import RawServer
 from BitTorrent.yielddefer import launch_coroutine, _wrap_task
 from BitTorrent.ConvertedMetainfo import ConvertedMetainfo
 from BitTorrent.defer import DeferredEvent
+from BitTorrent.platform import encode_for_filesystem
+from BitTorrent.prefs import Preferences
 from time import time
 
 
@@ -51,13 +54,13 @@
       # logger Formatter, which is specific to exceptions, warnings, and
       # info messages.
       try:
+        self.display = display.display
         self.logger = logging.getLogger(configfile_key)
         
         self.multitorrent = None
         self.rawserver = None
-        self.config = config
+        self.config = Preferences().initWithDict(config)
         self.configfile_key = configfile_key
-        self.display = display
 
         self.torrent_dir = config['torrent_dir']
 
@@ -78,30 +81,31 @@
 
         self.hashcheck_queue = []
         self.hashcheck_store = {}
-        self.hashcheck_current = None
                          
         self.core_doneflag = DeferredEvent()
-        rawserver_doneflag = DeferredEvent() 
+        self.rawserver_doneflag = DeferredEvent() 
         self.rawserver = RawServer(self.config)
         try:
    
             # set up shut-down procedure before we begin doing things that
             # can throw exceptions.
             def shutdown():
-                print "SHUTDOWNSHUTDOWNSHUTDOWN"
+                #print "SHUTDOWNSHUTDOWNSHUTDOWN"
                 self.logger.critical(_("shutting down"))
-                for infohash in self.multitorrent.get_torrents():
-                    self.logger.info(_('dropped "%s"') %
-                                    self.torrent_cache[infohash]['path'])
-                #    torrent = self.downloads[infohash]
-                #    if torrent is not None:
-                #        torrent.shutdown()
+                for torrent in self.multitorrent.get_torrents():
+                    try:
+                        removed = self.torrent_cache[torrent.infohash]['path']
+                        self.logger.info(_('dropped "%s"') % removed)
+                    except KeyError:
+                        pass
+                    if torrent is not None:
+                        torrent.shutdown()
                 if self.multitorrent:
                     df = self.multitorrent.shutdown()
-                    set_flag = lambda *a : rawserver_doneflag.set()
+                    set_flag = lambda *a : self.rawserver_doneflag.set()
                     df.addCallbacks(set_flag, set_flag)
                 else:
-                    rawserver_doneflag.set()
+                    self.rawserver_doneflag.set()
                 
             # It is safe to addCallback here, because there is only one thread,
             # but even if the code were multi-threaded, core_doneflag has not
@@ -112,9 +116,9 @@
    
             self.rawserver.install_sigint_handler(self.core_doneflag)
     
-            data_dir = config['data_dir']
-            print "Creating MultiTorrent"
-            self.multitorrent = MultiTorrent(config, self.rawserver, data_dir)
+            data_dir = self.config['data_dir']
+            #print "Creating MultiTorrent"
+            self.multitorrent = MultiTorrent(self.config, self.rawserver, data_dir)
     
             self.rawserver.add_task(0, self.scan)
             self.rawserver.add_task(0, self.stats)
@@ -131,162 +135,221 @@
                 self.rawserver.add_task(0,self.core_doneflag.set())
   
         except UserFailure, e:
-            output.exception(unicode(e.args[0]))
+            display.exception(unicode(e.args[0]))
             self.rawserver.add_task(0,self.core_doneflag.set())
         except:
             data = StringIO()
             print_exc(file = data)
-            output.exception(data.getvalue())
+            display.exception(data.getvalue())
             self.rawserver.add_task(0,self.core_doneflag.set())
            
         # always make sure events get processed even if only for
         # shutting down.
-        print "listening forever"
-        self.rawserver.listen_forever(rawserver_doneflag)
+        #print "listening forever"
+        try:
+            self.rawserver.listen_forever(self.rawserver_doneflag)
+        except AttributeError, e:
+            output.message(str(e))
+            raise
+        except KeyboardInterrupt: 
+            raise
         
       except:
         data = StringIO()
         print_exc(file = data)
-        output.exception(data.getvalue())
+        display.exception(data.getvalue())
+        self.core_doneflag.set()
+        self.rawserver_doneflag.set()
 
     def scan(self):
-        print "LaunchMany.scan top."
+        #print "LaunchMany.scan top."
         self.rawserver.add_task(self.config['parse_dir_interval'], self.scan)
 
         r = parsedir(self.torrent_dir, self.torrent_cache,
                      self.file_cache, self.blocked_files,
                      self.logger.error)
 
-        print "After parsedir"
+        #print "After parsedir"
         ( self.torrent_cache, self.file_cache, self.blocked_files,
             added, removed ) = r
         for infohash, data in removed.items():
             self.logger.info(_('dropped "%s"') % data['path'])
             self.remove(infohash)
         for infohash, data in added.items():
-            print "adding item:", data['path']
+            #print "adding item:", data['path']
             self.logger.info(_('added "%s"'  ) % data['path'])
-            print "after self.logger.info"
+            #print "after self.logger.info"
             if self.config['launch_delay'] > 0:
                 self.rawserver.add_task(self.config['launch_delay'], self.add, infohash, data)
             # torrent may have been known from resume state.
             elif not self.multitorrent.torrent_known(infohash):
                 self.add(infohash, data)
-        print "LaunchMany.scan bottom"
+        #print "LaunchMany.scan bottom"
 
     def stats(self):
         self.rawserver.add_task(self.config['display_interval'], self.stats)
         data = []
-        for d in self.get_torrents():
-            infohash = d.infohash
-            cache = self.torrent_cache[infohash]
-            if self.config['display_path']:
-                name = cache['path']
-            else:
-                name = cache['name']
-            size = cache['length']
-            #d = self.downloads[infohash]
-            progress = '0.0%'
-            peers = 0
-            seeds = 0
-            seedsmsg = "S"
-            dist = 0.0
-            uprate = 0.0
-            dnrate = 0.0
-            upamt = 0
-            dnamt = 0
-            t = 0
-            msg = ''
-            #if d.state in ["created", "initializing"]:
-            #    status = _("waiting for hash check")
-            #else:
-            stats = d.get_status()
-            status = stats['activity']
-            progress = '%.1f%%' % (int(stats['fractionDone']*1000)/10.0)
-            if d.is_running():
-                s = stats
-                dist = s['numCopies']
-                if d.is_seed:
-                    seeds = 0 # s['numOldSeeds']
-                    seedsmsg = "s"
+        for d in self.multitorrent.get_torrents():
+            if d is not None:
+                infohash = d.infohash
+                try:
+                    cache = self.torrent_cache[infohash]
+                except KeyError:
+                    self.remove(infohash)
+                    continue
+                if self.config['display_path']:
+                    name = cache['path']
                 else:
-                    if s['numSeeds'] + s['numPeers']:
-                        t = stats['timeEst']
-                        if t is None:
-                            t = -1
-                        if t == 0:  # unlikely
-                            t = 0.01
-                        status = _("downloading")
+                    name = cache['name']
+                size = cache['length']
+                progress = '0.0%'
+                peers = 0
+                seeds = 0
+                seedsmsg = "S"
+                dist = 0.0
+                uprate = 0.0
+                dnrate = 0.0
+                upamt = 0
+                dnamt = 0
+                t = 0
+                msg = ''
+                #if d.state in ["created", "initializing"]:
+                #    status = _("waiting for hash check")
+                #else:
+                stats = d.get_status()
+                status = stats['activity']
+                progress = '%.1f%%' % (int(stats['fractionDone']*1000)/10.0)
+                if d.is_running():
+                    s = stats
+                    dist = int(s['distributed_copies'])
+                    if d.is_seeding():
+                        seeds = 0 # s['numOldSeeds']
+                        seedsmsg = "s"
                     else:
-                        t = -1
-                        status = _("connecting to peers")
-                    seeds = s['numSeeds']
-                    dnrate = stats['downRate']
-                peers = s['numPeers']
-                uprate = stats['upRate']
-                upamt = s['upTotal']
-                dnamt = s['downTotal']
+                        if s['numSeeds'] + s['numPeers']:
+                            t = stats['timeEst']
+                            if t is None:
+                                t = -1
+                            if t == 0:  # unlikely
+                                t = 0.01
+                            status = _("downloading")
+                        else:
+                            t = -1
+                            status = _("connecting to peers")
+                        seeds = s['numSeeds']
+                        dnrate = stats['downRate']
+                    peers = s['numPeers']
+                    uprate = stats['upRate']
+                    upamt = s['upTotal']
+                    dnamt = s['downTotal']
 
-            data.append(( name, status, progress, peers, seeds, seedsmsg, dist,
+                data.append(( name, status, progress, peers, seeds, seedsmsg, dist,
                           uprate, dnrate, upamt, dnamt, size, t, msg ))
         stop = self.display(data)
         if stop:
             self.core_doneflag.set()
 
     def remove(self, infohash):
-        self.torrent_list.remove(infohash)
-        if self.downloads[infohash] is not None:
-            self.downloads[infohash].shutdown()
+        torrent = self.multitorrent.get_torrent(infohash)
+        if torrent is not None:
+            torrent.shutdown()
         self.was_stopped(infohash)
-        del self.downloads[infohash]
 
     def add(self, infohash, data):
-
         # data is a dict like
         # { path:'/a/b/c.torrent', file:'c.torrent', length:90911, name:'Sea',
         #   metainfo: <metainfo>}  Metainfo has bdecoded but not passed
         # to ConvertedMetainfo.
-        self.torrent_list.append(infohash)
-        self.downloads[infohash] = None
         self.hashcheck_queue.append(infohash)
         self.hashcheck_store[infohash] = ConvertedMetainfo(data['metainfo'])
         self.check_hashcheck_queue()
 
     def check_hashcheck_queue(self):
-        if self.hashcheck_current is not None or not self.hashcheck_queue:
+        if not self.hashcheck_queue:
             return
-        infohash = self.hashcheck_current = self.hashcheck_queue.pop(0)
+        infohash = self.hashcheck_queue.pop(0)
         metainfo = self.hashcheck_store[infohash]
         del self.hashcheck_store[infohash]
-        filename = self.determine_filename(infohash)
+        save_incomplete_as, save_as = self.determine_filename(infohash)
+        saveas_style_save_incomplete_as, saveas_style_save_as = self._determine_filename(infohash)
         torrent_path = self.torrent_cache[infohash]['path']
-        self.start_torrent(torrent_path, metainfo, filename, filename)
+        self.start_torrent(torrent_path, metainfo, save_incomplete_as,save_as,
+                           saveas_style_save_incomplete_as, saveas_style_save_as)
 
-    def start_torrent(self,torrent_path,metainfo,save_incomplete_as,save_as):
+    def start_torrent(self,torrent_path,metainfo,save_incomplete_as,save_as,
+                      saveas_style_save_incomplete_as=None,saveas_style_save_as=None):
         assert isinstance(metainfo, ConvertedMetainfo)
         df = launch_coroutine(_wrap_task(self.rawserver.add_task),
                               self._start_torrent, metainfo,
-                              save_incomplete_as, save_as)
+                              save_incomplete_as, save_as,
+                              saveas_style_save_incomplete_as=saveas_style_save_incomplete_as,
+                              saveas_style_save_as=saveas_style_save_as)
         df.addErrback(lambda e : self.logger.error(_("DIED: "),exc_info=e))
         return df
 
-    def _start_torrent(self, metainfo, save_incomplete_as,save_as):
+    def _start_torrent(self, metainfo, save_incomplete_as,save_as,
+                       saveas_style_save_incomplete_as,saveas_style_save_as):
         assert isinstance(metainfo, ConvertedMetainfo)
-        df = self.multitorrent.create_torrent(metainfo,
-                                              save_incomplete_as, save_as)
-        yield df
-        torrent = self.multitorrent.get_torrent(metainfo.infohash)
-        if torrent.is_initialized():
-           multitorrent.start_torrent(metainfo.infohash)
-        #else:  ????  # this would be an error condition already reported
-                      # to logger.
-        check_hashcheck_queue()
+        save_incomplete_as, junk = platform.encode_for_filesystem(save_incomplete_as)
+        save_as, junk = platform.encode_for_filesystem(save_as)
+        if saveas_style_save_incomplete_as is not None:
+            saveas_style_save_incomplete_as, junk = platform.encode_for_filesystem(saveas_style_save_incomplete_as)
+        if saveas_style_save_as is not None:
+            saveas_style_save_as, junk = platform.encode_for_filesystem(saveas_style_save_as)
+        try:
+            df = self.multitorrent.create_torrent(metainfo,
+                                              save_incomplete_as, save_as,
+                                              saveas_style_save_incomplete_as,
+                                              saveas_style_save_as)
+            yield df
+            df.getResult()
+        except (TorrentAlreadyRunning, TorrentAlreadyInQueue):
+            pass
+        except:
+            raise
 
-    def determine_filename(self, infohash):
+        infohash = metainfo.infohash
+
+        # find out if torrent has been recorded
+        try:
+            torrent = self.multitorrent.get_torrent(infohash)
+            if not torrent or torrent is None:
+                raise UnknownInfohash(infohash.encode("hex"))
+        except:
+            raise
+
+        # function to requeue torrent if has not been initialized just yet
+        def hashcheck_requeue(infohash):
+            df = self.remove(infohash)
+            data = self.torrent_cache[infohash]
+            if self.config['launch_delay'] > 0:
+                self.rawserver.add_task(self.config['launch_delay'], self.add, infohash, data)
+            else:
+                # wait at least 1
+                self.rawserver.add_task(1, self.add, infohash, data)
+
+        # Is it running?
+        running = self.multitorrent.torrent_running(infohash)
+        if not running:
+            try:
+                if torrent.is_initialized():
+                    df = self.multitorrent.start_torrent(infohash)
+                    yield df
+                    df.getResult()
+                else:
+                    raise TorrentNotInitialized
+            except TorrentAlreadyRunning:
+                pass
+            except TorrentNotInitialized:
+                hashcheck_requeue(infohash)
+            except:
+                raise
+
+        self.check_hashcheck_queue()
+
+    def determine_saveas_style(self, infohash):
         x = self.torrent_cache[infohash]
         name = x['name']
-        savein = self.config['save_in']
-        isdir = not x['metainfo']['info'].has_key('length')
         style = self.config['saveas_style']
         if style == 4:
             torrentname   = os.path.split(x['path'][:-8])[1]
@@ -295,20 +358,54 @@
                 style = 1
             else:
                 style = 3
+        return style
+
+    # Specially handle the style 3 case.
+    # Style 3 breaks Torrent.move so we have an intermediate
+    # _determine_filename for Torrent.move benefit
+    # but determine_filename for general use
+    def determine_filename(self, infohash):
+        x = self.torrent_cache[infohash]
+        name = x['name']
+        isdir = not x['metainfo']['info'].has_key('length')
+        style = self.determine_saveas_style(infohash)
+        saveincompleteas, saveas = self._determine_filename(infohash)
+
+        # add filename
+        if style == 3 and not isdir:
+            saveas = os.path.join(saveas, name)
+            saveincompleteas = os.path.join(saveincompleteas, name)
+
+        return saveincompleteas, saveas
+
+    # generate paths appropriate for Torrent.move method
+    def _determine_filename(self, infohash):
+        x = self.torrent_cache[infohash]
+        name = x['name']
+        savein = self.config['save_in']
+        saveincompletein = self.config['save_incomplete_in']
+        style = self.determine_saveas_style(infohash)
 
         if style == 1 or style == 3:
             if savein:
                 saveas = os.path.join(savein,x['file'][:-8]) # strip '.torrent'
             else:
                 saveas = x['path'][:-8] # strip '.torrent'
-            if style == 3 and not isdir:
-                saveas = os.path.join(saveas, name)
+            if saveincompletein:
+                saveincompleteas = os.path.join(saveincompletein, x['file'][:-8]) # strip '.torrent'
+            else:
+                saveincompleteas = x['path'][:-8] # strip '.torrent'
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
+        return saveincompleteas, saveas
 
     def was_stopped(self, infohash):
         try:
@@ -317,8 +414,6 @@
             pass
         else:
             del self.hashcheck_store[infohash]
-        if self.hashcheck_current == infohash:
-            self.hashcheck_current = None
         self.check_hashcheck_queue()
 
     # Exceptions are now reported via loggers.<
@@ -343,7 +438,7 @@
         # the self.failed() callback can run during this loop.
         for option, value in newvalues.iteritems():
             self.multitorrent.set_option(option, value)
-        for torrent in self.downloads.values():
+        for torrent in self.multitorrent.get_torrents():
             if torrent is not None:
                 for option, value in newvalues.iteritems():
                     torrent.set_option(option, value)
