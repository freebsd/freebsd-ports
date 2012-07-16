
$FreeBSD$

--- ajaxterm/ajaxterm/ajaxterm.py.orig
+++ ajaxterm/ajaxterm/ajaxterm.py
@@ -394,7 +394,7 @@
 			if self.cmd:
 				cmd=['/bin/sh','-c',self.cmd]
 			elif os.getuid()==0:
-				cmd=['/bin/login']
+				cmd=['/usr/bin/login']
 			else:
 				sys.stdout.write("Login: ")
 				login=sys.stdin.readline().strip()
@@ -549,16 +549,16 @@
 				file(o.pidfile,'w+').write(str(pid)+'\n')
 			except:
 				pass
-			print 'AjaxTerm at http://localhost:%s/ pid: %d' % (o.port,pid)
+			print ('AjaxTerm at http://localhost:%s/ pid: %d' % (o.port,pid))
 			sys.exit(0)
 	else:
-		print 'AjaxTerm at http://localhost:%s/' % o.port
+		print ('AjaxTerm at http://localhost:%s/' % o.port)
 	at=AjaxTerm(o.cmd,o.index_file)
 #	f=lambda:os.system('firefox http://localhost:%s/&'%o.port)
 #	qweb.qweb_wsgi_autorun(at,ip='localhost',port=int(o.port),threaded=0,log=o.log,callback_ready=None)
 	try:
 		qweb.QWebWSGIServer(at,ip='localhost',port=int(o.port),threaded=0,log=o.log).serve_forever()
-	except KeyboardInterrupt,e:
+	except KeyboardInterrupt as e:
 		sys.excepthook(*sys.exc_info())
 	at.multi.die()
 
