# New ports collection makefile for:	rtorrent
# Date created:				Mar 03 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rtorrent
PORTVERSION=	0.3.0
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	flz@FreeBSD.org
COMMENT=	BitTorrent Client written in C++

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl		\
		torrent.4:${PORTSDIR}/net/libtorrent

MAN1=		rtorrent.1

USE_GCC=	3.4
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
USE_INC_LIBTOOL_VER=	13

SUB_FILES=	pkg-message

PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/configure

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}/
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc ${EXAMPLESDIR}/
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
