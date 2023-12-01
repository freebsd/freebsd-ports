PORTNAME=	webengine
DISTVERSION=	${PYQTWEBENGINE_VERSION}
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITES_PYQTWEBENGINE}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTWEBENGINE_DISTNAME}

PYQT_DIST=	yes

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt6 toolkit, QtWebEngine module
WWW=		https://riverbankcomputing.com/software/pyqt

USES=		gl python pyqt:6 qt:6
USE_GL=		gl
USE_PYQT=	sip:build pyqt6
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
