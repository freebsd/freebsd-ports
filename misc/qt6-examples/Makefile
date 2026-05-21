PORTNAME=	examples
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	misc
MASTER_SITES=	QT/${_QT6_RELEASE_TYPE}_releases/qt/${QT6_VERSION:R}/${QT6_VERSION}/single
PKGNAMEPREFIX=	qt6-
DISTNAME=	qt-everywhere-src-${QT6_VERSION}
DIST_SUBDIR=	KDE/Qt/${QT6_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 examples source code
WWW=		https://www.qt.io/

LICENSE=	BSD3CLAUSE

USES=		qt:6 tar:xz
USE_QT=		#

# Add all qt modules with examples, whether or not they are relevant to FreeBBSD.
_QT_DISTS=	3d 5compat activeqt base canvaspainter charts coap \
		connectivity datavis3d declarative doc graphs httpserver mqtt \
		multimedia networkauth opcua openapi positioning quick3d \
		quick3dphysics remoteobjects scxml sensors serialbus \
		serialport speech tasktree tools virtualkeyboard wayland \
		webchannel webengine websockets webview
_QT_EXAMPLES=	${_QT_DISTS:C/^/qt/}

EXAMPLESDIR=	${PREFIX}/share/examples/qt6

.for example in ${_QT_EXAMPLES}
EXTRACT_AFTER_ARGS+=	${DISTNAME:S/-opensource//}/${example}/examples
.endfor
EXTRACT_AFTER_ARGS+=	${DISTNAME:S/-opensource//}/qtsvg/tests/manual/examples

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
.for example in ${_QT_EXAMPLES}
	cd ${WRKSRC}/${example}/examples && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/svg
	cd ${WRKSRC}/qtsvg/tests/manual/examples && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/svg

.include <bsd.port.mk>
