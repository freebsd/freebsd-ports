# New ports collection makefile for:	xcache
# Date created:			28 May 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xcache
DISTVERSION=	1.0.2
CATEGORIES=	www
MASTER_SITES=	http://210.51.190.228/pub/XCache/Releases/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A fast and stable php opcode cacher

USE_PHP=	yes
USE_PHPIZE=	yes

CONFIGURE_ARGS=	--enable-xcache=shared

OPTIONS=	COVERAGER "Enable code coverage dumper" off

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_COVERAGER)
CONFIGURE_ARGS+=--enable-xcache-coverager
PLIST_SUB+=	COVERAGER=""
.else
PLIST_SUB+=	COVERAGER="@comment "
.endif

post-build:
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|;s|%%PHP_EXT_DIR%%|${PHP_EXT_DIR}|' \
		${WRKSRC}/xcache.ini

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
		${WRKSRC}/admin/help.php \
		${WRKSRC}/admin/index.php \
		${WRKSRC}/admin/tablesort.js \
		${WRKSRC}/admin/xcache.css \
		${WRKSRC}/admin/xcache.php \
		${WRKSRC}/admin/xcache.tpl.php \
		${EXAMPLESDIR}/admin
.if defined(WITH_COVERAGER)
	@${MKDIR} ${EXAMPLESDIR}/coverager
	${INSTALL_DATA} ${WRKSRC}/coverager/config.php.example \
		${WRKSRC}/coverager/coverager.css \
		${WRKSRC}/coverager/coverager.php \
		${WRKSRC}/coverager/coverager.tpl.php \
		${WRKSRC}/coverager/index.php \
		${EXAMPLESDIR}/coverager
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
