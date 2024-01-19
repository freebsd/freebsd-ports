PORTREVISION=	0
CATEGORIES=	textproc gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python interface for XML parser library for GNOME
MASTERDIR=	${.CURDIR}/../libxml2

USES+=		gnome python shebangfix
USE_GNOME=	libxml2
USE_PYTHON=	flavors
SHEBANG_FILES=	*.py doc/*.py python/*.py python/tests/*.py

# Help CMake determine the correct version of Python if
# multiple versions are installed
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD}

OPTIONS_EXCLUDE=	${OPTIONS_DEFINE}

# Tell master port we're a slave port
LIBXML2_SLAVE=	python
# Grab pkg-descr from slave port
DESCR=		${.CURDIR}/pkg-descr

# Don't append pkg-plist from master port
PLIST=

PLIST_FILES=	${PYTHON_SITELIBDIR}/drv_libxml2.py \
		${PYTHON_SITELIBDIR}/libxml2.py \
		${PYTHON_SITELIBDIR}/libxml2mod.so

do-install:
		${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
		${INSTALL_SCRIPT} ${WRKSRC}/python/drv_libxml2.py ${STAGEDIR}${PYTHON_SITELIBDIR}
		${INSTALL_SCRIPT} ${BUILD_WRKSRC}/libxml2.py ${STAGEDIR}${PYTHON_SITELIBDIR}
		${INSTALL_LIB} ${BUILD_WRKSRC}/libxml2mod.so ${STAGEDIR}${PYTHON_SITELIBDIR}

.include "${MASTERDIR}/Makefile"
