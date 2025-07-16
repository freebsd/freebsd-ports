PORTNAME=	icinga-php-library
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Icinga PHP library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:web,flavors

USE_PHP=	filter
IGNORE_WITH_PHP=81

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/icingaweb2/icinga-php/${PORTNAME:C/^.*-//}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
