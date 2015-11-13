--- src/twister.cpp.orig	2015-10-19 01:02:01 UTC
+++ src/twister.cpp
@@ -1624,7 +1624,7 @@ bool usernameExists(std::string const &u
 
 bool createSignedUserpost(entry &v, std::string const &username, int k,
                           int flag, std::string const &msg,
-                          entry const *ent, entry const *sig,
+                          entry const *ent, entry const *sig_rtfav,
                           std::string const &reply_n = "", int reply_k = 0)
 {
     entry &userpost = v["userpost"];
@@ -1657,12 +1657,12 @@ bool createSignedUserpost(entry &v, std:
         }
         //userpost["t"] = "rt";
         userpost["rt"] = *ent;
-        userpost["sig_rt"] = *sig;
+        userpost["sig_rt"] = *sig_rtfav;
         break;
     }
     case USERPOST_FLAG_FAV:
         userpost["fav"] = *ent;
-        userpost["sig_fav"] = *sig;
+        userpost["sig_fav"] = *sig_rtfav;
         break;
     case USERPOST_FLAG_DM:
         //userpost["t"] = "dm";
