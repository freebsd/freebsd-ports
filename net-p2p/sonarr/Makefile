# $FreeBSD$

PORTNAME=	sonarr
PORTVERSION=	2.0.0.3732
PORTREVISION=	0
CATEGORIES=	net-p2p
MASTER_SITES=	http://download.sonarr.tv/v2/master/mono/
DISTNAME=	NzbDrone.master.${PORTVERSION}.mono

MAINTAINER=	feld@FreeBSD.org
COMMENT=	PVR for Usenet and BitTorrent users

LICENSE=	GPLv3

RUN_DEPENDS=	mono>0:${PORTSDIR}/lang/mono \
		mediainfo>0:${PORTSDIR}/multimedia/mediainfo \
		sqlite3>0:${PORTSDIR}/databases/sqlite3
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USE_RC_SUBR=	sonarr

NO_BUILD=	YES
WRKSRC=	${WRKDIR}/NzbDrone

USERS=	sonarr

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}

.include <bsd.port.mk>
