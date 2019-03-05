# $FreeBSD$

PORTNAME=	icingaweb2-module-director
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2
CATEGORIES=	net-mgmt www

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Configuration frontend for Icinga 2, integrated automation

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2>=2.4.1:net-mgmt/icingaweb2

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

USES=		php
USE_PHP=	yes

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=		NLS

NLS_USES=	gettext
NLS_USE=	php=intl

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
