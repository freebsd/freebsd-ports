--- main.cpp.orig	Fri Oct 25 13:49:34 2002
+++ main.cpp	Fri Oct 25 13:49:52 2002
@@ -38,12 +38,12 @@
 void LoadStatus(mailmsg *message)
 {
 	static char twiddle[] = "-+|+";
-	cerr << "\b\b" << twiddle[message->Index()%4] << ')';
+	std::cerr << "\b\b" << twiddle[message->Index()%4] << ')';
 }
 void QuitStatus(mailmsg *message)
 {
 	static char twiddle[] = "-+|+";
-	cerr << "\b\b" << twiddle[message->Index()%4] << ')';
+	std::cerr << "\b\b" << twiddle[message->Index()%4] << ')';
 }
 
 void CleanupMessages(void)
@@ -149,26 +149,26 @@
 		case SIGHUP:
 			if ( messages )
 				messages->Abort();
-			cout << "\rExiting because of hang-up signal!" << endl;
+			std::cout << "\rExiting because of hang-up signal!" << std::cerr;
 			break;
 		case SIGINT:
 		case SIGQUIT:
 			if ( messages )
 				messages->Abort();
-			cout << "\rExiting because of keyboard interrupt!" <<
-									endl;
+			std::cout << "\rExiting because of keyboard interrupt!" <<
+									std::cerr;
 			break;
 		case SIGSEGV:
 		case SIGBUS:
 			if ( messages )
 				messages->Abort();
-			cout << "\rExiting because of program bug!" << endl;
+			std::cout << "\rExiting because of program bug!" << std::cerr;
 			break;
 		case SIGTERM:
 			if ( messages )
 				messages->Abort();
-			cout << "\rExiting because of termination signal!" <<
-									endl;
+			std::cout << "\rExiting because of termination signal!" <<
+									std::cerr;
 			break;
 		default:
 			break;
