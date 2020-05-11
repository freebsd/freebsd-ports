--- man/pod2man.mk.orig	2020-05-09 06:49:29 UTC
+++ man/pod2man.mk
@@ -41,7 +41,7 @@ DATE_FMT = %Y-%m-%d
 ifdef SOURCE_DATE_EPOCH
 PODCENTER	?= $(shell date -u -d "@$(SOURCE_DATE_EPOCH)" "+$(DATE_FMT)" 2>/dev/null || date -u -r "$(SOURCE_DATE_EPOCH)" "+$(DATE_FMT)" 2>/dev/null || date -u "+$(DATE_FMT)")
 else
-PODCENTER	?= $(date "$(DATE_FMT)")
+PODCENTER	?= $(shell date "+$(DATE_FMT)")
 endif
 
 # Directories
