Submitted upstream in https://git.reviewboard.kde.org/r/120664/

commit 5ec6c0202cf44ee9790baed617c1e2f195f288d3
Author: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date:   Mon Oct 20 00:13:11 2014 +0300

    Revert "clang compat fix (from Qt)"
    
    The original Qt commit (3cba3745, "Phonon: Export ObjectDescriptionModel
    to prevent link errors with Clang") was a workaround for
    http://llvm.org/bugs/show_bug.cgi?id=8177, which was fixed more than 4
    years ago.
    
    Now that we have proper support for clang in Phonon and build it with
    -fvisibility=hidden, the workaround started causing problems, as
    ObjectDescriptionModel::staticObject and others were not being exported
    as expected. A quick test for this is building Qt's phonon capabilities
    example.
    
    This reverts commit 845e395ab3aba10dbd57207ad71fbbd6b422f107.
--- phonon/objectdescriptionmodel.h
+++ phonon/objectdescriptionmodel.h
@@ -139,11 +139,10 @@ namespace Phonon
 
 /* Required to ensure template class vtables are exported on both symbian
 and existing builds. */
-#if defined(Q_OS_SYMBIAN) && defined(Q_CC_RVCT) || defined(Q_CC_CLANG)
+#if defined(Q_OS_SYMBIAN) && defined(Q_CC_RVCT)
 // RVCT compiler (2.2.686) requires the export declaration to be on the class to export vtables
 // MWC compiler works both ways
 // GCCE compiler is unknown (it can't compile QtCore yet)
-// Clang also requires the export declaration to be on the class to export vtables
 #define PHONON_TEMPLATE_CLASS_EXPORT PHONON_EXPORT
 #define PHONON_TEMPLATE_CLASS_MEMBER_EXPORT
 #else
