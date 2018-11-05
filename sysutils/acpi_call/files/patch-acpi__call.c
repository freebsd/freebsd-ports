--- acpi_call.c.orig	2011-11-07 05:35:10 UTC
+++ acpi_call.c
@@ -45,18 +45,97 @@
 
 void acpi_call_fixup_pointers(ACPI_OBJECT *p, UINT8 *orig);
 
+static void
+free_acpi_object_list(ACPI_OBJECT_LIST *list)
+{
+	for (int i = 0; i < list->Count; i++) {
+		switch (list->Pointer[i].Type) {
+		case ACPI_TYPE_STRING:
+			AcpiOsFree(list->Pointer[i].String.Pointer);
+			break;
+		case ACPI_TYPE_BUFFER:
+			AcpiOsFree(list->Pointer[i].Buffer.Pointer);
+			break;
+		default:
+			break;
+		}
+	}
+	AcpiOsFree(list);
+}
+
+static ACPI_OBJECT_LIST *
+copyin_acpi_object_list(ACPI_OBJECT_LIST *src)
+{
+	ACPI_OBJECT_LIST *dest;
+	bool failed;
+
+	if (src->Count > 7)
+		return NULL;
+
+	dest = AcpiOsAllocate(sizeof(ACPI_OBJECT_LIST) + sizeof(ACPI_OBJECT) * src->Count);
+	if (!dest)
+		return NULL;
+
+	dest->Count = src->Count;
+	dest->Pointer = (ACPI_OBJECT *)(dest + 1);
+	if (copyin(src->Pointer, dest->Pointer, sizeof(ACPI_OBJECT) * dest->Count)) {
+		AcpiOsFree(dest);
+		return NULL;
+	}
+
+	failed = false;
+
+	for (int i = 0; i < dest->Count; i++) {
+		switch (dest->Pointer[i].Type) {
+		case ACPI_TYPE_INTEGER:
+			break;
+		case ACPI_TYPE_STRING: {
+			void *v = AcpiOsAllocate(dest->Pointer[i].String.Length);
+			if (!v || copyin(dest->Pointer[i].String.Pointer, v, dest->Pointer[i].String.Length))
+				failed = true;
+			dest->Pointer[i].String.Pointer = v;
+			break;
+		}
+		case ACPI_TYPE_BUFFER: {
+			void *v = AcpiOsAllocate(dest->Pointer[i].Buffer.Length);
+			if (!v || copyin(dest->Pointer[i].Buffer.Pointer, v, dest->Pointer[i].Buffer.Length))
+				failed = true;
+			dest->Pointer[i].String.Pointer = v;
+			break;
+		}
+		default:
+			failed = true;
+			break;
+		}
+	}
+
+	if (failed) {
+		free_acpi_object_list(dest);
+		dest = NULL;
+	}
+
+	return dest;
+}
+
 static int
 acpi_call_ioctl(u_long cmd, caddr_t addr, void *arg)
 {
 	struct acpi_call_descr *params;
+	ACPI_OBJECT_LIST	*args;
 	ACPI_BUFFER	result;
+	char		path[256];
 
 	result.Length = ACPI_ALLOCATE_BUFFER;
 	result.Pointer = NULL;
 
 	if (cmd == ACPIIO_CALL) {
 		params = (struct acpi_call_descr*)addr;
-		params->retval = AcpiEvaluateObject(NULL, params->path, &params->args, &result);
+		args = copyin_acpi_object_list(&params->args);
+		if (!args)
+			return EINVAL;
+		if (copyinstr(params->path, path, sizeof(path), NULL))
+			return EINVAL;
+		params->retval = AcpiEvaluateObject(NULL, path, args, &result);
 		if (ACPI_SUCCESS(params->retval))
 		{
 			if (result.Pointer != NULL)
@@ -64,30 +143,31 @@ acpi_call_ioctl(u_long cmd, caddr_t addr, void *arg)
 				if (params->result.Pointer != NULL)
 				{	
 					params->result.Length = min(params->result.Length, result.Length);
+					if (result.Length >= sizeof(ACPI_OBJECT))
+						acpi_call_fixup_pointers((ACPI_OBJECT*)result.Pointer, params->result.Pointer);
 					copyout(result.Pointer, params->result.Pointer,
 							params->result.Length);
 					params->reslen = result.Length;
-					if (result.Length >= sizeof(ACPI_OBJECT))
-						acpi_call_fixup_pointers((ACPI_OBJECT*)(params->result.Pointer), result.Pointer);
 				}
 				AcpiOsFree(result.Pointer);
 			}
 		}
+		free_acpi_object_list(args);
 	}
 
 	return (0);
 }
 
 void
-acpi_call_fixup_pointers(ACPI_OBJECT *p, UINT8 *orig)
+acpi_call_fixup_pointers(ACPI_OBJECT *p, UINT8 *dest)
 {
 	switch (p->Type)
 	{
 	case ACPI_TYPE_STRING:
-		p->String.Pointer = (char*)((UINT8*)(p->String.Pointer) - orig + (UINT8*)p);
+		p->String.Pointer += dest - (UINT8*)p;
 		break;
 	case ACPI_TYPE_BUFFER:
-		p->Buffer.Pointer -= orig - (UINT8*)p;
+		p->Buffer.Pointer += dest - (UINT8*)p;
 		break;
 	}
 }
