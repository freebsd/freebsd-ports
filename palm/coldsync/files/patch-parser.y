--- src/parser.y~	Tue Feb 20 06:04:15 2001
+++ src/parser.y	Mon Dec  2 18:32:28 2002
@@ -1003,6 +1003,7 @@
 	{
 		$$ = NULL;
 	}
+	;
 
  /* XXX - Added in 1.1.10, Sat May 20 14:21:43 2000. Make the colon
   * mandatory at some point.
@@ -1028,6 +1029,7 @@
 		ANOTHER_ERROR;
 		Error(_("\tMissing ':'."));
 	}
+	;
 
 
 open_brace:	'{'
@@ -1036,6 +1038,7 @@
 		ANOTHER_ERROR;
 		Error(_("\tMissing '{'."));
 	}
+	;
 
 semicolon:	';'
 	| error
@@ -1043,6 +1046,7 @@
 		ANOTHER_ERROR;
 		Error(_("\tMissing ';'."));
 	}
+	;
 
 %%
 
