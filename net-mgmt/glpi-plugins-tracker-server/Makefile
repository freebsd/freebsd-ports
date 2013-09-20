# Created by: ddurieux <d.durieux@siprossii.com>
# $FreeBSD$

PORTNAME=	server
DISTVERSION=	2.1.3
CATEGORIES=	net-mgmt
MASTER_SITES=	https://forge.indepnet.net/attachments/download/512/ \
		http://glpi.siprossii.com/distfiles/
PKGNAMEPREFIX=	glpi-plugins-tracker-
DISTNAME=	glpi-tracker_server-2.1.3

MAINTAINER=	d.durieux@siprossii.com
COMMENT=	Plugin of glpi to get information of networking devices by SNMP

RUN_DEPENDS=	glpi>=0.72:${PORTSDIR}/www/glpi

USE_PHP=	zlib

WRKSRC=		${WRKDIR}/tracker
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CPIOARGS=	--quiet -pdum -R

GLPIPLUGINDIR?=	www/glpi/plugins/tracker

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
	  -e 's,%%GLPIPLUGINDIR%%,${GLPIPLUGINDIR},g' pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} -m 0755 ${PREFIX}/${GLPIPLUGINDIR}
	@cd ${WRKSRC} && ${FIND} * -print | ${CPIO} ${CPIOARGS} ${WWWOWN}:${WWWGRP} ${PREFIX}/${GLPIPLUGINDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${GLPIPLUGINDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
