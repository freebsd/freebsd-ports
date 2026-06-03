PORTNAME=	webengine
DISTVERSION=	${PYQTWEBENGINE_VERSION}
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITES_PYQTWEBENGINE}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTWEBENGINE_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt6 toolkit, QtWebEngine module
WWW=		https://riverbankcomputing.com/software/pyqt

USES=		gl pyqt:6,dist python qt:6
USE_GL=		opengl
USE_PYQT=	pyqt6 qtbuilder:build sip:build
USE_PYTHON=	concurrent flavors
USE_QT=		base declarative positioning webchannel webengine

PLIST_SUB=	PYQT_WEBENGINE_VERSION=${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|%%QT_INCDIR%%|${QT_INCDIR}|g' \
		${WRKSRC}/pyproject.toml

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt6 \
		-name '*.so*' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
