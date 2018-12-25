# $FreeBSD$

PORTNAME=	kdeedu-data
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE edu data files

USES=		cmake kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		buildtools_build qmake_build

# The qmake dependency is only needed so that kf5-e-c-m can query qmake for
# some installation directories.
# We explicitly prevent it from looking for qt5-core and specify qmake's path
# to avoid needlessly depending on qt5-core.
CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5Core=TRUE \
		-DQMAKE_EXECUTABLE:PATH=${QMAKE}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
