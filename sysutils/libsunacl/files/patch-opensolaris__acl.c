--- opensolaris_acl.c	2018-01-12 08:00:20 UTC
+++ opensolaris_acl.c
@@ -154,15 +154,19 @@ acl_from_aces(struct acl *aclp, const ace_t *aces, int
 
 		switch (ace->a_type) {
 		case ACE_ACCESS_ALLOWED_ACE_TYPE:
+		case ACE_ACCESS_ALLOWED_OBJECT_ACE_TYPE:
 			entry->ae_entry_type = ACL_ENTRY_TYPE_ALLOW;
 			break;
 		case ACE_ACCESS_DENIED_ACE_TYPE:
+		case ACE_ACCESS_DENIED_OBJECT_ACE_TYPE:
 			entry->ae_entry_type = ACL_ENTRY_TYPE_DENY;
 			break;
 		case ACE_SYSTEM_AUDIT_ACE_TYPE:
+		case ACE_SYSTEM_AUDIT_OBJECT_ACE_TYPE:
 			entry->ae_entry_type = ACL_ENTRY_TYPE_AUDIT;
 			break;
 		case ACE_SYSTEM_ALARM_ACE_TYPE:
+		case ACE_SYSTEM_ALARM_OBJECT_ACE_TYPE:
 			entry->ae_entry_type = ACL_ENTRY_TYPE_ALARM;
 			break;
 		default:
