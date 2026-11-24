--- src/support/debug.cpp	2026-09-07 18:54:34 UTC
+++ src/support/debug.cpp
@@ -23,7 +23,16 @@
 #include <iostream>
 #include <iomanip>
 
+#ifndef _WIN32
+#include <cerrno>
+#include <clocale>
+#include <cstring>
+#include <iconv.h>
+#include <langinfo.h>
+#include <strings.h>
+#endif
 
+
 using namespace std;
 using namespace lyx::support;
 
@@ -302,6 +311,109 @@ LyXErr lyxerr;
 
 // The global instance
 LyXErr lyxerr;
+
+
+#ifndef _WIN32
+namespace {
+
+/// A stream buffer converting UTF-8 to another encoding on its way to
+/// the real stream buffer.
+class TranscodingStreamBuf : public streambuf
+{
+public:
+	TranscodingStreamBuf(streambuf * sink, iconv_t cd)
+		: sink_(sink), cd_(cd)
+	{
+		setp(buf_, buf_ + sizeof(buf_));
+	}
+
+protected:
+	int_type overflow(int_type c) override
+	{
+		if (!convert())
+			return traits_type::eof();
+		if (!traits_type::eq_int_type(c, traits_type::eof()))
+			return sputc(traits_type::to_char_type(c));
+		return traits_type::not_eof(c);
+	}
+
+	int sync() override
+	{
+		return convert() ? sink_->pubsync() : -1;
+	}
+
+private:
+	/// Convert the buffered text and pass it on to \c sink_.
+	/// An incomplete UTF-8 sequence at the end is kept for later.
+	bool convert();
+
+	streambuf * const sink_;
+	iconv_t const cd_;
+	char buf_[1024];
+};
+
+
+bool TranscodingStreamBuf::convert()
+{
+	char ICONV_CONST * inbuf = pbase();
+	size_t inleft = pptr() - pbase();
+	while (inleft > 0) {
+		char out[4096];
+		char * outbuf = out;
+		size_t outleft = sizeof(out);
+		size_t const res =
+			iconv(cd_, &inbuf, &inleft, &outbuf, &outleft);
+		int const err = errno;
+		streamsize const len = outbuf - out;
+		if (sink_->sputn(out, len) != len)
+			return false;
+		if (res != size_t(-1) || err == E2BIG)
+			continue;
+		if (err == EINVAL)
+			// incomplete sequence at the end of the buffer
+			break;
+		// Invalid input, or a character the target encoding lacks:
+		// print a question mark and skip the whole UTF-8 sequence.
+		if (traits_type::eq_int_type(sink_->sputc('?'),
+		                             traits_type::eof()))
+			return false;
+		do {
+			++inbuf;
+			--inleft;
+		} while (inleft > 0 && (*inbuf & 0xC0) == 0x80);
+	}
+	memmove(buf_, inbuf, inleft);
+	setp(buf_, buf_ + sizeof(buf_));
+	pbump(int(inleft));
+	return true;
+}
+
+} // namespace
+#endif
+
+
+void transcodeToLocale(ostream & os)
+{
+#ifndef _WIN32
+	char const * const locale = setlocale(LC_CTYPE, nullptr);
+	if (!locale || strcmp(locale, "C") == 0 || strcmp(locale, "POSIX") == 0)
+		return;
+	char const * const codeset = nl_langinfo(CODESET);
+	if (!codeset || !*codeset || strcasecmp(codeset, "UTF-8") == 0
+	    || strcasecmp(codeset, "UTF8") == 0)
+		return;
+	iconv_t cd = iconv_open((string(codeset) + "//TRANSLIT").c_str(), "UTF-8");
+	if (cd == iconv_t(-1))
+		cd = iconv_open(codeset, "UTF-8");
+	if (cd == iconv_t(-1))
+		return;
+	os.flush();
+	// Never deleted: the stream may still be used during exit.
+	os.rdbuf(new TranscodingStreamBuf(os.rdbuf(), cd));
+#else
+	(void)os;
+#endif
+}
 
 
 
