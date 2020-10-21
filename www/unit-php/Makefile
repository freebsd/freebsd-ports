# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

COMMENT=	PHP module for NGINX Unit

PLIST_FILES=	libexec/unit/modules/php${PHP_VER}.unit.so

RUN_DEPENDS=	unitd:www/unit

USES=		php:build,embed,flavors

USE_RC_SUBR=	# reset to empty

MASTERDIR=	${.CURDIR}/../unit

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
	./configure php --lib-path=${LOCALBASE}/lib \
			--module=php${PHP_VER}

do-build:
	cd ${CONFIGURE_WRKSRC} && ${MAKE} php${PHP_VER}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/php${PHP_VER}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

.include "${MASTERDIR}/Makefile"
