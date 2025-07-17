PORTNAME=	icingaweb2-module-vspheredb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
PORTREVISION=	3
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	gettoknowmi@yahoo.com
COMMENT=	Easily Monitor Vsphere with Icinga
WWW=		https://github.com/Icinga/icingaweb2-module-vspheredb

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2${PHP_PKGNAMESUFFIX}>=2.11.4:net-mgmt/icingaweb2@${PHP_FLAVOR} \
		icingaweb2-module-incubator${PHP_PKGNAMESUFFIX}>0:net-mgmt/icingaweb2-module-incubator@${PHP_FLAVOR} \
		icinga-php-library${PHP_PKGNAMESUFFIX}>0:net-mgmt/icinga-php-library@${PHP_FLAVOR} \
		icingaweb2-module-reactbundle${PHP_PKGNAMESUFFIX}>0:net-mgmt/icingaweb2-module-reactbundle@${PHP_FLAVOR}

USES=		mysql php:web,flavors
IGNORE_WITH_PHP=81

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

SUB_FILES=	vspheredb

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/vspheredb ${STAGEDIR}${PREFIX}/etc/rc.d
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
