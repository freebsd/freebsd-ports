# New ports collection makefile for:	abcache
# Date created:         Sat Feb 23 14:27:35 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	abcache
PORTVERSION=	0.14
CATEGORIES=	www
MASTER_SITES=	http://afterburner.bware.it/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A tool to cache applications written in PHP

WRKSRC=		${WRKDIR}/bware_cache-${PORTVERSION}

USE_PHP=	yes
USE_PHPIZE=	yes
WITH_PHP_MOD=	yes

CONFIGURE_ARGS+=--enable-bware_cache=shared

PKGMESSAGE=	${WRKDIR}/pkg-message

post-build:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g;s|%%PREFIX%%|${PREFIX}|g;s|%%PHP_EXT_DIR%%|${PHP_EXT_DIR}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/bware_cache.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
