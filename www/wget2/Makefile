PORTNAME=	wget2
DISTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	GNU/wget

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	File and recursive website downloader
WWW=		https://gitlab.com/gnuwget/wget2

LICENSE=	GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LESSER

USES=		autoreconf charsetfix cpe gmake iconv libtool:build localbase pkgconfig tar:lz
CPE_VENDOR=	gnu
CPE_PRODUCT=	wget
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=--without-libidn  # only libidn2 is used
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DANE IDN MANPAGES DOXYGEN NLS PSL HTTP2 GPGME TEST HSTS PROXY
OPTIONS_GROUP=	COMPRESSION
OPTIONS_GROUP_COMPRESSION=	BROTLI ZSTD LZMA BZIP2
OPTIONS_SINGLE=	SSL
OPTIONS_SINGLE_SSL=GNUTLS OPENSSL NOSSL # WOLFSSL
OPTIONS_RADIO=	PCRE
OPTIONS_RADIO_PCRE=PCRE1 PCRE2
OPTIONS_DEFAULT=IDN MANPAGES OPENSSL NLS PSL HTTP2 BROTLI ZSTD GPGME TEST HSTS LZMA BZIP2
OPTIONS_SUB=	yes

# requires gnutls built with DANE option enabled
DANE_DESC=		Support for DANE certificate checking (requires gnutls built with DANE option)
DANE_CONFIGURE_WITH=	libdane
DANE_LIB_DEPENDS=	libgnutls-dane.so:security/gnutls

IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2
IDN_CONFIGURE_WITH=	libidn2

MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc \
			gsed:textproc/gsed

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools
NLS_CONFIGURE_ENABLE=	nls

PCRE_DESC=		Support Perl regular expressions in addition to POSIX

PCRE1_DESC=		Support PCRE style regular expressions
PCRE1_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE1_CONFIGURE_WITH=	libpcre

PCRE2_DESC=		Support PCRE2 style regular expressions
PCRE2_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE2_CONFIGURE_WITH=	libpcre2

PSL_CONFIGURE_WITH=	libpsl
PSL_LIB_DEPENDS=	libpsl.so:dns/libpsl

HSTS_DESC=		Support HSTS preload lists
HSTS_CONFIGURE_WITH=	libhsts
HSTS_LIB_DEPENDS=	libhsts.so:www/libhsts

HTTP2_CONFIGURE_WITH=	libnghttp2
HTTP2_LIB_DEPENDS=	libnghttp2.so:www/libnghttp2

GPGME_DESC=		Support signature verification with gpgme
GPGME_CONFIGURE_WITH=	gpgme
GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme

TEST_TEST_TARGET=	check
TEST_CONFIGURE_WITH=	libmicrohttpd
TEST_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
TEST_TEST_DEPENDS=	p5-HTTP-Daemon>=0:www/p5-HTTP-Daemon \
			p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL

OPENSSL_CONFIGURE_ON=	--with-ssl=openssl --with-openssl
OPENSSL_USES=		ssl
OPENSSL_CPPFLAGS=	-I${OPENSSLINC}
OPENSSL_LDFLAGS=	-L${OPENSSLLIB}

GNUTLS_CONFIGURE_ON=	--with-ssl=gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

WOLFSSL_CONFIGURE_ON=	--with-ssl=wolfssl
WOLFSSL_LIB_DEPENDS=	libwolfssl.so:security/wolfssl
WOLFSSL_BROKEN=		does not build: use of undeclared identifier WOLFSSL_ALPN_CONTINUE_ON_MISMATCH

NOSSL_DESC=		Disable SSL support
NOSSL_LIB_DEPENDS=	libnettle.so:security/nettle  # still required libnettle for hashing and checksumming
NOSSL_CONFIGURE_ON=	--with-ssl=none

COMPRESSION_DESC=	Compression algorithms support

BROTLI_CONFIGURE_WITH=	brotlidec
BROTLI_LIB_DEPENDS=	libbrotlidec.so:archivers/brotli

ZSTD_CONFIGURE_WITH=	zstd
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

LZMA_CONFIGURE_WITH=	lzma

BZIP2_CONFIGURE_WITH=	bzip2

PROXY_DESC=		Systemwide proxy configuration through libproxy
PROXY_CONFIGURE_ENABLE=	libproxy
PROXY_LIB_DEPENDS=      libproxy.so:net/libproxy

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch-MANPAGES-off:
	@${REINPLACE_CMD} -e '/AC_CHECK_PROGS/ s|pandoc|&-not-found|' ${WRKSRC}/configure.ac

post-patch-DOXYGEN-off:
	@${REINPLACE_CMD} -e '/AC_CHECK_PROGS/ s|doxygen|&-not-found|' ${WRKSRC}/configure.ac

.include <bsd.port.post.mk>
