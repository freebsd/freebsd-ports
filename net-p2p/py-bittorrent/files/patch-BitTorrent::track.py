--- BitTorrent/track.py	Sun Mar 21 16:32:55 2004
+++ BitTorrent/track.py	Sun Jun  6 09:33:07 2004
@@ -37,12 +37,15 @@
         'minimum time it must have been since the last flush to do another one'),
     ('allowed_dir', '', 'only allow downloads for .torrents in this dir'),
     ('parse_allowed_interval', 15, 'minutes between reloading of allowed_dir'),
+    ('show_infopage', 1, "whether to display an info page when the tracker's root dir is loaded"),
+    ('infopage_redirect', '', 'a URL to redirect the info page to'),
     ('show_names', 1, 'whether to display names from allowed dir'),
     ('favicon', '', 'file containing x-icon data to return when browser requests favicon.ico'),
     ('only_local_override_ip', 1, "ignore the ip GET parameter from machines which aren't on local network IPs"),
     ('logfile', '', 'file to write the tracker logs, use - for stdout (default)'),
     ('allow_get', 0, 'use with allowed_dir; adds a /file?hash={hash} url that allows users to download the torrent file'),
     ('keep_dead', 0, 'keep dead torrents after they expire (so they still show up on your /scrape and web page)'),
+    ('scrape_allowed', 'full', 'scrape access allowed (can be none, specific or full)'),
     ('max_give', 200, 'maximum number of peers to give with any one request'),
     ]
 
@@ -124,11 +127,11 @@
         favicon = config['favicon']
         self.favicon = None
         if favicon:
-            if isfile(favicon):
+            try:
                 h = open(favicon, 'rb')
                 self.favicon = h.read()
                 h.close()
-            else:
+            except:
                 print "**warning** specified favicon file -- %s -- does not exist." % favicon
         self.rawserver = rawserver
         self.becache1 = {}
@@ -190,6 +193,130 @@
             self.uq_broken = 0
         self.keep_dead = config['keep_dead']
 
