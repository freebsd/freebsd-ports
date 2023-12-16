PORTNAME=	examples
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	misc
MASTER_SITES=	QT/official_releases/qt/${QT6_VERSION:R}/${QT6_VERSION}/single
PKGNAMEPREFIX=	qt6-
DISTNAME=	qt-everywhere-src-${QT6_VERSION}
DIST_SUBDIR=	KDE/Qt/${QT6_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 examples source code
WWW=		https://www.qt.io/

NO_ARCH=	yes
NO_BUILD=	yes

USES=		qt:6 tar:xz
USE_QT=		#

EXAMPLESDIR=	${PREFIX}/share/examples/qt6

_QT_DISTS=	3d 5compat activeqt base charts coap connectivity datavis3d \
		declarative doc graphs httpserver mqtt multimedia networkauth \
		opcua positioning quick3d quick3dphysics remoteobjects scxml \
		sensors serialbus serialport speech tools virtualkeyboard \
		wayland webchannel webengine websockets webview
EXAMPLES=	${_QT_DISTS:C/^/qt/}

.for example in ${EXAMPLES}
EXTRACT_AFTER_ARGS+=	${DISTNAME:S/-opensource//}/${example}/examples
.endfor
EXTRACT_AFTER_ARGS+=	${DISTNAME:S/-opensource//}/qtsvg/tests/manual/examples

do-install:
.for example in ${EXAMPLES}
	cd ${WRKSRC}/${example}/examples && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/svg
	cd ${WRKSRC}/qtsvg/tests/manual/examples && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}/svg

.include <bsd.port.mk>
