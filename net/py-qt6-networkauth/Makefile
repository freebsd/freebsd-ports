PORTNAME=	networkauth
DISTVERSION=	${PYQTNETWORKAUTH_VERSION}
CATEGORIES=	net devel python
MASTER_SITES=	${MASTER_SITES_PYQTNETWORKAUTH}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTNETWORKAUTH_DISTNAME}

PYQT_DIST=	yes

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt6 toolkit, QtNetworkAuth module
WWW=		https://riverbankcomputing.com/software/pyqt

BUILD_DEPENDS=	${PY_SETUPTOOLS}

USES=		gl pyqt:6 python qt:6
USE_GL=		opengl
USE_PYQT=	sip:build pyqt6 qtbuilder
USE_PYTHON=	concurrent flavors
USE_QT=		base networkauth

PLIST_SUB=	PYQTNETWORKAUTH_VERSION=${DISTVERSION}

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt6 \
		-name '*.so*' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
