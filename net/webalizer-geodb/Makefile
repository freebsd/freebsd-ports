PORTNAME=	webalizer-geodb
PORTVERSION=	20251229
CATEGORIES+=	net
MASTER_SITES=	ftp://ftp.dinoex.de/pub/webalizer/ \
		https://ftp.dinoex.de/pub/webalizer/ \
		https://ftp.dinoex.org/pub/webalizer/

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
