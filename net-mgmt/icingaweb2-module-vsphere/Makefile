# $FreeBSD$

PORTNAME=	icingaweb2-module-vsphere
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTREVISION=	4
CATEGORIES=	net-mgmt www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Automated import of your VMs and Physical Host from VMware Sphere

RUN_DEPENDS=	icingaweb2${PHP_PKGNAMESUFFIX}>=2.4.1:net-mgmt/icingaweb2@${PHP_FLAVOR} \
		icingaweb2-module-director${PHP_PKGNAMESUFFIX}>=1.6.2:net-mgmt/icingaweb2-module-director@${PHP_FLAVOR}

USES=		php:web,flavors
USE_PHP=	posix soap

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
