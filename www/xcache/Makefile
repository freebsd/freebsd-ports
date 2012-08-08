# New ports collection makefile for:	xcache
# Date created:			28 May 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xcache
DISTVERSION=	2.0.1
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

ADMINFILES=	common-en.lang.php common-zh-simplified-utf-8.lang.php \
		common-zh-traditional-utf-8.lang.php common.php config.default.php \
		config.example.php edit.php edit.tpl.php footer.tpl.php header.tpl.php \
		help-en.lang.php help-zh-simplified-utf-8.lang.php \
		help-zh-traditional-utf-8.lang.php help.php index.php \
		mkpassword.php tablesort.js xcache.css xcache.php xcache.tpl.php

COVERAGERFILES=	common-en.lang.php common-zh-simplified-gb2312.lang.php \
		common-zh-simplified-utf-8.lang.php common.php config.php.example \
		coverager.css coverager.php coverager.tpl.php index.php

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
.for f in ${ADMINFILES}
	${INSTALL_DATA} ${WRKSRC}/admin/${f} ${EXAMPLESDIR}/admin
.endfor
.if defined(WITH_COVERAGER)
	@${MKDIR} ${EXAMPLESDIR}/coverager
.for f in ${COVERAGERFILES}
	${INSTALL_DATA} ${WRKSRC}/coverager/${f} ${EXAMPLESDIR}/coverager
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
