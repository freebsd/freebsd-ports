--- include/atlas_genparse.h.orig	2016-07-28 19:42:59 UTC
+++ include/atlas_genparse.h
@@ -163,7 +163,8 @@ static int GetDoubleArr(char *str, int N, double *d)
       if (!str)
          break;
       str++;
-      assert(sscanf(str, "%le", d+i) == 1);
+      if (sscanf(str, "%le", d+i) != 1)
+         break;
       i++;
    }
    return(i);
