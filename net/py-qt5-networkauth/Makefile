PORTNAME=	networkauth
DISTVERSION=	${PYQTNETWORKAUTH_VERSION}
CATEGORIES=	net devel python
MASTER_SITES=	${MASTER_SITES_PYQTNETWORKAUTH}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTNETWORKAUTH_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtNetworkAuth module
WWW=		https://riverbankcomputing.com/software/pyqt

LICENSE=	${PYQT5_LICENSE}

USES=		pyqt:5,dist python qt:5
USE_PYQT=	pyqt5 qtbuilder:build sip:build
USE_PYTHON=	concurrent flavors
USE_QT=		core network networkauth \
		qmake:build

PLIST_SUB=	PYQTNETWORKAUTH_VERSION=${DISTVERSION}

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		-name '*.so*' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
