# New ports collection makefile for:	rtorrent
# Date created:				Mar 03 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rtorrent
PORTVERSION=	0.1.4
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	flz@FreeBSD.org
COMMENT=	BitTorrent Client written in C++

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl		\
		torrent.2:${PORTSDIR}/net/libtorrent

USE_GCC=	3.4
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
USE_INC_LIBTOOL_VER=	13

PLIST_FILES=	bin/rtorrent
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|-O3||' ${WRKSRC}/configure

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}/

.include <bsd.port.mk>
