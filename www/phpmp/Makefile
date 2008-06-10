# New ports collection makefile for:	phpmp
# Date created:		2007-02-27
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phpmp
PORTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://mercury.chem.pitt.edu/~shank/
DISTNAME=	phpMp-${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A web interface for music player daemon

NO_BUILD=	YES
USE_PHP=	pcre sockets

PHPMP?=		www/phpmp
PLIST_SUB+=	PHPMP=${PHPMP}

do-install:
	@${MKDIR} ${PREFIX}/${PHPMP}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${PHPMP}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPMP}
	@${CHMOD} -R 755 ${PREFIX}/${PHPMP}

.include <bsd.port.mk>
