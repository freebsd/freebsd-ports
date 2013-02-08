# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xcache
DISTVERSION=	3.0.1-rc1
CATEGORIES=	www
MASTER_SITES=	http://xcache.lighttpd.net/pub/Releases/${DISTVERSION}/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A fast and stable php opcode cacher

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_PHP=	yes
USE_PHPIZE=	yes

CONFIGURE_ARGS=	--enable-xcache=shared

OPTIONS_DEFINE=	CONSTANT COVERAGER
CONSTANT_DESC=	Enable handling of compile time constants
COVERAGER_DESC=	Enable code coverage dumper

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

PLIST_FILES=	lib/php/%%PHP_EXT_DIR%%/xcache.so
PLIST_DIRSTRY=	lib/php/%%PHP_EXT_DIR%%

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCONSTANT}
CONFIGURE_ARGS+=--enable-xcache-constant
.endif

.if ${PORT_OPTIONS:MCOVERAGER}
CONFIGURE_ARGS+=--enable-xcache-coverager
PLIST_SUB+=	COVERAGER=""
.else
PLIST_SUB+=	COVERAGER="@comment "
.endif

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_DATA} ${WRKSRC}/modules/${PORTNAME}.so \
	       ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xcache.ini \
		${EXAMPLESDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} htdocs ${EXAMPLESDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
