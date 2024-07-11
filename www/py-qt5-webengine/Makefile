PORTNAME=	webengine
DISTVERSION=	${PYQTWEBENGINE_VERSION}
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITES_PYQTWEBENGINE}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTWEBENGINE_DISTNAME}

PYQT_DIST=	yes

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtWebEngine module
WWW=		https://riverbankcomputing.com/software/pyqt

LICENSE=	GPLv3

BUILD_DEPENDS=	${PY_SETUPTOOLS}

USES=		gl python pyqt:5 qt:5
USE_GL=		gl
USE_PYQT=	sip:build pyqt5
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		core declarative gui location network printsupport webchannel \
		webengine widgets qmake:build

PLIST_SUB=	PYQT_WEBENGINE_VERSION=${DISTVERSION}

.include <bsd.port.mk>
