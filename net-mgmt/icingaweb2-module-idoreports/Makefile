# $FreeBSD$

PORTNAME=	icingaweb2-module-idoreports
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	net-mgmt www

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Host and service availability reports for Icinga

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2>=2.6.0:net-mgmt/icingaweb2 \
		icingaweb2-module-reporting>=0.9:net-mgmt/icingaweb2-module-reporting

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
