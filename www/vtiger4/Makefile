# New ports collection makefile for:	vtiger4
# Date created:			Fri Mar 11 20:59:31 EST 2005
# Whom:				Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	vtiger4
DISTVERSION=	4.2.4
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vtigercrm
DISTNAME=	vtigercrm-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	vtiger CRM is open source Customer Relationship Management (CRM) software

USE_PHP=	mysql gd session pcre xml
NO_BUILD=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

DEPRECATED=	This version is no longer supported by the developers
EXPIRATION_DATE=	2007-10-31

WWWDIR=		${PREFIX}/www/vtiger
WRKSRC=		${WRKDIR}/vtiger_crm

post-extract:
	${FIND} ${WRKSRC} -name .svn -delete

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/* ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
