$NetBSD$

--- src/frontends/xforms/FormBase.h.orig	2003-02-01 17:48:38.000000000 -0700
+++ src/frontends/xforms/FormBase.h
@@ -188,14 +188,14 @@ FormCB<Controller, Base>::FormCB(string 
 template <class Controller, class Base>
 Controller & FormCB<Controller, Base>::controller()
 {
-	return static_cast<Controller &>(getController());
+	return static_cast<Controller &>(this->getController());
 }
 
 
 template <class Controller, class Base>
 Controller const & FormCB<Controller, Base>::controller() const
 {
-	return static_cast<Controller const &>(getController());
+	return static_cast<Controller const &>(this->getController());
 }
 
 
