The trustlist feature, which only worked for a short period in 2003, was
removed in GpgME 2.0.0.

--- src/gpacontext.c.orig	2022-11-14 07:04:19 UTC
+++ src/gpacontext.c
@@ -38,8 +38,6 @@ static void gpa_context_next_key (GpaContext *context,
 static void gpa_context_start (GpaContext *context);
 static void gpa_context_done (GpaContext *context, gpg_error_t err);
 static void gpa_context_next_key (GpaContext *context, gpgme_key_t key);
-static void gpa_context_next_trust_item (GpaContext *context,
-                                         gpgme_trust_item_t item);
 static void gpa_context_progress (GpaContext *context, int current, int total);
 
 /* The GPGME I/O callbacks */
@@ -65,7 +63,6 @@ enum
   START,
   DONE,
   NEXT_KEY,
-  NEXT_TRUST_ITEM,
   PROGRESS,
   LAST_SIGNAL
 };
@@ -113,7 +110,6 @@ gpa_context_class_init (GpaContextClass *klass)
   klass->start = gpa_context_start;
   klass->done = gpa_context_done;
   klass->next_key = gpa_context_next_key;
-  klass->next_trust_item = gpa_context_next_trust_item;
   klass->progress = gpa_context_progress;
 
   /* Signals */
@@ -143,15 +139,6 @@ gpa_context_class_init (GpaContextClass *klass)
                         g_cclosure_marshal_VOID__POINTER,
                         G_TYPE_NONE, 1,
 			G_TYPE_POINTER);
-  signals[NEXT_TRUST_ITEM] =
-          g_signal_new ("next_trust_item",
-                        G_TYPE_FROM_CLASS (object_class),
-                        G_SIGNAL_RUN_FIRST,
-                        G_STRUCT_OFFSET (GpaContextClass, next_trust_item),
-                        NULL, NULL,
-                        g_cclosure_marshal_VOID__POINTER,
-                        G_TYPE_NONE, 1,
-			G_TYPE_POINTER);
   signals[PROGRESS] =
           g_signal_new ("progress",
                         G_TYPE_FROM_CLASS (object_class),
@@ -496,10 +483,6 @@ gpa_context_event_cb (void *data, gpgme_event_io_t typ
     case GPGME_EVENT_NEXT_KEY:
       g_signal_emit (context, signals[NEXT_KEY], 0, type_data);
       break;
-    case GPGME_EVENT_NEXT_TRUSTITEM:
-      g_signal_emit (context, signals[NEXT_TRUST_ITEM], 0,
-                     type_data);
-      break;
     default:
       /* Ignore unsupported event types */
       break;
@@ -527,12 +510,6 @@ gpa_context_next_key (GpaContext *context, gpgme_key_t
 
 static void
 gpa_context_next_key (GpaContext *context, gpgme_key_t key)
-{
-  /* Do nothing yet */
-}
-
-static void
-gpa_context_next_trust_item (GpaContext *context, gpgme_trust_item_t item)
 {
   /* Do nothing yet */
 }
