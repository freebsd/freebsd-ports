commit a24ca1192172ddbf506b3484d07d731d36b17ce6
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    undefine Success to unbreak the build
    
    Current X.h (X11/X.h from xorgproto) defines Success - but that name is
    also used as a variable over here. We undef Success in the respective
    part so the define does not shadow the variable.

diff --git toolkit/xre/nsXREDirProvider.cpp toolkit/xre/nsXREDirProvider.cpp
index dcce3335e14f..b0fe274ca7e0 100644
--- toolkit/xre/nsXREDirProvider.cpp
+++ toolkit/xre/nsXREDirProvider.cpp
@@ -61,6 +61,9 @@
 #  ifdef XP_MACOSX
 #    include "MacApplicationDelegate.h"
 #  endif
+#  ifdef Success // from X.h, this really messes up nss
+#    undef Success
+#  endif
 #  include "ScopedNSSTypes.h"
 #  include "nsNSSComponent.h"
 #endif
