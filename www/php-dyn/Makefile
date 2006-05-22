# New ports collection makefile for:	php-dyn
# Date created:         Wed May 22 14:27:22 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	php-dyn
PORTVERSION=	1.2.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	php_dyn-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PHP Extension to help debugging a PHP script

USE_PHP=	yes
USE_PHPIZE=	yes
WITH_PHP_MOD=	yes
BROKEN_WITH_PHP=5
DEFAULT_PHP_VER=4

CONFIGURE_ARGS=	--enable-php_dyn=shared

PKGMESSAGE=	${WRKDIR}/pkg-message

post-build:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g;s|%%PREFIX%%|${PREFIX}|g;s|%%PHP_EXT_DIR%%|${PHP_EXT_DIR}|g" \
		${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/php_dyn.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.en ${DOCSDIR}/README
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
