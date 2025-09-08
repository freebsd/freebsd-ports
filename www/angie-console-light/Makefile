PORTNAME=	angie-console-light
DISTVERSION=	1.8.1
CATEGORIES=	www
MASTER_SITES=	https://download.angie.software/files/angie-console-light/

MAINTAINER=	sko@rostwald.de
COMMENT=	Angie Web Monitoring Panel
WWW=		https://en.angie.software/angie/docs/configuration/monitoring/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
