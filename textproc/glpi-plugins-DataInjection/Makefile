# Created by: ddurieux <d.durieux@siprossii.com>
# $FreeBSD$

PORTNAME=	DataInjection
DISTVERSION=	1.7.2
CATEGORIES=	textproc
MASTER_SITES=	https://forge.indepnet.net/attachments/download/497/ \
		http://glpi.siprossii.com/distfiles/
PKGNAMEPREFIX=	glpi-plugins-
DISTNAME=	glpi-datainjection-1.7.2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	This glpi plugin allows data import into GLPI using CSV files

BROKEN=		unfetchable

RUN_DEPENDS=	glpi>=0.72:www/glpi

WRKSRC=		${WRKDIR}/datainjection
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CPIOARGS=	--quiet -pdum
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

GLPIPLUGINDIR?=	www/glpi/plugins/datainjection

do-install:
	@${MKDIR} -m 0755 ${STAGEDIR}${PREFIX}/${GLPIPLUGINDIR}
	@cd ${WRKSRC} && ${FIND} * -print | ${CPIO} ${CPIOARGS} ${STAGEDIR}${PREFIX}/${GLPIPLUGINDIR}

.include <bsd.port.mk>
