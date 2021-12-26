PORTNAME=	wget2
DISTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	GNU/wget

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	File and recursive website downloader

LICENSE=	GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LESSER

USES=		autoreconf charsetfix cpe iconv libtool:build localbase pkgconfig tar:lz
CPE_VENDOR=	gnu
CPE_PRODUCT=	wget
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-lzip  # not in ports yet
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	IDN MANPAGES DOXYGEN NLS PSL NGHTTP2 BROTLI ZSTD GPGME TEST HSTS
OPTIONS_RADIO=	SSL PCRE
OPTIONS_RADIO_SSL=GNUTLS OPENSSL # WOLFSSL
OPTIONS_RADIO_PCRE=PCRE1 PCRE2
OPTIONS_DEFAULT=IDN MANPAGES OPENSSL NLS PSL NGHTTP2 BROTLI ZSTD GPGME TEST HSTS
OPTIONS_SUB=	yes

IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2
IDN_CONFIGURE_WITH=	libidn2

MANPAGES_BUILD_DEPENDS=	pandoc:textproc/hs-pandoc

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

NGHTTP2_DESC=		Support HTTP/2.0 through libnghttp2
NGHTTP2_CONFIGURE_WITH=	libnghttp2
NGHTTP2_LIB_DEPENDS=	libnghttp2.so:www/libnghttp2

BROTLI_CONFIGURE_WITH=	brotlidec
BROTLI_LIB_DEPENDS=	libbrotlidec.so:archivers/brotli

ZSTD_CONFIGURE_WITH=	zstd
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

GPGME_DESC=		Support signature verification with gpgme
GPGME_CONFIGURE_WITH=	gpgme
GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme

TEST_TEST_TARGET=	check
TEST_CONFIGURE_WITH=	libmicrohttpd
TEST_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
TEST_TEST_DEPENDS=	p5-HTTP-Daemon>=0:www/p5-HTTP-Daemon \
			p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USES+=		ssl
CONFIGURE_ARGS+=--with-ssl=openssl --with-openssl
CPPFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.elif ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:security/gnutls
CONFIGURE_ARGS+=--with-ssl=gnutls
.elif ${PORT_OPTIONS:MWOLFSSL}
BROKEN=		does not build: use of undeclared identifier WOLFSSL_ALPN_CONTINUE_ON_MISMATCH
LIB_DEPENDS+=	libwolfssl.so:security/wolfssl
CONFIGURE_ARGS+=--with-ssl=wolfssl
.else
CONFIGURE_ARGS+=--with-ssl=none
.endif

post-patch-MANPAGES-off:
	@${REINPLACE_CMD} -e '/AC_CHECK_PROGS/ s|pandoc|&-not-found|' ${WRKSRC}/configure.ac

post-patch-DOXYGEN-off:
	@${REINPLACE_CMD} -e '/AC_CHECK_PROGS/ s|doxygen|&-not-found|' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
