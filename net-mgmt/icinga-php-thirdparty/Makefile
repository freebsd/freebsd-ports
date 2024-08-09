PORTNAME=	icinga-php-thirdparty
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.1
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Icinga PHP thirdparty
WWW=		https://github.com/Icinga/icinga-php-thirdparty

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:web,flavors

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/icingaweb2/icinga-php/${PORTNAME:C/^.*-//}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
