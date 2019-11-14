# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	neon
PORTVERSION=	0.30.2
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	LOCAL/lev

MAINTAINER=	lev@FreeBSD.org
COMMENT=	HTTP and WebDAV client library for Unix systems

LICENSE=	GPLv2

USES=		pathfix libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		CA_BUNDLE DOCS GSSAPI NLS OPENSSL PROXY
OPTIONS_DEFAULT=	CA_BUNDLE EXPAT GSSAPI OPENSSL
OPTIONS_SINGLE=		XML
OPTIONS_SINGLE_XML=	EXPAT LIBXML

CA_BUNDLE_DESC=		Install CA bundle for OpenSSL
LIBXML_DESC=		libxml2 XML parser support
PROXY_DESC=		libproxy support
XML_DESC=		XML parser library

CA_BUNDLE_CONFIGURE_ON=	--with-ca-bundle=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
EXPAT_CONFIGURE_WITH=	expat
EXPAT_LIB_DEPENDS=	libexpat.so:textproc/expat2
GSSAPI_CONFIGURE_WITH=	gssapi
LIBXML_CONFIGURE_WITH=	libxml2
LIBXML_USES=		gnome
LIBXML_USE=		GNOME=libxml2
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
OPENSSL_CONFIGURE_ENV=	ne_cv_libsfor_SSL_library_init=-lssl
OPENSSL_CONFIGURE_WITH=	ssl
OPENSSL_USES=		ssl
PROXY_CONFIGURE_WITH=	libproxy
PROXY_LIB_DEPENDS=	libproxy.so:net/libproxy

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=--enable-shared \
		--with-libs=${LOCALBASE}:${PREFIX}

.if ${PORT_OPTIONS:MCA_BUNDLE} && !${PORT_OPTIONS:MOPENSSL}
WARNING+=	"OpenSSL need for CA bundle support"
WARNING+=	"Enable the OPENSSL option or disable the CA_BUNDLE option"
.endif

PLIST_SUB+=	PORTVERSION=${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/neon

post-patch:
	${REINPLACE_CMD} -e 's|-@NEON_VERSION@$$||' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libneon.so.27.*

.include <bsd.port.mk>
