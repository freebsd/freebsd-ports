# $FreeBSD$

PORTNAME=	xml
CATEGORIES=	textproc devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtXml module

BUILD_DEPENDS=	${PY_ENUM34}
RUN_DEPENDS=	${PY_ENUM34}

CONFIGURE_ARGS=	--enable QtXml
PYQT_DIST=	yes

USES=		python pyqt:5 qt:5
USE_PYQT=	sip_build core_run
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		core xml buildtools_build qmake_build

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtXml API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${PYQT_APIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5
DEBUG_CONFIGURE_ON=	--debug --trace

post-install:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-f -d ${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5

.include <bsd.port.mk>
