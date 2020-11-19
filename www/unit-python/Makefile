# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-${UNIT_MODNAME}

UNIT_MODNAME=	python${PYTHON_SUFFIX}

COMMENT=	Python module for NGINX Unit

USES=		python gettext-runtime
USE_PYTHON=	flavors

PLIST_FILES=	libexec/unit/modules/${UNIT_MODNAME}.unit.so

RUN_DEPENDS=	unitd:www/unit

USE_RC_SUBR?=	# reset to empty

MASTERDIR=	${.CURDIR}/../unit

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
	${CONFIGURE_CMD} python --module=${UNIT_MODNAME} \
			--config=${PYTHON_CMD}-config

do-build:
	cd ${CONFIGURE_WRKSRC} && ${MAKE} ${UNIT_MODNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/${UNIT_MODNAME}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

.include "${MASTERDIR}/Makefile"
