# $FreeBSD$

PORTNAME?=	rtorrent
PORTVERSION=	0.9.2
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	az@FreeBSD.org
COMMENT=	BitTorrent Client written in C++

BUILD_DEPENDS=	libtorrent=0.13.2_1:${PORTSDIR}/net-p2p/libtorrent
RUN_DEPENDS=	libtorrent=0.13.2_1:${PORTSDIR}/net-p2p/libtorrent
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

CONFLICTS=	rtorrent-devel-[0-9]*

GNU_CONFIGURE=	yes
USES=		pkgconfig
LDFLAGS+=	-pthread
CONFIGURE_ARGS=	--disable-debug

SUB_FILES=	pkg-message

PORTDOCS=	README

OPTIONS_DEFINE=	XMLRPC IPV6 DOCS
OPTIONS_DEFAULT=	XMLRPC IPV6
XMLRPC_DESC=	Compile with xmlrpc-c support

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not configure on arm
.endif

# Workaround to build and segfault on > 10.x
.if ${OPSYS} == "FreeBSD" && ${OSVERSION} >= 1000000
USE_GCC=        yes
LDFLAGS+=	-lc++
.endif

.if ${PORT_OPTIONS:MXMLRPC}
CONFIGURE_ARGS+=	--with-xmlrpc-c
LIB_DEPENDS+=	xmlrpc.3:${PORTSDIR}/net/xmlrpc-c-devel
.else
CONFIGURE_ARGS+=	--with-xmlrpc-c=no
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/configure

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc ${EXAMPLESDIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
