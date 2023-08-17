PORTNAME=	kirigami2
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-toolkits kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QtQuick based components set

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	kdeclarative \
		ecm:build
USE_QT=		core concurrent dbus declarative graphicaleffects gui \
		linguisttools network quickcontrols2 svg widgets \
		buildtools:build qmake:build testlib:build

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1300016
# src/imagecolors.cpp:317:9: error: statement after '#pragma omp parallel for'
# must be a for loop
CFLAGS+=	-fopenmp-version=50
.endif

.include <bsd.port.post.mk>
