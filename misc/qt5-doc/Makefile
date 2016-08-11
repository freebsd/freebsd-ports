# Created by: Ralf Nolden <nolden@kde.org>
# $FreeBSD$

PORTNAME=	doc
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	misc
MASTER_SITES=	QT/${QT5_BRANCH}/qt/${QT5_VERSION:R}/${QT5_VERSION}/${QT5_SUBDIR}
PKGNAMEPREFIX=	qt5-
DISTNAME=	qt-everywhere-opensource-src-${QT5_VERSION}
DIST_SUBDIR=	KDE/Qt/${QT5_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 documentation

NO_ARCH=	yes

USE_QT5=	help_build qdoc_build sql_build sql-sqlite3_build \
		buildtools_build qmake_build

USES=		compiler:c++11-lib python:build tar:xz

HAS_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
QT_NONSTANDARD=	yes
CONFIGURE_ARGS=	-opensource -confirm-license -developer-build -nomake tests

.include <bsd.port.pre.mk>
# If we are on a system without gcc make qmake use the internal freebsd-clang
# mkspec.
.if ${COMPILER_TYPE:Mclang}
CONFIGURE_ARGS+=	-platform unsupported/freebsd-clang
.endif

EXTRACT_AFTER_ARGS?=    ${DISTNAME:S,$,/qtwebkit,:S,^,--exclude ,} \
                                ${DISTNAME:S,$,/qtwebkit-examples,:S,^,--exclude ,} \
				${DISTNAME:S,$,/qtwebengine,:S,^,--exclude ,}

DOCSDIR=	${PREFIX}/share/doc/qt5

MAKE_JOBS_UNSAFE=	YES
ALL_TARGET=		docs

DESCR=		${.CURDIR:H:H}/devel/qt5/pkg-descr

post-extract:
	${MKDIR} ${BUILD_WRKSRC}/qtbase/bin
	${LN} -sf ${MOC} ${BUILD_WRKSRC}/qtbase/bin/moc
	${LN} -sf ${UIC} ${BUILD_WRKSRC}/qtbase/bin/uic
	${LN} -sf ${RCC} ${BUILD_WRKSRC}/qtbase/bin/rcc
	${LN} -sf ${QT_BINDIR}/qdoc ${BUILD_WRKSRC}/qtbase/bin/qdoc
	${LN} -sf ${QT_BINDIR}/qhelpgenerator ${BUILD_WRKSRC}/qtbase/bin/qhelpgenerator

post-patch:
# qtdeclarative.pro wants to run python, replace that with PYTHON_CMD
	${REINPLACE_CMD} '/py_out/s#python#${PYTHON_CMD}#g' \
		${WRKSRC}/qtdeclarative/qtdeclarative.pro
# Make mkspecs/freebsd-g++ use the correct gcc for the build.
.if ${COMPILER_TYPE:Mgcc}
	${REINPLACE_CMD} -e 's#gcc#${CC}#g' \
			 -e 's#g++#${CXX}#g' \
			 ${PATCH_WRKSRC}/qtbase/mkspecs/common/g++-base.conf
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
		cd ${BUILD_WRKSRC}/qtbase/doc && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
