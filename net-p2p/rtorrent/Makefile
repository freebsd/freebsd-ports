# $FreeBSD$

PORTNAME?=	rtorrent
PORTVERSION=	0.9.2
PORTREVISION=	5
CATEGORIES=	net-p2p
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BitTorrent Client written in C++

BUILD_DEPENDS=	libtorrent=0.13.2_3:${PORTSDIR}/net-p2p/libtorrent
RUN_DEPENDS=	libtorrent=0.13.2_3:${PORTSDIR}/net-p2p/libtorrent
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

CONFLICTS=	rtorrent-devel-[0-9]*

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

# Workaround to build on >= 10.x
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
CXXFLAGS+=	-std=c++11
EXTRA_PATCHES+=	${FILESDIR}/extra-clang
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
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
	@${FIND} ${WRKSRC} \( -name '*.h' -o -name '*.cc' \) -type f \
		-exec ${REINPLACE_CMD} -e 's/tr1::/std::/g' {} \; \
		-exec ${REINPLACE_CMD} -e 's/std::std::/std::/g' {} \; \
		-exec ${REINPLACE_CMD} -e '/namespace tr1/d' {} \; \
		-exec ${REINPLACE_CMD} -e '/include/s,tr1/,,' {} \;
.endif

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
