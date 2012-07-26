--- mailnews/addrbook/src/nsDirPrefs.cpp~
+++ mailnews/addrbook/src/nsDirPrefs.cpp
@@ -375,7 +375,7 @@ static bool DIR_SetServerPosition(nsVoid
    DIR_Server *s=nsnull;
    
    switch (position) {
-   case DIR_POS_APPEND:
+   case (PRInt32)DIR_POS_APPEND:
    /* Do nothing if the request is to append a server that is already
      * in the list.
      */
@@ -401,7 +401,7 @@ static bool DIR_SetServerPosition(nsVoid
      wholeList->AppendElement(server);
      break;
      
-   case DIR_POS_DELETE:
+   case (PRInt32)DIR_POS_DELETE:
        /* Remove the prefs corresponding to the given server.  If the prefName
        * value is nsnull, the server has never been saved and there are no
        * prefs to remove.
