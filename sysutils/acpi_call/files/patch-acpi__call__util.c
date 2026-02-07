--- acpi_call_util.c.orig	2011-11-07 05:35:10 UTC
+++ acpi_call_util.c
@@ -102,6 +102,7 @@ int main(int argc, char * argv[])
 	if (ioctl(fd, ACPIIO_CALL, &params) == -1)
 	{
 		perror("ioctl");
+		fprintf(stderr, "(Is `acpi_call.ko' kernel module loaded?)\n");
 		return 1;
 	}
 
