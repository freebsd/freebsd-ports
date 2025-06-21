PORTREVISION=	0
CATEGORIES=	textproc gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python interface for XML parser library for GNOME
MASTERDIR=	${.CURDIR}/../libxml2

DEPRECATED=	Python bindings are planned to be deprecated upstream, consider migrating to another project such as lxml

USES+=		gnome python shebangfix
USE_GNOME=	libxml2
USE_PYTHON=	flavors
SHEBANG_FILES=	doc/*.py python/*.py python/tests/*.py

# Tell master port we're a slave port
LIBXML2_SLAVE=	python

DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

OPTIONS_EXCLUDE=	${OPTIONS_DEFINE}

do-install:
		${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
		${INSTALL_SCRIPT} ${WRKSRC}/python/drv_libxml2.py ${STAGEDIR}${PYTHON_SITELIBDIR}
		${INSTALL_SCRIPT} ${BUILD_WRKSRC}/libxml2.py ${STAGEDIR}${PYTHON_SITELIBDIR}
		${INSTALL_LIB} ${BUILD_WRKSRC}/libxml2mod.so ${STAGEDIR}${PYTHON_SITELIBDIR}

.include "${MASTERDIR}/Makefile"
