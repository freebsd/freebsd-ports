PKGNAMESUFFIX=	-${FREEUNIT_MODNAME}

FREEUNIT_MODNAME=	python${PYTHON_SUFFIX}

COMMENT=	Python module for FreeUnit

RUN_DEPENDS=	unitd:www/freeunit

USES=		gettext-runtime python
USE_PYTHON=	flavors

USE_RC_SUBR=

MASTERDIR=	${.CURDIR}/../freeunit

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} python \
		--module=${FREEUNIT_MODNAME} \
		--config=${PYTHON_CMD}-config

do-build:
	cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
			${MAKEFILE} ${MAKE_ARGS} ${FREEUNIT_MODNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/lib/unit/modules/${FREEUNIT_MODNAME}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

.include "${MASTERDIR}/Makefile"
