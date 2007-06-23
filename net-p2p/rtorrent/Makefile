# New ports collection makefile for:	rtorrent
# Date created:				Mar 03 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	rtorrent
PORTVERSION?=	0.7.4
PORTREVISION?=	0
CATEGORIES=	net-p2p
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	flz/rtorrent/

MAINTAINER?=	flz@FreeBSD.org
COMMENT?=	BitTorrent Client written in C++

LIB_DEPENDS?=	# empty

BUILD_DEPENDS?=	libtorrent>=0.11.3:${PORTSDIR}/net-p2p/libtorrent
RUN_DEPENDS?=	libtorrent>=0.11.3:${PORTSDIR}/net-p2p/libtorrent
LIB_DEPENDS+=	curl.4:${PORTSDIR}/ftp/curl

CONFLICTS?=	rtorrent-devel-[0-9]*

MAN1=		rtorrent.1

USE_GCC=	3.4+
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug --mandir="${PREFIX}/man"
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

SUB_FILES=	pkg-message

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/configure

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}/
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc ${EXAMPLESDIR}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
