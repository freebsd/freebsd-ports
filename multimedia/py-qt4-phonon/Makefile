# $FreeBSD$

PORTNAME=	phonon
PORTREVISION=	1
CATEGORIES=	multimedia devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, Phonon module

CONFIGURE_ARGS=	--enable phonon
PYQT_DIST=	yes

USES=		python pyqt:4
USE_PYQT=	sip_build core_run gui_run
USE_PYTHON=	flavors
USE_QT4=	corelib gui phonon moc_build qmake_build

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install Phonon API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${QSCIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2_qt4.so:devel/qscintilla2
DEBUG_CONFIGURE_ON=	--debug --trace

.include <bsd.port.mk>