+    def get_infopage(self):
+        if not self.config['show_infopage']:
+            return (404, 'Not Found', {'Content-Type': 'text/plain', 'Pragma': 'no-cache'}, alas)
+        red = self.config['infopage_redirect']
+        if red != '':
+            return (302, 'Found', {'Content-Type': 'text/html', 'Location': red},
+                    '<A HREF="'+red+'">Click Here</A>')
+
+        s = StringIO()
+        s.write('<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">\n' \
+            '<html><head><title>BitTorrent download info</title>\n')
+        if self.favicon != None:
+            s.write('<link rel="shortcut icon" href="/favicon.ico" />\n')
+        s.write('</head>\n<body>\n' \
+            '<h3>BitTorrent download info</h3>\n'\
+            '<ul>\n'
+            '<li><strong>tracker version:</strong> %s</li>\n' \
+            '<li><strong>server time:</strong> %s</li>\n' \
+            '</ul>\n' % (version, isotime()))
+        names = self.downloads.keys()
+        if not names:
+            s.write('<p>not tracking any files yet...</p>\n')
+        else:
+            names.sort()
+            tn = 0
+            tc = 0
+            td = 0
+            tt = 0  # Total transferred
+            ts = 0  # Total size
+            nf = 0  # Number of files displayed
+            uc = {}
+            ud = {}
+            if self.allowed != None and self.show_names:
+                s.write('<table summary="files" border="1">\n' \
+                    '<tr><th>info hash</th><th>torrent name</th><th align="right">size</th><th align="right">complete</th><th align="right">downloading</th><th align="right">downloaded</th><th align="right">transferred</th></tr>\n')
+            else:
+                s.write('<table summary="files">\n' \
+                    '<tr><th>info hash</th><th align="right">complete</th><th align="right">downloading</th><th align="right">downloaded</th></tr>\n')
+            for name in names:
+                l = self.downloads[name]
+                n = self.completed.get(name, 0)
+                tn = tn + n
+                lc = []
+                for i in l.values():
+                    if type(i) == DictType:
+                        if i['left'] == 0:
+                            lc.append(1)
+                            uc[i['ip']] = 1
+                        else:
+                            ud[i['ip']] = 1
+                c = len(lc)
+                tc = tc + c
+                d = len(l) - c
+                td = td + d
+                if self.allowed != None and self.show_names:
+                    if self.allowed.has_key(name):
+                        nf = nf + 1
+                        sz = self.allowed[name]['length']  # size
+                        ts = ts + sz
+                        szt = sz * n   # Transferred for this torrent
+                        tt = tt + szt
+                        if self.allow_get == 1:
+                            linkname = '<a href="/file?info_hash=' + quote(name) + '">' + self.allowed[name]['name'] + '</a>'
+                        else:
+                            linkname = self.allowed[name]['name']
+                        s.write('<tr><td><code>%s</code></td><td>%s</td><td align="right">%s</td><td align="right">%i</td><td align="right">%i</td><td align="right">%i</td><td align="right">%s</td></tr>\n' \
+                            % (b2a_hex(name), linkname, size_format(sz), c, d, n, size_format(szt)))
+                else:
+                    s.write('<tr><td><code>%s</code></td><td align="right"><code>%i</code></td><td align="right"><code>%i</code></td><td align="right"><code>%i</code></td></tr>\n' \
+                        % (b2a_hex(name), c, d, n))
+            ttn = 0
+            for i in self.completed.values():
+                ttn = ttn + i
+            if self.allowed != None and self.show_names:
+                s.write('<tr><td align="right" colspan="2">%i files</td><td align="right">%s</td><td align="right">%i/%i</td><td align="right">%i/%i</td><td align="right">%i/%i</td><td align="right">%s</td></tr>\n'
+                        % (nf, size_format(ts), len(uc), tc, len(ud), td, tn, ttn, size_format(tt)))
+            else:
+                s.write('<tr><td align="right">%i files</td><td align="right">%i/%i</td><td align="right">%i/%i</td><td align="right">%i/%i</td></tr>\n'
+                        % (nf, len(uc), tc, len(ud), td, tn, ttn))
+            s.write('</table>\n' \
+                '<ul>\n' \
+                '<li><em>info hash:</em> SHA1 hash of the "info" section of the metainfo (*.torrent)</li>\n' \
+                '<li><em>complete:</em> number of connected clients with the complete file (total: unique IPs/total connections)</li>\n' \
+                '<li><em>downloading:</em> number of connected clients still downloading (total: unique IPs/total connections)</li>\n' \
+                '<li><em>downloaded:</em> reported complete downloads (total: current/all)</li>\n' \
+                '<li><em>transferred:</em> torrent size * total downloaded (does not include partial transfers)</li>\n' \
+                '</ul>\n')
+        s.write('</body>\n' \
+            '</html>\n')
+        return (200, 'OK', {'Content-Type': 'text/html; charset=iso-8859-1'}, s.getvalue())
+
+    def scrapedata(self, name, return_name = True):
+        l = self.downloads[name]
+        n = self.completed.get(name, 0)
+        c = len([1 for i in l.values() if i['left'] == 0])
+        d = len(l) - c
+        f = {'complete': c, 'incomplete': d, 'downloaded': n}
+        if ( return_name and self.show_names
+             and self.allowed is not None and self.allowed.has_key(name) ):
+            f['name'] = self.allowed[name]['name']
+        return (f)
+
+    def get_scrape(self, paramslist):
+        fs = {}
+        if paramslist.has_key('info_hash'):
+            if self.config['scrape_allowed'] not in ['specific', 'full']:
+                return (400, 'Not Authorized', {'Content-Type': 'text/plain', 'Pragma': 'no-cache'},
+                    bencode({'failure reason':
+                    'specific scrape function is not available with this tracker.'}))
+            for infohash in paramslist['info_hash']:
+                if infohash in self.downloads.keys():
+                    fs[infohash] = self.scrapedata(infohash)
+        else:
+            if self.config['scrape_allowed'] != 'full':
+                return (400, 'Not Authorized', {'Content-Type': 'text/plain', 'Pragma': 'no-cache'},
+                    bencode({'failure reason':
+                    'full scrape function is not available with this tracker.'}))
+            names = self.downloads.keys()
+            names.sort()
+            for name in names:
+                fs[name] = self.scrapedata(name)
+
+        return (200, 'OK', {'Content-Type': 'text/plain'}, bencode({'files': fs}))
+
     def get(self, connection, path, headers):
         try:
             (scheme, netloc, path, pars, query, fragment) = urlparse(path)
