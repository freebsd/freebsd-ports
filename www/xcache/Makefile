# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xcache
DISTVERSION=	3.2.0
CATEGORIES=	www
MASTER_SITES=	http://xcache.lighttpd.net/pub/Releases/${DISTVERSION}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Fast and stable php opcode cacher

LICENSE=	BSD3CLAUSE

USES=		php:phpize tar:bzip2

IGNORE_WITH_PHP=	70 71 72

CONFIGURE_ARGS=	--enable-xcache=shared

OPTIONS_DEFINE=	CONSTANT COVERAGER EXAMPLES
CONSTANT_DESC=	Enable handling of compile time constants
COVERAGER_DESC=	Enable code coverage dumper

SUB_FILES=	pkg-message

PLIST_FILES=	lib/php/%%PHP_EXT_DIR%%/xcache.so

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
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_DATA} ${WRKSRC}/modules/${PORTNAME}.so \
	       ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xcache.ini \
		${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} htdocs \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
