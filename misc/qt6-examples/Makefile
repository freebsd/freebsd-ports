PORTNAME=	examples
PORTVERSION=	${QT6_VERSION}
CATEGORIES=	misc
MASTER_SITES=	QT/official_releases/qt/${QT6_VERSION:R}/${QT6_VERSION}/single
PKGNAMEPREFIX=	qt6-
DISTNAME=	qt-everywhere-src-${QT6_VERSION}
#WRKSRC=		${WRKDIR}/qt-everywhere-src-${QT5_VERSION}
DIST_SUBDIR=	KDE/Qt/${QT6_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 examples sourcecode

NO_ARCH=	yes
NO_BUILD=	yes

USES=		qt:6 tar:xz
USE_QT=		#

EXAMPLESDIR=	${PREFIX}/share/examples/qt6
# The destination location depends on the values given in
# share/doc/qt5/<module>/examples-manifest.xml. The exception is
# qtscript and qtserialbus where the examples are looked up in $EXAMPLESDIR/.
# This way, the examples show up in qtcreator on the examples front page.

_QT_DISTS=	3d 5compat activeqt base charts coap connectivity datavis3d \
		declarative doc httpserver mqtt multimedia networkauth opcua \
		positioning quick3d quick3dphysics remoteobjects scxml \
		sensors serialbus serialport speech svg tools virtualkeyboard \
		wayland webchannel webengine websockets webview
EXAMPLES=		${_QT_DISTS:C/^/qt/}

.for example in ${EXAMPLES}
EXTRACT_AFTER_ARGS+=	${DISTNAME:S/-opensource//}/${example}/examples
.endfor

do-install:
.for example in ${EXAMPLES}
	cd ${WRKSRC}/${example}/examples && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