@@ -197,117 +324,22 @@
                 path = path.replace('+',' ')
                 query = query.replace('+',' ')
             path = unquote(path)[1:]
+            paramslist = {}
             params = {}
             for s in query.split('&'):
                 if s != '':
                     i = s.index('=')
-                    params[unquote(s[:i])] = unquote(s[i+1:])
+                    kw = unquote(s[:i])
+                    key, value = unquote(s[:i]), unquote(s[i+1:])
+                    paramslist.setdefault(key, []).append(value)
+                    params[key] = value
         except ValueError, e:
             return (400, 'Bad Request', {'Content-Type': 'text/plain'}, 
                     'you sent me garbage - ' + str(e))
         if path == '' or path == 'index.html':
-            s = StringIO()
-            s.write('<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">\n' \
-                '<html><head><title>BitTorrent download info</title>\n')
-            if self.favicon != None:
-                s.write('<link rel="shortcut icon" href="/favicon.ico" />\n')
-            s.write('</head>\n<body>\n' \
-                '<h3>BitTorrent download info</h3>\n'\
-                '<ul>\n'
-                '<li><strong>tracker version:</strong> %s</li>\n' \
-                '<li><strong>server time:</strong> %s</li>\n' \
-                '</ul>\n' % (version, isotime()))
-            names = self.downloads.keys()
-            if names:
-                names.sort()
-                tn = 0
-                tc = 0
-                td = 0
-                tt = 0  # Total transferred
-                ts = 0  # Total size
-                nf = 0  # Number of files displayed
-                uc = {}
-                ud = {}
-                if self.allowed != None and self.show_names:
-                    s.write('<table summary="files" border="1">\n' \
-                        '<tr><th>info hash</th><th>torrent name</th><th align="right">size</th><th align="right">complete</th><th align="right">downloading</th><th align="right">downloaded</th><th align="right">transferred</th></tr>\n')
-                else:
-                    s.write('<table summary="files">\n' \
-                        '<tr><th>info hash</th><th align="right">complete</th><th align="right">downloading</th><th align="right">downloaded</th></tr>\n')
-                for name in names:
-                    l = self.downloads[name]
-                    n = self.completed.get(name, 0)
-                    tn = tn + n
-                    lc = []
-                    for i in l.values():
-                        if type(i) == DictType:
-                            if i['left'] == 0:
-                                lc.append(1)
-                                uc[i['ip']] = 1
-                            else:
-                                ud[i['ip']] = 1
-                    c = len(lc)
-                    tc = tc + c
-                    d = len(l) - c
-                    td = td + d
-                    if self.allowed != None and self.show_names:
-                        if self.allowed.has_key(name):
-                            nf = nf + 1
-                            sz = self.allowed[name]['length']  # size
-                            ts = ts + sz
-                            szt = sz * n   # Transferred for this torrent
-                            tt = tt + szt
-                            if self.allow_get == 1:
-                                linkname = '<a href="/file?info_hash=' + quote(name) + '">' + self.allowed[name]['name'] + '</a>'
-                            else:
-                                linkname = self.allowed[name]['name']
-                            s.write('<tr><td><code>%s</code></td><td>%s</td><td align="right">%s</td><td align="right">%i</td><td align="right">%i</td><td align="right">%i</td><td align="right">%s</td></tr>\n' \
-                                % (b2a_hex(name), linkname, size_format(sz), c, d, n, size_format(szt)))
-                    else:
-                        s.write('<tr><td><code>%s</code></td><td align="right"><code>%i</code></td><td align="right"><code>%i</code></td><td align="right"><code>%i</code></td></tr>\n' \
-                            % (b2a_hex(name), c, d, n))
-                ttn = 0
-                for i in self.completed.values():
-                    ttn = ttn + i
-                if self.allowed != None and self.show_names:
-                    s.write('<tr><td align="right" colspan="2">%i files</td><td align="right">%s</td><td align="right">%i/%i</td><td align="right">%i/%i</td><td align="right">%i/%i</td><td align="right">%s</td></tr>\n'
-                            % (nf, size_format(ts), len(uc), tc, len(ud), td, tn, ttn, size_format(tt)))
-                else:
-                    s.write('<tr><td align="right">%i files</td><td align="right">%i/%i</td><td align="right">%i/%i</td><td align="right">%i/%i</td></tr>\n'
-                            % (nf, len(uc), tc, len(ud), td, tn, ttn))
-                s.write('</table>\n' \
-                    '<ul>\n' \
-                    '<li><em>info hash:</em> SHA1 hash of the "info" section of the metainfo (*.torrent)</li>\n' \
-                    '<li><em>complete:</em> number of connected clients with the complete file (total: unique IPs/total connections)</li>\n' \
-                    '<li><em>downloading:</em> number of connected clients still downloading (total: unique IPs/total connections)</li>\n' \
-                    '<li><em>downloaded:</em> reported complete downloads (total: current/all)</li>\n' \
-                    '<li><em>transferred:</em> torrent size * total downloaded (does not include partial transfers)</li>\n' \
-                    '</ul>\n')
-            else:
-                s.write('<p>not tracking any files yet...</p>\n')
-            s.write('</body>\n' \
-                '</html>\n')
-            return (200, 'OK', {'Content-Type': 'text/html; charset=iso-8859-1'}, s.getvalue())
+            return self.get_infopage()
         elif path == 'scrape':
