Fix API schema error caused by LegacyActivateUserKeyViewSet

Obtained from:

https://github.com/Onemind-Services-LLC/netbox-secrets/pull/241

--- netbox_secrets/api/views.py.orig	2026-03-18 08:56:30 UTC
+++ netbox_secrets/api/views.py
@@ -725,6 +725,46 @@ class LegacyActivateUserKeyViewSet(ViewSet):
     permission_classes = [IsAuthenticated]
     serializer_class = serializers.ActivateUserKeySerializer
 
+    @extend_schema(
+        request=serializers.ActivateUserKeySerializer,
+        responses={
+            200: OpenApiResponse(
+                response=OpenApiTypes.STR,
+                description="Plain-text success message.",
+                examples=[
+                    OpenApiExample(
+                        "Success",
+                        value="Successfully activated 2 user keys.",
+                    )
+                ],
+            ),
+            400: OpenApiResponse(
+                description="Bad request or validation error.",
+                response=OpenApiTypes.OBJECT,
+                examples=[
+                    OpenApiExample(
+                        "Validation error",
+                        value={"user_key_ids": ["This field is required."]},
+                    ),
+                    OpenApiExample(
+                        "Legacy error message",
+                        value={"detail": ERR_NO_KEYS_PROVIDED},
+                    ),
+                ],
+            ),
+            403: OpenApiResponse(
+                response=OpenApiTypes.STR,
+                description="Permission denied.",
+                examples=[
+                    OpenApiExample(
+                        "Permission denied",
+                        value="You do not have permission to active User Keys.",
+                    )
+                ],
+            ),
+        },
+        deprecated=True,
+    )
     def create(self, request):
         """
         Activate one or more user keys using the caller's private key.
