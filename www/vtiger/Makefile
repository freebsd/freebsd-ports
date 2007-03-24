# New ports collection makefile for:	vtiger
# Date created:			Fri Mar 11 20:59:31 EST 2005
# Whom:				Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	vtiger
DISTVERSION=	5.0.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vtigercrm
DISTNAME=	vtigercrm-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vtiger CRM is open source Customer Relationship Management (CRM) software

USE_PHP=	mysql gd imap session pcre xml
IGNORE_WITH_PHP=4
NO_BUILD=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_MYSQL=	yes
WANT_MYSQL_VER=	50

WRKSRC=		${WRKDIR}/vtigercrm

post-extract:
	${FIND} ${WRKSRC} -name .svn -delete

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/* ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
