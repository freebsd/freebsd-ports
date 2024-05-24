PORTREVISION=	1
CATEGORIES=	textproc gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python interface for XML parser library for GNOME

USES+=		gnome python shebangfix
USE_GNOME=	libxml2
USE_PYTHON=	flavors
SHEBANG_FILES=	*.py doc/*.py python/*.py python/tests/*.py

# Help CMake determine the correct version of Python if
# multiple versions are installed
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD}

MASTERDIR=	${.CURDIR}/../libxml2

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

OPTIONS_EXCLUDE=	${OPTIONS_DEFINE}

# Tell master port we're a slave port
LIBXML2_SLAVE=	python

do-install:
		${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
		${INSTALL_SCRIPT} ${WRKSRC}/python/drv_libxml2.py ${STAGEDIR}${PYTHON_SITELIBDIR}
		${INSTALL_SCRIPT} ${BUILD_WRKSRC}/libxml2.py ${STAGEDIR}${PYTHON_SITELIBDIR}
		${INSTALL_LIB} ${BUILD_WRKSRC}/libxml2mod.so ${STAGEDIR}${PYTHON_SITELIBDIR}

.include "${MASTERDIR}/Makefile"
