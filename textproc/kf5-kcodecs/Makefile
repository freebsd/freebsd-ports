# $FreeBSD$

PORTNAME=	kcodecs
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	textproc kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library for string manipulation

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		cmake compiler:c++11-lib gperf kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		buildtools_build core linguisttools qmake_build

.include <bsd.port.mk>
