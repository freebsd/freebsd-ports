# New ports collection makefile for:	vtiger
# Date created:			Fri Mar 11 20:59:31 EST 2005
# Whom:				Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	vtiger
DISTVERSION=	4.0RC1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vtigercrm
DISTNAME=	${PORTNAME}_CRM_4_0_RC1_Source

MAINTAINER=	edwin@mavetju.org
COMMENT=	vtiger CRM is open source Customer Relationship Management (CRM) software

WRKSRC=		${WRKDIR}/vtiger_crm_source
USE_ZIP=	yes
USE_PHP=	mysql gd

NO_BUILD=	yes

WWWDIR?=	${PREFIX}/www/vtiger

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/* ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	${CAT} pkg-message

.include <bsd.port.mk>
