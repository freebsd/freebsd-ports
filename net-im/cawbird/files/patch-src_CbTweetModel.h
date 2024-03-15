libcawbird.a.p/src/TweetInfoPage.c:3374:20: error: implicit declaration of function 'cb_tweet_model_index_of_retweet' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
                replied_to_idx = cb_tweet_model_index_of_retweet (_tmp3_, reply_id);
                                 ^

--- src/CbTweetModel.h.orig	2022-03-18 20:59:56 UTC
+++ src/CbTweetModel.h
@@ -56,6 +56,7 @@ int cb_tweet_model_index_of (CbTweetModel *self, gint6
 CbTweetModel *cb_tweet_model_new (void);
 
 int cb_tweet_model_index_of (CbTweetModel *self, gint64 id);
+int cb_tweet_model_index_of_retweet (CbTweetModel *self, gint64 id);
 
 gboolean cb_tweet_model_contains_id  (CbTweetModel *self,
                                       gint64        id);
