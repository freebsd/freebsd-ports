# Created by: Alex Dupre <sysadmin@alexdupre.com>
# $FreeBSD$

PORTNAME=	php-screw
PORTVERSION=	1.5
CATEGORIES=	www security
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	php_screw-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP script encryption tool

CRYPTKEY?=	11152, 368, 192, 1281, 62

USES=		php:phpize libtool
USE_PHP=	zlib
PLIST_SUB=	PHP_EXTDIR="${PHP_EXT_DIR}"
SUB_FILES=	pkg-message

CONFIGURE_ARGS+=	--enable-php_screw=shared

pre-everything::
	@${ECHO} ""
	@${ECHO} "To achieve real security, define your own encryption"
	@${ECHO} "seed key (CRYPTKEY); longer is better."
	@${ECHO} ""
	@${ECHO} "make CRYPTKEY=\"234, 84, 39664, 771, 9853\""
	@${ECHO} ""

post-patch:
	@${ECHO} "short pm9screw_mycryptkey[] = { ${CRYPTKEY} };" > \
		${WRKSRC}/my_screw.h

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	@(cd ${BUILD_WRKSRC}/tools; ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/php_screw.so \
		${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/tools/screw ${STAGEDIR}${PREFIX}/bin
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/php_screw.so

.include <bsd.port.mk>
