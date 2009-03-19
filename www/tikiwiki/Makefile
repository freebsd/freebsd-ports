# New ports collection makefile for:	tikiwiki
# Date created:		19-JUNE-2006
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	tikiwiki
PORTVERSION=	2.3
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Powerful PHP based Wiki/CMS/Groupware

USE_PHP=	gettext pcre posix session xml zlib

NO_BUILD=	YES
USE_BZIP2=	YES

do-install:
	@-${MKDIR} ${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR})
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

.include <bsd.port.mk>
