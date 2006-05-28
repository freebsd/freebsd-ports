# New ports collection makefile for:	xcache
# Date created:			28 May 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xcache
DISTVERSION=	1.0-rc
CATEGORIES=	www
MASTER_SITES=	http://210.51.190.228/pub/XCache/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A fast and stable php opcode cacher

USE_PHP=	yes
USE_PHPIZE=	yes

CONFIGURE_ARGS=	--enable-xcache=shared

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_DATA} ${WRKSRC}/modules/${PORTNAME}.so \
	       ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xcache.ini \
		${EXAMPLESDIR}

post-install:
	@${MKDIR} ${EXAMPLESDIR}/admin
	${INSTALL_DATA} ${WRKSRC}/admin/config.php.example \
		${WRKSRC}/admin/index.php \
		${WRKSRC}/admin/tablesort.js \
		${WRKSRC}/admin/xcache.css \
		${WRKSRC}/admin/xcache.php \
		${WRKSRC}/admin/xcache.tpl.php \
		${EXAMPLESDIR}/admin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
