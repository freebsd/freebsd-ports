--- src/racoon/session.c.orig	Tue Dec 13 09:53:34 2005
+++ src/racoon/session.c	Tue Dec 13 09:53:38 2005
@@ -320,7 +320,7 @@ signal_handler(sig)
 	int sig;
 {
 	switch (sig) {
-#if 0
+#if 1
 	/*
 	 * Is this code section actually usefull? On some systems, the
 	 * wait() called during a signal handler may lead to race 
