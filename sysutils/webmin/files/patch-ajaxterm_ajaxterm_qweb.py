
$FreeBSD$

--- ajaxterm/ajaxterm/qweb.py.orig
+++ ajaxterm/ajaxterm/qweb.py
@@ -128,12 +128,12 @@
         r=None
         try:
             r=eval(expr,self.data)
-        except NameError,e:
+        except NameError as e:
             pass
-        except AttributeError,e:
+        except AttributeError as e:
             pass
-        except Exception,e:
-            print "qweb: expression error '%s' "%expr,e
+        except Exception as e:
+            print ("qweb: expression error '%s' "%expr,e)
         if self.data.has_key("__builtins__"):
             del self.data["__builtins__"]
         return r
@@ -846,7 +846,7 @@
         fname=os.path.join(self.session_path,'qweb_sess_%s'%self.session_id)
         try:
             oldtime=os.path.getmtime(fname)
-        except OSError,IOError:
+        except (OSError,IOError):
             oldtime=0
         dump=pickle.dumps(self.copy())
         if (dump != self.session_orig) or (time.time() > oldtime+self.session_maxlifetime/4):
@@ -863,7 +863,7 @@
             for i in [os.path.join(self.session_path,i) for i in os.listdir(self.session_path) if i.startswith('qweb_sess_')]:
                 if (t > os.path.getmtime(i)+self.session_maxlifetime):
                     os.unlink(i)
-        except OSError,IOError:
+        except (OSError,IOError):
             pass
 class QWebSessionMem(QWebSession):
     def session_load(self,sid):
@@ -1237,8 +1237,8 @@
     def write(self,data):
         try:
             self.wfile.write(data)
-        except (socket.error, socket.timeout),e:
-            print e
+        except (socket.error, socket.timeout) as e:
+            print (e)
     def bufferon(self):
         if not getattr(self,'wfile_buf',0):
             self.wfile_buf=1
@@ -1323,7 +1323,7 @@
         sock = socket.fromfd(0, socket.AF_INET, socket.SOCK_STREAM)
         try:
             sock.getpeername()
-        except socket.error, e:
+        except socket.error as e:
             if e[0] == errno.ENOTSOCK:
                 fcgi=0
     if fcgi or os.environ.has_key('REQUEST_METHOD'):
@@ -1331,13 +1331,13 @@
         fcgi.WSGIServer(wsgiapp,multithreaded=False).run()
     else:
         if log:
-            print 'Serving on %s:%d'%(ip,port)
+            print ('Serving on %s:%d'%(ip,port))
         s=QWebWSGIServer(wsgiapp,ip=ip,port=port,threaded=threaded,log=log)
         if callback_ready:
             callback_ready()
         try:
             s.serve_forever()
-        except KeyboardInterrupt,e:
+        except KeyboardInterrupt as e:
             sys.excepthook(*sys.exc_info())
 
 #----------------------------------------------------------
@@ -1351,6 +1351,6 @@
         body+='\n\n%s\n%s\n\n%s'%(n,'-'*len(n),d)
     return body
 
-    print qweb_doc()
+    print (qweb_doc())
 
 #
