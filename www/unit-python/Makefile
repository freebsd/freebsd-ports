# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2
PKGNAMESUFFIX=	-python${PYTHON_SUFFIX}

COMMENT=	Python module for NGINX Unit

USES=		python gettext-runtime
USE_PYTHON=	flavors

PLIST_FILES=	libexec/unit/modules/python${PYTHON_SUFFIX}.unit.so

RUN_DEPENDS=	unitd:www/unit

USE_RC_SUBR?=	# reset to empty

MASTERDIR=	${.CURDIR}/../unit

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
	./configure python --module=python${PYTHON_SUFFIX} \
			--config=${PYTHON_CMD}-config

do-build:
	cd ${CONFIGURE_WRKSRC} && ${MAKE} python${PYTHON_SUFFIX}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/python${PYTHON_SUFFIX}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

.include "${MASTERDIR}/Makefile"
