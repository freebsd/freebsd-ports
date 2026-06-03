PORTNAME=	icingaweb2-module-monitoring
DISTVERSIONPREFIX=	v
DISTVERSION=	2.12.6
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Monitoring module for Icinga Web 2
WWW=		https://github.com/Icinga/icingaweb2-module-monitoring

LICENSE=	GPLv2

USES=		php:web,flavors

USE_GITHUB=	yes
GH_ACCOUNT=	icinga
GH_TAG=		v2.12.6

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_USE=	PHP=intl

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
