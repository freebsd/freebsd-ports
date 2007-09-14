# New ports collection makefile for:	tikiwiki
# Date created:		19-JUNE-2006
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	tikiwiki
PORTVERSION=	1.9.8
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Powerful PHP based Wiki/CMS/Groupware

USE_PHP=	gettext pcre posix session xml zlib

NO_BUILD=	YES
USE_BZIP2=	YES
TIKIWIKI?=	www/tikiwiki
PLIST_SUB+=	TIKIWIKI=${TIKIWIKI}

do-install:
	${MKDIR} ${PREFIX}/${TIKIWIKI}
	@${CHMOD} 755 ${PREFIX}/${TIKIWIKI}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${TIKIWIKI}
	# set the correct permissions
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TIKIWIKI}

.include <bsd.port.mk>
