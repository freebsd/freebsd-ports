# Created by: Alex Dupre <sysadmin@alexdupre.com>
# $FreeBSD$

PORTNAME=	screw
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	SF/${PORTNAME}/OldFiles
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTNAME=	php_screw-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP script encryption tool

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CRYPTKEY?=	11152, 368, 192, 1281, 62

USES=		php:phpize libtool
USE_PHP=	zlib
PLIST_SUB=	PHP_EXTDIR="${PHP_EXT_DIR}"
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--enable-php_screw=shared

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "To achieve real security, define your own encryption"
	@${ECHO_CMD} "seed key (CRYPTKEY); longer is better."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "make CRYPTKEY=\"234, 84, 39664, 771, 9853\""
	@${ECHO_CMD} ""

post-patch:
	@${ECHO_CMD} "short pm9screw_mycryptkey[] = { ${CRYPTKEY} };" > \
		${WRKSRC}/my_screw.h

do-build:
	(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
	(cd ${BUILD_WRKSRC}/tools && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_LIB} ${WRKSRC}/modules/php_screw.so \
		${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/tools/screw ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/php
	@${ECHO_CMD} "extension=${PREFIX}/lib/php/${PHP_EXT_DIR}/php_screw.so" > \
		${STAGEDIR}${PREFIX}/etc/php/ext-30-screw.ini

.include <bsd.port.mk>
