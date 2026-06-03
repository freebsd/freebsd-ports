PORTNAME=	icingaweb2-module-grafana
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.3
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	dsh@bamus.cz
COMMENT=	Add Grafana graphs into Icinga Web 2 to display performance metrics

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2${PHP_PKGNAMESUFFIX}>=2.11.4:net-mgmt/icingaweb2@${PHP_FLAVOR}

USES=		php:web,flavors

USE_GITHUB=	yes
GH_ACCOUNT=	NETWAYS

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}
EXTRACT_AFTER_ARGS=	--exclude .idea \
			--exclude .github \
			--no-same-owner --no-same-permissions
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
