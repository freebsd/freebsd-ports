--- agent/ssm/service.go.orig	2016-07-06 21:51:35 UTC
+++ agent/ssm/service.go
@@ -128,6 +128,8 @@ func (svc *sdkService) UpdateInstanceInf
 		params.PlatformType = aws.String(ssm.PlatformTypeWindows)
 	case "linux":
 		params.PlatformType = aws.String(ssm.PlatformTypeLinux)
+	case "freebsd":
+		params.PlatformType = aws.String(ssm.PlatformTypeLinux)
 	default:
 		return nil, fmt.Errorf("Cannot report platform type of unrecognized OS. %v", goOS)
 	}
