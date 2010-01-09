# New ports collection makefile for:   glpi-plugins-DataInjection
# Date created:        01 November 2009
# Whom:                ddurieux <d.durieux@siprossii.com>
#
# $FreeBSD$
#

PORTNAME=	DataInjection
DISTVERSION=	1.7.2
CATEGORIES=	textproc
MASTER_SITES=	https://forge.indepnet.net/attachments/download/497/ \
		http://glpi.siprossii.com/distfiles/
PKGNAMEPREFIX=	glpi-plugins-
DISTNAME=	glpi-datainjection-1.7.2

MAINTAINER=	d.durieux@siprossii.com
COMMENT=	This glpi plugin allows data import into GLPI using CSV files

RUN_DEPENDS=	glpi>=0.72:${PORTSDIR}/www/glpi

WRKSRC=		${WRKDIR}/datainjection
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CPIOARGS=	--quiet -pdum -R

GLPIPLUGINDIR?=	www/glpi/plugins/datainjection

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} -m 0755 ${PREFIX}/${GLPIPLUGINDIR}
	@cd ${WRKSRC} && ${FIND} * -print | ${CPIO} ${CPIOARGS} ${WWWOWN}:${WWWGRP} ${PREFIX}/${GLPIPLUGINDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${GLPIPLUGINDIR}

.include <bsd.port.post.mk>