@@ -178,17 +178,17 @@
 		char cmdbuf[BUFSIZ];
 
 		if ( messages ) {
-			cout << "Saving  messages: ( )" << flush;
+			std::cout << "Saving  messages: ( )" << std::flush;
 			messages->OnSave(QuitStatus);
 			CleanupMessages();
 			messages = NULL;
-			cout << " -- Done." <<  endl;
+			std::cout << " -- Done." <<  std::cerr;
 
 			/* Check for new mail */
 			time_t atime, mtime;
 			mailfile->get_time(&atime, &mtime);
 			if ( mtime > atime )
-				cout << "You have NEW mail!" << endl;
+				std::cout << "You have NEW mail!" << std::cerr;
 		}
 		if ( was_compressed ) {
 			/* For some reason, this crashes on some mailboxes
@@ -202,9 +202,9 @@
 
 		/* Any final mailfile cleanup */
 		if ( was_compressed ) {
-			cout << "Compressing mailfile..." << flush;
+			std::cout << "Compressing mailfile..." << std::flush;
 			(void) system(cmdbuf);
-			cout << "Done." << endl;
+			std::cout << "Done." << std::cerr;
 			/* For some reason, this crashes on some mailboxes
 				delete[] cmdbuf;
 			*/
@@ -447,12 +447,12 @@
 
 void Usage(char *prog)
 {
-	cout << 
-Version << endl << endl <<
-"Usage: " << prog << " [-s subject] recipient1 recipient2 ... " << endl <<
-"or...  " << prog << " -c" << endl <<
-"or...  " << prog << " [-r initfile] [-f mailbox]" << endl <<
-	endl;
+	std::cout << 
+Version << std::cerr << std::cerr <<
+"Usage: " << prog << " [-s subject] recipient1 recipient2 ... " << std::cerr <<
+"or...  " << prog << " -c" << std::cerr <<
+"or...  " << prog << " [-r initfile] [-f mailbox]" << std::cerr <<
+	std::cerr;
 }
 
 main(int argc, char *argv[])
@@ -511,7 +511,7 @@
 	/* Command line mailing? */
 	if ( *argv ) {
 		if ( NewMail(argv, subject) < 0 ) {
-			cerr << "Mail send failed!" << endl;
+			std::cerr << "Mail send failed!" << std::cerr;
 			quit(-1);
 		}
 		quit(0);
@@ -526,7 +526,7 @@
 			((mailpath=(char *)getenv("MAIL")) == NULL) ) {
 		if ( ((whoami=getlogin()) == NULL) &&
 					((whoami=mycuserid()) == NULL) ) {
-			cerr << "Who are you?  -- Aborting!" << endl;
+			std::cerr << "Who are you?  -- Aborting!" << std::cerr;
 			quit(-1);
 		}
 		mailpath = new char[strlen(MAILPATH)+1+strlen(whoami)+1];
@@ -546,25 +546,25 @@
 	struct stat sb;
 
 	if ( stat(mailpath, &sb) < 0 ) {
-		cout << mailpath << " is not readable" << endl;
+		std::cout << mailpath << " is not readable" << std::cerr;
 		quit(0);
 	}
 	if ( sb.st_size == 0 )  {
-		cout << "No mail." << endl;
+		std::cout << "No mail." << std::cerr;
 		quit(0);
 	}
 	if ( check_mail ) {
 		if ( sb.st_mtime < sb.st_atime )
-			cout << "You have mail." << endl;
+			std::cout << "You have mail." << std::cerr;
 		else
-			cout << "You have NEW mail." << endl;
+			std::cout << "You have NEW mail." << std::cerr;
 		quit(0);
 	}
 
 	/* Check to see if the lock file exists */
 	if ( CheckLock(mailpath) ) {
-		cout << "Lockfile (" << mailpath << ".lock) exists!" << endl;
-		cout << "Please try again later..." << endl;
+		std::cout << "Lockfile (" << mailpath << ".lock) exists!" << std::cerr;
+		std::cout << "Please try again later..." << std::cerr;
 		quit(0);
 	}
 
@@ -592,10 +592,10 @@
 
 		/* Perform decompression */
 		if ( decompress ) {
-			cout << "Uncompressing mailfile..." << flush;
+			std::cout << "Uncompressing mailfile..." << std::flush;
 			if ( system(cmdbuf) == 0 )
 				was_compressed = 1;
-			cout << "Done." << endl;
+			std::cout << "Done." << std::cerr;
 		}
 		delete[] cmdbuf;
 	}
@@ -616,11 +616,11 @@
 	char             buffer[BUFSIZ];
 
 	if ( mailfile->fail() || mailfile->eof() ) {
-		cout << "No mail in " << mailpath << endl;
+		std::cout << "No mail in " << mailpath << std::cerr;
 		quit(0);
 	}
 	if ( mailfile->readline(buffer, BUFSIZ) == 1 ) {
-		cout << "Newline at start of mailfile -- aborting!" << endl;
+		std::cout << "Newline at start of mailfile -- aborting!" << std::cerr;
 		quit(-1);
 	}
 	mailfile->seekg(0);
@@ -629,7 +629,7 @@
 	MIME_body::MIME_Ignore(GetStartVar("MIME_ignore"));
 
 	/* If we have succeeded in opening the mailfile, load mail */
-	cout << "Loading messages: ( )" << flush;
+	std::cout << "Loading messages: ( )" << std::flush;
 	messages = new mailmsg(mailfile, LoadStatus);
 	if ( ((current = messages->ByStatus("N")) == NULL) &&
 	     ((current = messages->ByStatus("O")) == NULL) ) {
@@ -637,7 +637,7 @@
 		for ( current = messages; newmsg = current->Next(); )
 			current = newmsg;
 	}
-	cout << " -- Done." <<  endl;
+	std::cout << " -- Done." <<  std::cerr;
 	sleep(1);
 	mailfile->get_time(NULL, &last_mtime);
 	mailfile->Size(&last_size);
