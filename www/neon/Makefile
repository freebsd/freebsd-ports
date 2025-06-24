PORTNAME=	neon
DISTVERSION=	0.34.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://notroj.github.io/neon/

MAINTAINER=	lev@FreeBSD.org
COMMENT=	HTTP and WebDAV client library for Unix systems
WWW=		https://notroj.github.io/neon/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/src/COPYING.LIB

USES=		cpe libtool localbase:ldflags pathfix pkgconfig
CPE_VENDOR=	webdav
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	have_ld_version_script=yes
LDFLAGS=	-Wl,--undefined-version
CONFIGURE_ARGS=	--enable-shared --disable-static
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

OPTIONS_DEFINE=		DOCS GSSAPI MANPAGES NLS PROXY
OPTIONS_DEFAULT=	EXPAT GSSAPI MANPAGES OPENSSL

OPTIONS_RADIO=		SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL
OPTIONS_SINGLE=		XML
OPTIONS_SINGLE_XML=	EXPAT LIBXML2

LIBXML2_DESC=		libxml2 XML parser support
PROXY_DESC=		libproxy support
XML_DESC=		XML parser library

EXPAT_LIB_DEPENDS=	libexpat.so:textproc/expat2
EXPAT_CONFIGURE_WITH=	expat

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_ON=	--with-ssl=gnutls

GSSAPI_CONFIGURE_WITH=	gssapi

LIBXML2_CONFIGURE_WITH=	libxml2
LIBXML2_USES=		gnome
LIBXML2_USE=		GNOME=libxml2

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ENV=	ne_cv_libsfor_SSL_library_init=-lssl
OPENSSL_CONFIGURE_ON=	--with-ssl=openssl

PROXY_CONFIGURE_WITH=	libproxy
PROXY_LIB_DEPENDS=	libproxy.so:net/libproxy

OPTIONS_SUB=		yes
DOCSDIR=		${PREFIX}/share/doc/neon

post-patch:
	${REINPLACE_CMD} -e 's|-@NEON_VERSION@$$||' ${WRKSRC}/Makefile.in

post-patch-DOCS-off:
	${REINPLACE_CMD} -e '152s|install-docs ||' ${WRKSRC}/Makefile.in

post-patch-MANPAGES-off:
	${REINPLACE_CMD} -e '152s|install-man ||' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libneon.so.27.*

.include <bsd.port.mk>
