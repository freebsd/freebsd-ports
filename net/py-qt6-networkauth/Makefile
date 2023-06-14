PORTNAME=	networkauth
PORTVERSION=	${PYQTNETWORKAUTH_VERSION}
PORTREVISION=	2
CATEGORIES=	net devel python
MASTER_SITES=	${MASTER_SITES_PYQTNETWORKAUTH}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTNETWORKAUTH_DISTNAME}

PYQT_DIST=	yes

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt6 toolkit, QtNetworkAuth module
WWW=		https://riverbankcomputing.com/software/pyqt

LIB_DEPENDS=	libqscintilla2_qt6.so:devel/qscintilla2-qt6

USES=		gl pyqt:6 python qt:6
USE_GL=		gl
USE_PYQT=	sip:build pyqt6 qtbuilder
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		base networkauth

.include <bsd.port.mk>
