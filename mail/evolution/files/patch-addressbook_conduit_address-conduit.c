--- addressbook/conduit/address-conduit.c.orig	Tue Aug 26 19:45:53 2003
+++ addressbook/conduit/address-conduit.c	Fri Aug  6 12:19:52 2004
@@ -610,6 +610,7 @@
 	case E_CARD_SIMPLE_FIELD_EMAIL_2:
 		return E_CARD_SIMPLE_FIELD_EMAIL_3;
 	default:
+		break;
 	}
 
 	return E_CARD_SIMPLE_FIELD_LAST;
@@ -625,6 +626,7 @@
 	case E_CARD_SIMPLE_FIELD_PHONE_HOME:
 		return E_CARD_SIMPLE_FIELD_PHONE_HOME_2;
 	default:
+		break;
 	}
 
 	return E_CARD_SIMPLE_FIELD_LAST;
@@ -640,6 +642,7 @@
 	case E_CARD_SIMPLE_FIELD_PHONE_BUSINESS:
 		return E_CARD_SIMPLE_FIELD_PHONE_BUSINESS_2;
 	default:
+		break;
 	}
 
 	return E_CARD_SIMPLE_FIELD_LAST;
@@ -657,6 +660,7 @@
 	case E_CARD_SIMPLE_FIELD_PHONE_HOME_FAX:
 		return E_CARD_SIMPLE_FIELD_PHONE_OTHER_FAX;
 	default:
+		break;
 	}
 
 	return E_CARD_SIMPLE_FIELD_LAST;
