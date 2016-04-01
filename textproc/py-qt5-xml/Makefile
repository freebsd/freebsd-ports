# $FreeBSD$

PORTNAME=	xml
CATEGORIES=	textproc devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtXml module

CONFIGURE_ARGS=	--enable QtXml
PYQT_DIST=	yes

USES=		python pyqt:5
USE_PYQT=	sip_build core_run
USE_QT5=	core xml buildtools_build qmake_build

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtXml API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${QSCIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2-qt5.so:devel/qscintilla2-qt5
DEBUG_CONFIGURE_ON=	--debug --trace

.include <bsd.port.mk>
