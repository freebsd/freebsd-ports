PORTNAME=	networkauth
PORTVERSION=	${PYQTNETWORKAUTH_VERSION}
CATEGORIES=	net devel python
MASTER_SITES=	${MASTER_SITES_PYQTNETWORKAUTH}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTNETWORKAUTH_DISTNAME}

PYQT_DIST=	yes

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtNetworkAuth module

BUILD_DEPENDS=	qmake-qt5:devel/qt5-qmake
LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5

USES=		gl pyqt:5 python:3.8+ qt:5
USE_GL=		gl
USE_PYQT=	sip_build pyqt5
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		core gui network networkauth

.include <bsd.port.mk>
