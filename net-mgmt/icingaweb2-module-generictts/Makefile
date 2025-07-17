PORTNAME=	icingaweb2-module-generictts
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic ticket system integration into Icinga web 2
WWW=		https://github.com/Icinga/icingaweb2-module-generictts

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2${PHP_PKGNAMESUFFIX}>=2.11.4:net-mgmt/icingaweb2@${PHP_FLAVOR}

USES=		php:web,flavors
IGNORE_WITH_PHP=81

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
