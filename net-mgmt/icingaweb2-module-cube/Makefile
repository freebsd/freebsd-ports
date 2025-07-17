PORTNAME=	icingaweb2-module-cube
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.2
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drill-down view for Icinga web 2 based on custom variables
WWW=		https://github.com/Icinga/icingaweb2-module-cube

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2${PHP_PKGNAMESUFFIX}>=2.12.1:net-mgmt/icingaweb2@${PHP_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes
NO_ARCH=	yes

USES=		php:web,flavors
IGNORE_WITH_PHP=81

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
