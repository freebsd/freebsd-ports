# $FreeBSD$

PORTNAME=	oxygen-icons5
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11-themes kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The Oxygen icon theme for KDE

USES=		cmake:outsource kde:5 tar:xz
USE_KDE=	ecm_build  # We only install icons.

# The qmake dependency is only needed so that kf5-e-c-m can query qmake for
# some installation directories.
# We explicitly prevent it from looking for qt5-core and specify qmake's path
# to avoid needlessly depending on qt5-core; we're just installing a ton of
# icon files and do not even use the paths queried from qmake.
USE_QT5=	qmake_build
CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Core=TRUE \
		-DQMAKE_EXECUTABLE:PATH=${QMAKE}

NO_ARCH=	yes

CONFLICTS_INSTALL=	kde4-oxygen-icons-*

.include <bsd.port.mk>
