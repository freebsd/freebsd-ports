--- SoObjects/SOGo/BSONCodec.m.orig	2015-09-16 18:41:31 UTC
+++ SoObjects/SOGo/BSONCodec.m
@@ -310,7 +310,7 @@ static NSDictionary *BSONTypes()
 
 		case 'q': return 0x12;
 		default:
-			[NSException raise: NSInvalidArgumentException format: @"%@::%s - invalid encoding type '%c'", [self class], _cmd, encoding];
+			[NSException raise: NSInvalidArgumentException format: @"%@::%s - invalid encoding type '%c'", [self class], (char *)NSStringFromSelector(_cmd), encoding];
 	}
 	return 0;
 }
@@ -385,7 +385,7 @@ static NSDictionary *BSONTypes()
 	}
 
 
-	[NSException raise: NSInvalidArgumentException format: @"%@::%s - invalid encoding type '%c'", [self class], _cmd, encoding];
+	[NSException raise: NSInvalidArgumentException format: @"%@::%s - invalid encoding type '%c'", [self class], (char *)NSStringFromSelector(_cmd), encoding];
 	return nil;
 }
 
