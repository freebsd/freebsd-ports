--- internal/impl/redis/client.go.orig	1979-11-29 23:00:00 UTC
+++ internal/impl/redis/client.go
@@ -21,7 +21,7 @@ Some cloud hosted instances of Redis (such as Azure Ca
 	return []*service.ConfigField{
 		service.NewURLField("url").
 			Description("The URL of the target Redis server. Database is optional and is supplied as the URL path.").
-			Example("redis://:6397").
+			Example("redis://:6379").
 			Example("redis://localhost:6379").
 			Example("redis://foousername:foopassword@redisplace:6379").
 			Example("redis://:foopassword@redisplace:6379").
