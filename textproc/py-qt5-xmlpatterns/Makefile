# $FreeBSD$

PORTNAME=	xmlpatterns
CATEGORIES=	textproc devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtXmlPatterns module

CONFIGURE_ARGS=	--enable QtXmlPatterns
PYQT_DIST=	yes

USES=		python:3.5+ pyqt:5 qt:5
USE_PYQT=	sip_build core_run network_run
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		core network xmlpatterns qmake_build

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtXmlPatterns API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${PYQT_APIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5
DEBUG_CONFIGURE_ON=	--debug --trace

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5/QtXmlPatterns.so

.include <bsd.port.mk>
