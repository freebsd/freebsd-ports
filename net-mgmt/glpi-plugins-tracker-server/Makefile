# Created by: ddurieux <d.durieux@siprossii.com>
# $FreeBSD$

PORTNAME=	server
DISTVERSION=	2.1.3
CATEGORIES=	net-mgmt
MASTER_SITES=	https://forge.indepnet.net/attachments/download/512/ \
		http://glpi.siprossii.com/distfiles/
PKGNAMEPREFIX=	glpi-plugins-tracker-
DISTNAME=	glpi-tracker_server-2.1.3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin of glpi to get information of networking devices by SNMP

RUN_DEPENDS=	glpi>=0.72:${PORTSDIR}/www/glpi

DEPRECATED=	superceded by net-mgmt/glpi-plugins-fusioninventory-server
EXPIRATION_DATE=	2015-05-22

USE_PHP=	zlib

WRKSRC=		${WRKDIR}/tracker
NO_BUILD=	yes
CPIOARGS=	--quiet -pdum
SUB_FILES=	pkg-message
SUB_LIST=	GLPIPLUGINDIR="${GLPIPLUGINDIR}"
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

GLPIPLUGINDIR?=	www/glpi/plugins/tracker

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${PREFIX}/${GLPIPLUGINDIR}
	@cd ${WRKSRC} && ${FIND} * -print | ${CPIO} ${CPIOARGS} ${STAGEDIR}${PREFIX}/${GLPIPLUGINDIR}

.include <bsd.port.mk>
