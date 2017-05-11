--- kadu-core/gui/actions/action-description.cpp.orig	2017-01-24 21:36:21 UTC
+++ kadu-core/gui/actions/action-description.cpp
@@ -103,7 +103,8 @@ void ActionDescription::registerAction(Actions *action
 
 void ActionDescription::unregisterAction(Actions *actions)
 {
-	actions->remove(this);
+	if (actions)
+		actions->remove(this);
 }
 
 void ActionDescription::actionAboutToBeDestroyed(Action *action)
