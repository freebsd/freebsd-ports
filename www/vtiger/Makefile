# New ports collection makefile for:	vtiger
# Date created:			Fri Mar 11 20:59:31 EST 2005
# Whom:				Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	vtiger
PORTVERSION=	4.0p1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vtigercrm
DISTFILES=	${DIST_MAIN} ${DIST_ADDITIONAL}
EXTRACT_ONLY=	${DIST_MAIN}

MAINTAINER=	edwin@mavetju.org
COMMENT=	vtiger CRM is open source Customer Relationship Management (CRM) software

DIST_MAIN=	${PORTNAME}_CRM_4_0_Source${EXTRACT_SUFX}
DIST_ADDITIONAL=${PORTNAME}CRM_4_0_Patch_1${EXTRACT_SUFX}
WRKSRC=		${WRKDIR}/vtiger_crm_source
USE_ZIP=	yes
USE_PHP=	mysql gd session pcre

NO_BUILD=	yes

WWWDIR?=	${PREFIX}/www/vtiger

post-extract:
	@${ECHO_CMD} "Extracting patch 1"
	@${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_ADDITIONAL} -d ${WRKSRC}

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/* ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
