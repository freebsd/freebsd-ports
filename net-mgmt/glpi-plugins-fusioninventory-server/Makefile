# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	server
PORTVERSION=	${GLPI_VER}.${FUNV_VER}
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://forge.fusioninventory.org/attachments/download/1665/
PKGNAMEPREFIX=	glpi-plugins-fusioninventory-
DISTNAME=	fusioninventory-for-glpi_${GLPI_VER}+${FUNV_VER}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Plugin of glpi to get information of networking devices

LICENSE=	AGPLv3

RUN_DEPENDS=	glpi>=0.84:${PORTSDIR}/www/glpi

USE_PHP=	fileinfo simplexml wddx
USES=		gettext
GLPI_VER=	0.84
FUNV_VER=	3.5
WRKSRC=		${WRKDIR}
NO_BUILD=	yes

GLPIPLUGINDIR?=	www/glpi/plugins

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${PREFIX}/${GLPIPLUGINDIR}
	@${CP} -R ${WRKSRC}/fusioninventory ${STAGEDIR}${PREFIX}/${GLPIPLUGINDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${PREFIX}/${GLPIPLUGINDIR}/fusioninventory

.include <bsd.port.post.mk>
