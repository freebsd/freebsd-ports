# New ports collection makefile for:	glpi-plugins-fusioninventory-server
# Date created:		2011-02-18
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	server
PORTVERSION=	${GLPI_VER}.${FUNV_VER}
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://forge.fusioninventory.org/attachments/download/668/
PKGNAMEPREFIX=	glpi-plugins-fusioninventory-
DISTNAME=	fusioninventory-for-glpi-metapackage_${GLPI_VER}+${FUNV_VER}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Plugin of glpi to get information of networking devices

RUN_DEPENDS=	glpi>=0.80:${PORTSDIR}/www/glpi

USE_PHP=	simplexml wddx

GLPI_VER=	0.80
FUNV_VER=	1.5
WRKSRC=		${WRKDIR}
NO_BUILD=	yes

GLPIPLUGINDIR?=	www/glpi/plugins

OPTIONS_DEFINE=	INVENTORY SNMP

INVENTORY_DESC=	Additional features
SNMP_DESC=	SNMP support

OPTIONS_DEFAULT=INVENTORY

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MINVENTORY}
PLIST_SUB+=	INVENTORY=""
.else
PLIST_SUB+=	INVENTORY="@comment "
.endif

.if ${PORT_OPTIONS:MSNMP}
PLIST_SUB+=	SNMP=""
.else
PLIST_SUB+=	SNMP="@comment "
.endif

do-install:
	@${MKDIR} -m 0755 ${PREFIX}/${GLPIPLUGINDIR}
	@${CP} -R ${WRKSRC}/fusioninventory ${PREFIX}/${GLPIPLUGINDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${GLPIPLUGINDIR}/fusioninventory

.if ${PORT_OPTIONS:MINVENTORY}
	@${CP} -R ${WRKSRC}/fusinvinventory ${PREFIX}/${GLPIPLUGINDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${GLPIPLUGINDIR}/fusinvinventory
.endif

.if ${PORT_OPTIONS:MSNMP}
	@${CP} -R ${WRKSRC}/fusinvsnmp ${PREFIX}/${GLPIPLUGINDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${GLPIPLUGINDIR}/fusinvsnmp
.endif

.include <bsd.port.post.mk>
