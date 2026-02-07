--- src/lib/libast/vmalloc/vmmaddress.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/vmalloc/vmmaddress.c
@@ -96,7 +96,7 @@ ssize_t _vmpagesize(void)
 		if ((_Vmpagesize = getpagesize()) <= 0)
 #endif
 			_Vmpagesize = VM_PAGESIZE;
-		_Vmpagesize = (*_Vmlcm)(_Vmpagesize, ALIGN);
+		_Vmpagesize = (*_Vmlcm)(_Vmpagesize, MEM_ALIGN);
 	}
 #if VMCHKMEM
 	_Vmchkmem = _vmchkmem; /* _vmchkmem() can check memory availability */
