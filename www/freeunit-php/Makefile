PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

FREEUNIT_MODNAME=	php${PHP_VER}

COMMENT=	PHP module for FreeUnit

RUN_DEPENDS=	unitd:www/freeunit

USES=		php:build,embed,flavors

IGNORE_WITH_PHP=	82 86

USE_RC_SUBR=

MASTERDIR=	${.CURDIR}/../freeunit

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} php \
		--lib-path=${LOCALBASE}/lib \
		--module=${FREEUNIT_MODNAME}

do-build:
	cd ${CONFIGURE_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} ${FREEUNIT_MODNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/lib/unit/modules/${FREEUNIT_MODNAME}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

.include "${MASTERDIR}/Makefile"
