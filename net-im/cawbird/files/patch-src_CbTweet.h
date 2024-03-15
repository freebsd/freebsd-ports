libcawbird.a.p/src/list/TweetListEntry.c:1215:6: error: implicit declaration of function 'cb_tweet_has_quoted_inline_media' is invalid in C99 [-Werror,-Wimplicit-function-declaration]
        if (cb_tweet_has_quoted_inline_media (tweet)) {
            ^

--- src/CbTweet.h.orig	2022-03-18 20:59:56 UTC
+++ src/CbTweet.h
@@ -110,6 +110,7 @@ gboolean         cb_tweet_has_inline_media (CbTweet   
 char **          cb_tweet_get_mentions     (CbTweet   *tweet,
                                             int       *n_mentions);
 gboolean         cb_tweet_has_inline_media (CbTweet   *tweet);
+gboolean         cb_tweet_has_quoted_inline_media (CbTweet *tweet);
 gint64           cb_tweet_get_user_id      (CbTweet   *tweet);
 const char *     cb_tweet_get_screen_name  (CbTweet   *tweet);
 const char *     cb_tweet_get_user_name    (CbTweet   *tweet);