-            fs = {}
-            names = []
-            if params.has_key('info_hash'):
-                if self.downloads.has_key(params['info_hash']):
-                    names = [ params['info_hash'] ]
-                # else return nothing
-            else:
-                names = self.downloads.keys()
-                names.sort()
-            for name in names:
-                l = self.downloads[name]
-                n = self.completed.get(name, 0)
-                c = len([1 for i in l.values() if type(i) == DictType and i['left'] == 0])
-                d = len(l) - c
-                fs[name] = {'complete': c, 'incomplete': d, 'downloaded': n}
-                if (self.allowed is not None) and self.allowed.has_key(name) and self.show_names:
-                    fs[name]['name'] = self.allowed[name]['name']
-            r = {'files': fs}
-            return (200, 'OK', {'Content-Type': 'text/plain'}, bencode(r))
+            return self.get_scrape(paramslist)
         elif (path == 'file') and (self.allow_get == 1) and params.has_key('info_hash') and self.allowed.has_key(params['info_hash']):
             hash = params['info_hash']
             fname = self.allowed[hash]['file']
@@ -506,9 +538,9 @@
         r = str(s) + 'B'
     elif (s < 1048576):
         r = str(int(s/1024)) + 'KiB'
-    elif (s < 1073741824l):
+    elif (s < 1073741824L):
         r = str(int(s/1048576)) + 'MiB'
-    elif (s < 1099511627776l):
+    elif (s < 1099511627776L):
         r = str(int((s/1073741824.0)*100.0)/100.0) + 'GiB'
     else:
         r = str(int((s/1099511627776.0)*100.0)/100.0) + 'TiB'
