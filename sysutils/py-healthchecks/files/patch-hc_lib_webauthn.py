--- hc/lib/webauthn.py.orig	2025-06-11 05:51:38 UTC
+++ hc/lib/webauthn.py
@@ -14,8 +14,6 @@ from fido2.webauthn import (
     UserVerificationRequirement,
 )
 
-fido2.features.webauthn_json_mapping.enabled = True
-
 
 class CreateHelper:
     def __init__(self, rp_id: str, credentials: Iterable[bytes]):
