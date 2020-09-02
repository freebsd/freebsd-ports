--- filter.c.orig	2019-02-22 18:41:46 UTC
+++ filter.c
@@ -61,6 +61,8 @@ static int howmany = 0;      /**< how many filters wer
 static int active = 0;       /**< indicates if those filters are applied or not */
 static int * results = NULL; /**< this keeps the results of the applied filters */
 
+static struct filter_item * filters = NULL;
+
 /**
  * \brief Add a filter to filters structure
  *
