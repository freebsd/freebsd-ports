# $FreeBSD: head/net/webalizer-geodb/Makefile 566829 2021-03-01 06:16:34Z dinoex $

PORTNAME=	webalizer-geodb
PORTVERSION=	20210401
CATEGORIES+=	net
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/geodb/ \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Webalizer GeoDB geolocation database

LICENSE=	GPLv2

USES=		tar:tgz
WRKSRC=		${WRKDIR}
NO_BUILD=	yes
PLIST_FILES=	share/geolizer/GeoDB.dat

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/geolizer
	${INSTALL_DATA} ${WRKDIR}/GeoDB.dat ${STAGEDIR}${PREFIX}/share/geolizer/

.include <bsd.port.mk>
