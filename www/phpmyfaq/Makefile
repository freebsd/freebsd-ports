PORTNAME=	phpmyfaq
DISTVERSION=	4.0.16
CATEGORIES=	www
MASTER_SITES=	https://download.phpmyfaq.de/files/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Multilingual, completely database-driven FAQ-system
WWW=		https://www.phpmyfaq.de/

LICENSE=	MPL20

USES=		cpe php:web,flavors
USE_PHP=	curl fileinfo filter gd json mysqli session spl xml xmlrpc \
		xmlwriter zlib

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	YES
NO_ARCH=	YES

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
