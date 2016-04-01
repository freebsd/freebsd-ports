# Created by: ddurieux <d.durieux@siprossii.com>
# $FreeBSD$

PORTNAME=	AdditionalReports
DISTVERSION=	1.3.0
CATEGORIES=	textproc
MASTER_SITES=	https://forge.indepnet.net/attachments/download/136/ \
		http://glpi.siprossii.com/distfiles/
PKGNAMEPREFIX=	glpi-plugins-
DISTNAME=	glpi-reports-1.3.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	This plugin enables additional reports

BROKEN=		unfetchable

RUN_DEPENDS=	glpi>=0.72:www/glpi

WRKSRC=		${WRKDIR}/reports
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CPIOARGS=	--quiet -pdum
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

GLPIPLUGINDIR?=	www/glpi/plugins/reports

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${PREFIX}/${GLPIPLUGINDIR}
	@cd ${WRKSRC} && ${FIND} * -print | ${CPIO} ${CPIOARGS} ${STAGEDIR}${PREFIX}/${GLPIPLUGINDIR}

.include <bsd.port.mk>
