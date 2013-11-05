# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	neon29
PORTVERSION=	0.29.6
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.webdav.org/neon/
DISTNAME=	neon-${PORTVERSION}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	An HTTP and WebDAV client library for Unix systems

CONFLICTS=	neon2[^9]-[0-9]*

OPTIONS_DEFINE=		OPENSSL NLS GSSAPI PROXY DOCS
OPTIONS_DEFAULT=	EXPAT OPENSSL NLS GSSAPI
OPTIONS_SINGLE=		XML
OPTIONS_SINGLE_XML=	EXPAT LIBXML

XML_DESC=		XML parser library
LIBXML_DESC=		libxml2 XML parser support
PROXY_DESC=		libproxy support

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

USES=		pathfix
USE_GNOME=	ltverhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--with-libs=${LOCALBASE}:${PREFIX}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXPAT}
CONFIGURE_ARGS+=--with-expat
LIB_DEPENDS+=	expat.6:${PORTSDIR}/textproc/expat2
.endif

.if ${PORT_OPTIONS:MLIBXML}
CONFIGURE_ARGS+=--with-libxml2
LIB_DEPENDS+=	xml2.5:${PORTSDIR}/textproc/libxml2
.endif

.if ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=--with-ssl
USE_OPENSSL=	yes
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ! ${PORT_OPTIONS:MGSSAPI}
CONFIGURE_ARGS+=--without-gssapi
.endif

.if ${PORT_OPTIONS:MPROXY}
CONFIGURE_ARGS+=--with-libproxy
LIB_DEPENDS+=	proxy.1:${PORTSDIR}/net/libproxy
.else
CONFIGURE_ARGS+=--without-libproxy
.endif

PLIST_SUB+=	PORTVERSION=${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/neon

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.3 ${STAGEDIR}${MANPREFIX}/man/man3
	${MAKE} -C ${WRKSRC} install-html ${MAKE_ARGS}

.include <bsd.port.mk>
