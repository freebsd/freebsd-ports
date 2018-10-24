--- molsketch/programversion.h.orig	2018-10-24 03:35:24 UTC
+++ molsketch/programversion.h
@@ -30,8 +30,8 @@ public:
   ProgramVersion(const QString& version = "");
   ProgramVersion(int major, int minor = 0, int patch = 0, int build = 0);
   ~ProgramVersion();
-  unsigned int major() const;
-  unsigned int minor() const;
+  unsigned int majorx() const;
+  unsigned int minorx() const;
   unsigned int patch() const;
   unsigned int build() const;
   bool operator ==(const ProgramVersion& other) const;
