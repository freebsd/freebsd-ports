--- autoconf/scripts/makemake.sh.orig	Wed Jun  1 00:14:20 2005
+++ autoconf/scripts/makemake.sh	Wed Jun  1 00:14:34 2005
@@ -86,7 +86,7 @@
   done
   [ -n "$deps" ] || continue
   echo "$i.o: $deps" >> $outlink
-  echo '	$(LD) $(LDFLAGS) -o $@' "$deps" >> $outlink
+  echo '	$(LD) -r $(LDFLAGS) -o $@' "$deps" >> $outlink
   echo >> $outlink
 done
 
