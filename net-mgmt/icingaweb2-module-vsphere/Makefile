# $FreeBSD$

PORTNAME=	icingaweb2-module-vsphere
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	net-mgmt www

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Automated import of your VMs and Physical Host from VMware Sphere

RUN_DEPENDS=	icingaweb2>=2.4.1:net-mgmt/icingaweb2 \
		${LOCALBASE}/www/icingaweb2/modules/director/run.php:net-mgmt/icingaweb2-module-director

USES=		php
USE_GITHUB=	yes
GH_ACCOUNT=	icinga
USE_PHP=	posix soap

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
