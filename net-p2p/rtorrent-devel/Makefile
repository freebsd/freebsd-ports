# $FreeBSD$

PORTNAME=	rtorrent-devel
PORTVERSION=	0.9.3
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/
DISTNAME=	${PORTNAME:S/-devel//}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BitTorrent Client written in C++ (development version)

BUILD_DEPENDS=	libtorrent-devel=0.13.3_1:${PORTSDIR}/net-p2p/libtorrent-devel
RUN_DEPENDS=	libtorrent-devel=0.13.3_1:${PORTSDIR}/net-p2p/libtorrent-devel
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

CONFLICTS=	rtorrent-[0-9]*

GNU_CONFIGURE=	yes
USES=		pkgconfig
LDFLAGS+=	-pthread
CONFIGURE_ARGS=	--disable-debug

SUB_FILES=	pkg-message

PORTDOCS=	README

OPTIONS_DEFINE=	XMLRPC IPV6 DOCS
OPTIONS_DEFAULT=	XMLRPC
XMLRPC_DESC=	Compile with xmlrpc-c support

.include <bsd.port.options.mk>

.if ${ARCH} == arm
BROKEN=		Does not configure on arm
.endif

# Workaround to build and segfault on > 10.x
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
USE_GCC=	yes
LDFLAGS+=	-lc++
.endif

.if ${PORT_OPTIONS:MXMLRPC}
CONFIGURE_ARGS+=	--with-xmlrpc-c
LIB_DEPENDS+=	libxmlrpc.so:${PORTSDIR}/net/xmlrpc-c-devel
.else
CONFIGURE_ARGS+=	--with-xmlrpc-c=no
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
