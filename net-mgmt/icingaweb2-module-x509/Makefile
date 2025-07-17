PORTNAME=	icingaweb2-module-x509
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	gettoknowmi@yahoo.com
COMMENT=	Automates certificate monitoring with Icinga
WWW=		https://github.com/Icinga/icingaweb2-module-x509

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icinga-php-library${PHP_PKGNAMESUFFIX}>0:net-mgmt/icinga-php-library@${PHP_FLAVOR} \
		icingaweb2${PHP_PKGNAMESUFFIX}>=2.11.4:net-mgmt/icingaweb2@${PHP_FLAVOR} \
		icingaweb2-module-reactbundle${PHP_PKGNAMESUFFIX}>0:net-mgmt/icingaweb2-module-reactbundle@${PHP_FLAVOR}

USES=		mysql:server php:web,flavors ssl

USE_GITHUB=	yes
GH_ACCOUNT=	Icinga

USE_PHP=	gmp
IGNORE_WITH_PHP=81

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

do-install:
	@${RM} -r ${WRKSRC}/.github
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
