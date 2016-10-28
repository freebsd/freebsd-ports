# Created by: Marie Loise Nolden <nolden@kde.org>
# $FreeBSD$

PORTNAME=	doc
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	misc
MASTER_SITES=	QT/official_releases/qt/${QT5_VERSION:R}/${QT5_VERSION}/single
PKGNAMEPREFIX=	qt5-
DISTNAME=	qt-everywhere-opensource-src-${QT5_VERSION}
DIST_SUBDIR=	KDE/Qt/${QT5_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 documentation

USES=		gmake python:build qmake:norecursive,outsource tar:xz
USE_QT5=	buildtools_build concurrent_build help_build qdoc_build
QMAKE_SOURCE_PATH=	${WRKSRC}/qt.pro

ALL_TARGET=	docs
DESCR=		${.CURDIR:H:H}/devel/qt5/pkg-descr
NO_ARCH=	yes

# The default qconfig.pri that qmake reads comes from devel/qt5-core and thus
# disables a lot of items. We re-enable the most important ones below so that
# we do not end up without documentation for QtGui and QtWidgets.
QMAKE_ARGS=	QT_CONFIG-="no-gui no-widgets"

# We need to invoke the qmake symlink we create in the pre-configure target so
# that it reads the qt.conf installed alongside it.
_QMAKE=		${BUILD_WRKSRC}/qtbase/bin/qmake

SUB_FILES=	qt.conf
SUB_LIST=	BUILD_WRKSRC=${BUILD_WRKSRC} \
		QT_DOCDIR=${QT_DOCDIR}

pre-configure: apply-slist
	${MKDIR} ${BUILD_WRKSRC}/qtbase/bin
	${LN} -sf ${MOC} ${BUILD_WRKSRC}/qtbase/bin/moc
	${LN} -sf ${UIC} ${BUILD_WRKSRC}/qtbase/bin/uic
	${LN} -sf ${RCC} ${BUILD_WRKSRC}/qtbase/bin/rcc
	${LN} -sf ${QMAKE} ${BUILD_WRKSRC}/qtbase/bin/qmake
	${LN} -sf ${QT_BINDIR}/qdoc ${BUILD_WRKSRC}/qtbase/bin/qdoc
	${LN} -sf ${QT_BINDIR}/qhelpgenerator ${BUILD_WRKSRC}/qtbase/bin/qhelpgenerator
	${CP} -Rp ${QT_MKSPECDIR} ${BUILD_WRKSRC}/qtbase/mkspecs
	${CP} ${WRKDIR}/qt.conf ${BUILD_WRKSRC}/qtbase/bin/qt.conf

post-patch:
# qtdeclarative.pro wants to run python, replace that with PYTHON_CMD
	${REINPLACE_CMD} '/py_out/s#python#${PYTHON_CMD}#g' \
		${WRKSRC}/qtdeclarative/qtdeclarative.pro

do-install:
	${MKDIR} ${STAGEDIR}${QT_DOCDIR} && \
		cd ${BUILD_WRKSRC}/qtbase/doc && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${QT_DOCDIR}

.include <bsd.port.mk>
