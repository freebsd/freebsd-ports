# Created by: Florent Thoumie <flz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rtorrent-devel
PORTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/
DISTNAME=	${PORTNAME:S/-devel//}-${PORTVERSION}

MAINTAINER=	az@FreeBSD.org
COMMENT=	BitTorrent Client written in C++ (development version)

BUILD_DEPENDS=	libtorrent-devel=0.13.3:${PORTSDIR}/net-p2p/libtorrent-devel
RUN_DEPENDS=	libtorrent-devel=0.13.3:${PORTSDIR}/net-p2p/libtorrent-devel
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

CONFLICTS=	rtorrent-[0-9]*

GNU_CONFIGURE=	yes
USES=		pkgconfig
LDFLAGS+=	-pthread
CONFIGURE_ARGS=	--disable-debug

SUB_FILES=	pkg-message

PORTDOCS=	README

OPTIONS_DEFINE=	XMLRPC IPV6 DOCS
OPTIONS_DEFAULT=	XMLRPC IPV6
XMLRPC_DESC=	Compile with xmlrpc-c support

.include <bsd.port.pre.mk>

.if ${ARCH} == "arm"
BROKEN=		Does not configure on arm
.endif

.if ${PORT_OPTIONS:MXMLRPC}
CONFIGURE_ARGS+=	--with-xmlrpc-c
LIB_DEPENDS+=	xmlrpc:${PORTSDIR}/net/xmlrpc-c-devel
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
