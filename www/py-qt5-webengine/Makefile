PORTNAME=	webengine
DISTVERSION=	${PYQTWEBENGINE_VERSION}
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITES_PYQTWEBENGINE}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTWEBENGINE_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtWebEngine module
WWW=		https://riverbankcomputing.com/software/pyqt

LICENSE=	${PYQT5_LICENSE}

USES=		gl pyqt:5,dist python qt:5
USE_GL=		gl
USE_PYQT=	pyqt5 qtbuilder:build sip:build
USE_PYTHON=	concurrent flavors
USE_QT=		core declarative gui location network printsupport webchannel \
		webengine widgets qmake:build

PLIST_SUB=	PYQT_WEBENGINE_VERSION=${DISTVERSION}

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		-name '*.so*' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
