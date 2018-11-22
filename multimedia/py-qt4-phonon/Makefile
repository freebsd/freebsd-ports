# $FreeBSD$

PORTNAME=	phonon
PORTREVISION=	5
CATEGORIES=	multimedia devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, Phonon module

CONFIGURE_ARGS=	--enable phonon
PYQT_DIST=	yes

USES=		python pyqt:4 qt:4
USE_PYQT=	sip_build core_run gui_run
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		corelib gui phonon moc_build qmake_build

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install Phonon API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${PYQT_APIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2_qt4.so:devel/qscintilla2
DEBUG_CONFIGURE_ON=	--debug --trace

.include <bsd.port.mk>
