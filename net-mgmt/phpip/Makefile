# New ports collection makefile for:	phpip
# Date created:		2006-10-28
# Whom:			Babak Farrokhi <babak@farrokhi.net>
#
# $FreeBSD$
#

PORTNAME=	phpip
PORTVERSION=	4.3.${SNAPSHOT}
CATEGORIES=	www net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpip
DISTNAME=	${PORTNAME}-4.3-build-${SNAPSHOT}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	A complete IPv4 IPAM (IP address management) suite

SNAPSHOT=	200610162352
NO_BUILD=	YES
USE_PHP=	mysql
WANT_PHP_WEB=	YES

PHPIP?=		www/phpip
PLIST_SUB+=	PHPIP=${PHPIP}

do-install:
	@${MKDIR} ${PREFIX}/${PHPIP}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${PHPIP}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${PHPIP}
	@${CHMOD} -R 755 ${PREFIX}/${PHPIP}

.include <bsd.port.mk>
