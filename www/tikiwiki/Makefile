# New ports collection makefile for:	tikiwiki
# Date created:		19-JUNE-2006
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	tikiwiki
PORTVERSION=	8.3
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Tiki_8.x_Acubens/${PORTVERSION}/
DISTNAME=	tiki-${PORTVERSION}

MAINTAINER=	c.petrik.sosa@gmail.com
COMMENT=	Powerful PHP based Wiki/CMS/Groupware

USE_PHP=	gettext pcre posix session xml zlib

NO_BUILD=	YES

do-extract:
	${MKDIR} ${WRKDIR}
	${TAR} -yxf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} -C ${WRKDIR}

do-install:
	@-${MKDIR} ${WWWDIR}
	@(cd ${WRKDIR}/tiki-${PORTVERSION} && ${COPYTREE_SHARE} . ${WWWDIR})
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

.include <bsd.port.mk>
