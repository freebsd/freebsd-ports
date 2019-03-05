# $FreeBSD$

PORTNAME=	icingaweb2-module-businessprocess
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
CATEGORIES=	net-mgmt www

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Manage Business Processes in Icinga Web 2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2>=2.4.1:net-mgmt/icingaweb2 \
		icingaweb2-module-ipl>=0.1.1:net-mgmt/icingaweb2-module-ipl

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

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
