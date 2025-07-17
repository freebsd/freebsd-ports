PORTNAME=	icingaweb2-module-businessprocess
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
PORTREVISION=	0
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Manage Business Processes in Icinga Web 2
WWW=		https://github.com/Icinga/icingaweb2-module-businessprocess

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2${PHP_PKGNAMESUFFIX}>=2.12.1:net-mgmt/icingaweb2@${PHP_FLAVOR} \
		icinga-php-library${PHP_PKGNAMESUFFIX}>=0.13.1:net-mgmt/icinga-php-library@${PHP_FLAVOR}

USES=		php:web,flavors
IGNORE_WITH_PHP=81

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=		NLS

NLS_USES=	gettext php
NLS_USE=	php=intl

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
