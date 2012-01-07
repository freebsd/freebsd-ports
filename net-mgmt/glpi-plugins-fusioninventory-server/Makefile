# New ports collection makefile for:	glpi-plugins-fusioninventory-server
# Date created:		2011-02-18
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	server
PORTVERSION=	2.4.0
CATEGORIES=	net-mgmt
MASTER_SITES=	http://forge.fusioninventory.org/attachments/download/456/
PKGNAMEPREFIX=	glpi-plugins-fusioninventory-
DISTNAME=	fusioninventory-for-glpi-metapackage_${PORTVERSION}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Plugin of glpi to get information of networking devices

RUN_DEPENDS=	glpi>=0.80:${PORTSDIR}/www/glpi

USE_PHP=	simplexml wddx

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

GLPIPLUGINDIR?=	www/glpi/plugins

OPTIONS=	INVENTORY "Additional features" on \
		SNMP "SNMP support" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_INVENTORY)
PLIST_SUB+=	INVENTORY="@comment "
.else
PLIST_SUB+=	INVENTORY=""
.endif

.if defined(WITHOUT_SNMP)
PLIST_SUB+=	SNMP="@comment "
.else
PLIST_SUB+=	SNMP=""
.endif

do-install:
	@${MKDIR} -m 0755 ${PREFIX}/${GLPIPLUGINDIR}
	@${CP} -R ${WRKSRC}/fusioninventory ${PREFIX}/${GLPIPLUGINDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${GLPIPLUGINDIR}/fusioninventory

.if !defined(WITHOUT_INVENTORY)
	@${CP} -R ${WRKSRC}/fusinvinventory ${PREFIX}/${GLPIPLUGINDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${GLPIPLUGINDIR}/fusinvinventory
.endif

.if !defined(WITHOUT_SNMP)
	@${CP} -R ${WRKSRC}/fusinvsnmp ${PREFIX}/${GLPIPLUGINDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${GLPIPLUGINDIR}/fusinvsnmp
.endif

.include <bsd.port.post.mk>
