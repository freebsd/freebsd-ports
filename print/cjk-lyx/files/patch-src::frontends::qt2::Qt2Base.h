$NetBSD$

--- ./src/frontends/qt2/Qt2Base.h.orig	2003-02-01 17:48:38.000000000 -0700
+++ ./src/frontends/qt2/Qt2Base.h
@@ -174,14 +174,14 @@ Qt2CB<Controller, Base>::Qt2CB(QString c
 template <class Controller, class Base>
 Controller & Qt2CB<Controller, Base>::controller()
 {
-	return static_cast<Controller &>(getController());
+       return static_cast<Controller &>(this->getController());
 }
 
 
 template <class Controller, class Base>
 Controller const & Qt2CB<Controller, Base>::controller() const
 {
-	return static_cast<Controller const &>(getController());
+       return static_cast<Controller const &>(this->getController());
 }
 
 
