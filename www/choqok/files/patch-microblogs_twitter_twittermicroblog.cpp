--- microblogs/twitter/twittermicroblog.cpp.orig	2020-02-05 11:49:13 UTC
+++ microblogs/twitter/twittermicroblog.cpp
@@ -473,7 +473,11 @@ Choqok::Post *TwitterMicroBlog::readPost(Choqok::Accou
     }
 
     //postId is changed, regenerate link url
-    post->link = postUrl(account, post->author.userName, post->postId);
+    if (!post->repeatedPostId.isEmpty()) {
+        post->link = postUrl(account, post->author.userName, post->repeatedPostId);
+    } else {
+        post->link = postUrl(account, post->author.userName, post->postId);
+    }
 
     QVariantMap userMap = var[QLatin1String("user")].toMap();
     post->author.userId = userMap[QLatin1String("id_str")].toString();
@@ -491,7 +495,6 @@ void TwitterMicroBlog::fetchPost(Choqok::Account *theA
     QUrl url = account->apiUrl();
     url.setPath(url.path() + QStringLiteral("/statuses/show/%1.json").arg(post->postId));
 
-    QUrl tmpUrl(url);
     QUrlQuery urlQuery;
     urlQuery.addQueryItem(QLatin1String("tweet_mode"), QLatin1String("extended"));
     url.setQuery(urlQuery);
@@ -506,7 +509,7 @@ void TwitterMicroBlog::fetchPost(Choqok::Account *theA
     }
     job->addMetaData(QStringLiteral("customHTTPHeader"),
                      QStringLiteral("Authorization: ") +
-                     QLatin1String(authorizationHeader(account, tmpUrl, QNetworkAccessManager::GetOperation)));
+                     QLatin1String(authorizationHeader(account, url, QNetworkAccessManager::GetOperation)));
     mFetchPostMap[ job ] = post;
     mJobsAccount[ job ] = theAccount;
     connect(job, &KIO::StoredTransferJob::result, this, &TwitterMicroBlog::slotFetchPost);
