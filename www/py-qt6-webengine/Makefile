PORTNAME=	webengine
DISTVERSION=	${PYQTWEBENGINE_VERSION}
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITES_PYQTWEBENGINE}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTWEBENGINE_DISTNAME}

PYQT_DIST=	yes

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt6 toolkit, QtWebEngine module
WWW=		https://riverbankcomputing.com/software/pyqt

LICENSE=	GPLv3

USES=		gl python pyqt:6 qt:6
USE_GL=		gl
USE_PYQT=	sip:build pyqt6
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		base declarative positioning webchannel webengine

PLIST_SUB=		PYQT_WEBENGINE_VERSION=${DISTVERSION}

.include <bsd.port.mk>
