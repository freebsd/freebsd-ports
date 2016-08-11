# Created by: Ralf Nolden <nolden@kde.org>
# $FreeBSD$

PORTNAME=	examples
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	misc
MASTER_SITES=	QT/official_releases/qt/${QT5_VERSION:R}/${QT5_VERSION}/single/
PKGNAMEPREFIX=	qt5-
DISTNAME=	qt-everywhere-opensource-src-${QT5_VERSION}
DIST_SUBDIR=	KDE/Qt/${QT5_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 examples sourcecodes

NO_ARCH=	yes
NO_BUILD=	yes

USES=		tar:xz
USE_QT5=	#

DESCR=		${.CURDIR:H:H}/devel/qt5/pkg-descr

EXAMPLESDIR=	${PREFIX}/share/examples/qt5
# The destination location depends on the values given in
# share/doc/qt5/<module>/examples-manifest.xml. The exception is
# qtscript and qtserialbus where the examples are looked up in $EXAMPLESDIR/.
# This way, the examples show up in qtcreator on the examples front page.

EXAMPLES=	qt3d qtbase qtcanvas3d qtconnectivity qtdeclarative qtenginio \
		qtlocation qtmultimedia qtquickcontrols qtscript qtsensors \
		qtserialport qtsvg qttools qtwebchannel qtwebkit-examples \
		qtwebsockets qtxmlpatterns

.for example in ${EXAMPLES}
EXTRACT_AFTER_ARGS+=	${DISTNAME}/${example}/examples
.endfor

do-install:
.for example in ${EXAMPLES}
	cd ${WRKSRC}/${example}/examples && \
	${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
