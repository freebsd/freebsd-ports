PORTNAME=	syntax-highlighting
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	textproc kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 syntax highlighting engine for structured text and code

USES=		cmake compiler:c++11-lib kde:5 perl5 qt:5 tar:xz
USE_KDE=	ecm_build
USE_QT=		core gui network \
		buildtools_build linguisttools_build testlib_build qmake_build 

CMAKE_ARGS=	-DCMAKE_DISABLE_FIND_PACKAGE_Qt5XmlPatterns=TRUE

.include <bsd.port.mk>
