PKGNAMESUFFIX=	-${UNIT_MODNAME}

UNIT_MODNAME=	python${PYTHON_SUFFIX}

COMMENT=	Python module for NGINX Unit

USES=		python:3.10-3.11 gettext-runtime
USE_PYTHON=	flavors

PLIST_FILES=	libexec/unit/modules/${UNIT_MODNAME}.unit.so

RUN_DEPENDS=	unitd:www/unit

USE_RC_SUBR?=	# reset to empty

MASTERDIR=	${.CURDIR}/../unit

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} python \
		--module=${UNIT_MODNAME} \
		--config=${PYTHON_CMD}-config

do-build:
	cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
			${MAKEFILE} ${MAKE_ARGS} ${UNIT_MODNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/lib/unit/modules/${UNIT_MODNAME}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

.include "${MASTERDIR}/Makefile"
