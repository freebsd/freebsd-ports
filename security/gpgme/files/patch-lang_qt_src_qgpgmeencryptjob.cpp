Rename encrypt() so that the code builds with FreeBSD 10.2/10.3's libc++, which
has a bug that causes std::bind() to fail with the original function name:

qgpgmeencryptjob.cpp:133:9: error: no matching function for call to 'bind'
    run(std::bind(&encrypt,
        ^~~~~~~~~
/usr/include/c++/v1/functional:2184:1: note: candidate template ignored:
couldn't infer template argument '_Fp'
bind(_Fp&& __f, _BoundArgs&&... __bound_args)
^
/usr/include/c++/v1/functional:2193:1: note: candidate template ignored:
couldn't infer template argument '_Rp'
bind(_Fp&& __f, _BoundArgs&&... __bound_args)
^
1 error generated.

--- lang/qt/src/qgpgmeencryptjob.cpp.orig	2016-10-18 17:22:02 UTC
+++ lang/qt/src/qgpgmeencryptjob.cpp
@@ -65,7 +65,7 @@ void QGpgMEEncryptJob::setOutputIsBase64
     mOutputIsBase64Encoded = on;
 }
 
-static QGpgMEEncryptJob::result_type encrypt(Context *ctx, QThread *thread,
+static QGpgMEEncryptJob::result_type do_encrypt(Context *ctx, QThread *thread,
         const std::vector<Key> &recipients,
         const std::weak_ptr<QIODevice> &plainText_,
         const std::weak_ptr<QIODevice> &cipherText_,
@@ -117,7 +117,7 @@ static QGpgMEEncryptJob::result_type enc
     if (!buffer->open(QIODevice::ReadOnly)) {
         assert(!"This should never happen: QBuffer::open() failed");
     }
-    return encrypt(ctx, 0, recipients, buffer, std::shared_ptr<QIODevice>(), eflags, outputIsBsse64Encoded);
+    return do_encrypt(ctx, 0, recipients, buffer, std::shared_ptr<QIODevice>(), eflags, outputIsBsse64Encoded);
 }
 
 Error QGpgMEEncryptJob::start(const std::vector<Key> &recipients, const QByteArray &plainText, bool alwaysTrust)
@@ -130,7 +130,7 @@ Error QGpgMEEncryptJob::start(const std:
 void QGpgMEEncryptJob::start(const std::vector<Key> &recipients, const std::shared_ptr<QIODevice> &plainText,
                              const std::shared_ptr<QIODevice> &cipherText, const Context::EncryptionFlags eflags)
 {
-    run(std::bind(&encrypt,
+    run(std::bind(&do_encrypt,
                     std::placeholders::_1, std::placeholders::_2,
                     recipients,
                     std::placeholders::_3, std::placeholders::_4,
