--- src/libopensc/card-openpgp.c.orig	2023-03-13 11:54:48 UTC
+++ src/libopensc/card-openpgp.c
@@ -129,7 +129,7 @@ static pgp_ec_curves_t	ec_curves_gnuk[] = {
 
 static int		pgp_get_card_features(sc_card_t *card);
 static int		pgp_finish(sc_card_t *card);
-static void		pgp_iterate_blobs(pgp_blob_t *, void (*func)());
+static void		pgp_iterate_blobs(pgp_blob_t *, void (*func)(pgp_blob_t *));
 
 static int		pgp_get_blob(sc_card_t *card, pgp_blob_t *blob,
 				 unsigned int id, pgp_blob_t **ret);
@@ -1150,7 +1150,7 @@ pgp_free_blob(pgp_blob_t *blob)
  * Internal: iterate through the blob tree, calling a function for each blob.
  */
 static void
-pgp_iterate_blobs(pgp_blob_t *blob, void (*func)())
+pgp_iterate_blobs(pgp_blob_t *blob, void (*func)(pgp_blob_t *))
 {
 	if (blob) {
 		pgp_blob_t *child = blob->files;
