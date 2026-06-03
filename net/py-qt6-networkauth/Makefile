PORTNAME=	networkauth
DISTVERSION=	${PYQTNETWORKAUTH_VERSION}
CATEGORIES=	net devel python
MASTER_SITES=	${MASTER_SITES_PYQTNETWORKAUTH}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTNETWORKAUTH_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt6 toolkit, QtNetworkAuth module
WWW=		https://riverbankcomputing.com/software/pyqt

LICENSE=	${PYQT6_LICENSE}

USES=		gl pyqt:6,dist python qt:6
USE_GL=		opengl
USE_PYQT=	pyqt6 qtbuilder:build sip:build
USE_PYTHON=	concurrent flavors
USE_QT=		base networkauth

PLIST_SUB=	PYQTNETWORKAUTH_VERSION=${DISTVERSION}

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt6 \
		-name '*.so*' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
