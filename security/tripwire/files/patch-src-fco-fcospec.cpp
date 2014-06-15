--- src/fco/fcospec.cpp.orig	2011-11-21 17:06:56.000000000 +0100
+++ src/fco/fcospec.cpp	2014-06-15 01:50:46.000000000 +0200
@@ -51,6 +51,7 @@
 class cDefaultSpecMask : public iFCOSpecMask
 {
 public:
+	cDefaultSpecMask() {}
 	virtual const TSTRING& GetName() const;
 	virtual bool Accept(const iFCO* pFCO) const;
 private:
