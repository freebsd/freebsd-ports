PORTNAME=	phonon
DISTVERSION=	4.12.0
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}
DIST_SUBDIR=	KDE/phonon
PKGNAMESUFFIX=	-designerplugin-qt6

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt Designer plugin for Phonon
WWW=		https://userbase.kde.org/Phonon

LICENSE=	LGPL21

USES=		cmake:insource compiler:c++11-lang kde:6 qt:6 tar:xz
USE_KDE=	phonon ecm:build
USE_QT=		5compat base tools
CMAKE_OFF=	PHONON_BUILD_QT5
CMAKE_ON=	PHONON_BUILD_QT6
PLIST_FILES=	${QT_PLUGINDIR_REL}/designer/phonon4qt6widgets.so

BUILD_WRKSRC=	${WRKSRC}/designer6
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DISTINFO_FILE=	${.CURDIR:H}/phonon/distinfo

.include <bsd.port.mk>
