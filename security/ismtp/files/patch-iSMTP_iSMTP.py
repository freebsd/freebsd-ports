--- iSMTP/iSMTP.py.orig	2023-03-18 07:13:19 UTC
+++ iSMTP/iSMTP.py
@@ -29,13 +29,13 @@ class colors:
 	green = "\033[1;32m"
 
 start_time = time.time()
-banner = "\n " + "-" * 69 + "\n " + colors.white + " iSMTP v1.6 - SMTP Server Tester, Alton Johnson (alton.jx@gmail.com)\n " + colors.normal + "-" * 69 + "\n "
+banner = "\n " + "-" * 69 + "\n " + colors.white + " SMTP Server Tester \n"  + colors.normal + "-" * 69 + "\n "
 split_service = "\n " + colors.white + "-" * 10 + " starting next test " + "-" * 10 + colors.normal + "\n"
 split_target = "\n " + colors.white + "=" * 23 + " starting next target " + "=" * 23 + colors.normal + "\n"
 
 def help():
 	print(banner)
-	print(" Usage: ./iSMTP.py <OPTIONS>\n")
+	print(" Usage: ismtp  <OPTIONS>\n")
 	print(colors.red + " Required:\n" + colors.normal)
 	print("\t-f <import file>\tImports a list of SMTP servers for testing.\n\t\t\t\t(Cannot use with '-h'.)")
 	print("\t-h <host>\t\tThe target IP and port (IP:port).\n\t\t\t\t(Cannot use with '-f'.)")
