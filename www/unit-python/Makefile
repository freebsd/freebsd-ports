PKGNAMESUFFIX=	-${UNIT_MODNAME}

UNIT_MODNAME=	python${PYTHON_SUFFIX}

COMMENT=	Python module for NGINX Unit

USES=		python:3.7-3.10 gettext-runtime
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
	${INSTALL_LIB} ${WRKSRC}/build/${UNIT_MODNAME}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

# Overwrite the target in the ${MASTERDIR}/Makefile
post-install:
	@${DO_NADA}

.include "${MASTERDIR}/Makefile"
