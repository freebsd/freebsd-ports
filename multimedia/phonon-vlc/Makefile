PORTNAME=	phonon
DISTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTNAME}-backend-${PHONON_PLUGIN}/${DISTVERSION}
PKGNAMESUFFIX=	-${PHONON_PLUGIN}-${FLAVOR}
DISTNAME=	${PORTNAME}-backend-${PHONON_PLUGIN}-${DISTVERSION}
DIST_SUBDIR=	KDE/phonon

MAINTAINER=	kde@FreeBSD.org
COMMENT=	VLC backend for Phonon
WWW=		https://userbase.kde.org/Phonon

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

LIB_DEPENDS=	libvlc.so:multimedia/vlc

USES=		cmake compiler:c++11-lang kde:${FLAVOR:S/qt//} pkgconfig \
		qt:${FLAVOR:S/qt//} tar:xz
USE_KDE=	phonon ecm:build
USE_QT=		${_USE_QT_${FLAVOR}}

CMAKE_ON=	${_CMAKE_ON_${FLAVOR}}
CMAKE_OFF=	${_CMAKE_OFF_${FLAVOR}}

_CMAKE_ON_qt5=	PHONON_BUILD_QT5
_CMAKE_ON_qt6=	PHONON_BUILD_QT6
_CMAKE_OFF_qt5=	PHONON_BUILD_QT6
_CMAKE_OFF_qt6=	PHONON_BUILD_QT5

_USE_QT_qt5=	core gui widgets buildtools:build qmake:build
_USE_QT_qt6=	base 5compat tools

_QT5_ONLY_qt5=	#
_QT5_ONLY_qt6=	"@comment "
PLIST_SUB=	QT5_ONLY=${_QT5_ONLY_${FLAVOR}} \
		QT_VER=${FLAVOR:S/qt//} \

PHONON_PLUGIN=	vlc

.include <bsd.port.mk>
