# $FreeBSD$

PORTNAME=	webkit
PORTREVISION=	1
CATEGORIES=	www devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtWebKit module

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:devel/py-sip@${FLAVOR}
RUN_DEPENDS=	${PKGNAMEPREFIX}gui>=${PYQT5_VERSION}:x11-toolkits/py-qt5-gui@${FLAVOR}

CONFIGURE_ARGS=	--enable QtWebKit
PYQT_DIST=	yes

USES=		python pyqt:5
USE_GL=		gl
USE_PYQT=	sip_build core_run gui_run network_run
USE_PYTHON=	flavors
USE_QT5=	core gui network webkit qmake_build

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtWebKit API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${QSCIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2-qt5.so:devel/qscintilla2-qt5
DEBUG_CONFIGURE_ON=	--debug --trace

.include <bsd.port.mk>
