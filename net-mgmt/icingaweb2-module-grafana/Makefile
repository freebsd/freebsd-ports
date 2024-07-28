PORTNAME=	icingaweb2-module-grafana
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.3
PORTREVISION=	0
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Add Grafana graphs into Icinga Web 2 to display performance metrics
WWW=		https://github.com/Mikesch-mp/icingaweb2-module-grafana

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2${PHP_PKGNAMESUFFIX}>=2.11.4:net-mgmt/icingaweb2@${PHP_FLAVOR}

USES=		php:web,flavors
IGNORE_WITH_PHP=	84

USE_GITHUB=	yes
GH_ACCOUNT=	mikesch-mp

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

do-install:
	@${RM} -r ${WRKSRC}/.idea ${WRKSRC}/.github
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
