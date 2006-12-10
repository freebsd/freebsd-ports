--- src/rpslcheck/rpslcheck.cc.orig	2004-07-30 12:58:15.000000000 +0200
+++ src/rpslcheck/rpslcheck.cc
@@ -129,12 +129,12 @@ void init_and_set_options (int argc, cha
    IRR::handleEnvironmentVariables(envp);
 
    if (ParseArgv(&argc, argv, argTable, ARGV_NO_LEFTOVERS) != ARGV_OK) {
-      cerr << endl;
+      std::cerr << std::endl;
       exit(1);
    }
 
    if (! (irr = IRR::newClient())) {
-      cerr << "Unknown protocol!" << endl;
+      std::cerr << "Unknown protocol!" << std::endl;
       exit(1);
    }
 
@@ -166,7 +166,7 @@ main(int argc, char **argv, char **envp)
 	  myAS = atoi(opt_my_as + 2);
 	  const AutNum *autnum = irr->getAutNum(myAS);
           if (!autnum)	{
-          	cerr << "Error: no object for AS " << myAS << endl;
+          	std::cerr << "Error: no object for AS " << myAS << std::endl;
 		exit(1);
 	  }
 	  o = new Object((Object &) *autnum);
@@ -180,10 +180,10 @@ main(int argc, char **argv, char **envp)
        }
 
           if (opt_echo && code)
-             cout << *o;
+             std::cout << *o;
 
           if (!o->has_error && code)
-          cout << "Congratulations no errors were found" << endl;
+          std::cout << "Congratulations no errors were found" << std::endl;
 
 	  delete o;
 
@@ -197,7 +197,7 @@ main(int argc, char **argv, char **envp)
       schema.printClassStats();
 
    if (opt_prompt)
-      cout << endl;
+      std::cout << std::endl;
 
    if (opt_rusage)
       clog << ru;
