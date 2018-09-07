--- kopete/kconf_update/kopete-nameTracking.cpp.orig	2018-09-07 10:14:33 UTC
+++ kopete/kconf_update/kopete-nameTracking.cpp
@@ -59,7 +59,7 @@ int main()
 					// check if it's a contact by checking for "protocol" substring in the tag,
 					// and the presence of a contactId child element.
 					QString pluginId = elem.attribute( QLatin1String( "plugin-id" ) );
-					bool isProtocol = ( pluginId.contains( "protocol", false ) > 0 ); // case-insensitive search
+					bool isProtocol = bool( pluginId.contains( "protocol", false ) ); // case-insensitive search
 					bool hasContactId = false;
 					QDomNode field = elem.firstChild();
 					while( !field.isNull() )
