# New ports collection makefile for:	rtorrent
# Date created:				Mar 03 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	rtorrent
PORTVERSION?=	0.8.7
CATEGORIES=	net-p2p
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/rtorrent/

MAINTAINER?=	flz@FreeBSD.org
COMMENT?=	BitTorrent Client written in C++

BUILD_DEPENDS?=	libtorrent=0.12.7:${PORTSDIR}/net-p2p/libtorrent
RUN_DEPENDS?=	libtorrent=0.12.7:${PORTSDIR}/net-p2p/libtorrent
LIB_DEPENDS?=	curl.6:${PORTSDIR}/ftp/curl

CONFLICTS?=	rtorrent-devel-[0-9]*

USE_GCC=	4.2+

GNU_CONFIGURE=	yes
CONFIGURE_ENV+= LDFLAGS="${LDFLAGS} -pthread"
CONFIGURE_ARGS=	--disable-debug

SUB_FILES=	pkg-message

PORTDOCS=	README

OPTIONS=	XMLRPC "Compile with xmlrpc-c support" on \
		IPV6 "Enable IPv6 support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_XMLRPC)
CONFIGURE_ARGS+=	--with-xmlrpc-c
LIB_DEPENDS+=	xmlrpc.3:${PORTSDIR}/net/xmlrpc-c-devel
.else
CONFIGURE_ARGS+=	--with-xmlrpc-c=no
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/configure

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc ${EXAMPLESDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
