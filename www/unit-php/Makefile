# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

COMMENT=	PHP module for NGINX Unit

PLIST_FILES=	libexec/unit/modules/php${PHP_VER}.unit.so

USES=		php:build,embed,flavors

USE_RC_SUBR=	# reset to empty

MASTERDIR=	${.CURDIR}/../unit

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
	./configure php --lib-path=${LOCALBASE}/lib \
			--module=php${PHP_VER}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/php${PHP_VER}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

.include "${MASTERDIR}/Makefile"
