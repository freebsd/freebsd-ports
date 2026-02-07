PORTNAME=	adwaita-qt
DISTVERSION=	1.4.2
CATEGORIES=	x11-themes
PKGNAMESUFFIX=	${_qt_version}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adwaita theme for Qt applications
WWW=		https://github.com/MartinBriza/adwaita-qt

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

BUILD_DEPENDS=	sassc:textproc/sassc

USES=		cmake compiler:c++11-lib localbase pkgconfig qt:${_qt_version} \
		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	FedoraQt
USE_QT=		${_qt${_qt_version}_use}
USE_XORG=	xcb
CMAKE_ARGS=	-DUSE_QT6=${_qt${_qt_version}_qt6_on}

PLIST_SUB=	${_qt${_qt_version}_plist_sub} \
		PORTVERSION=${PORTVERSION}

# Handle Qt 5 and Qt 6
_qt_version?=	5
_qt5_qt6_on=	OFF
_qt6_qt6_on=	ON
_qt5_use=	core dbus gui widgets x11extras \
		buildtools:build qmake:build
_qt6_use=	base
_qt5_plist_sub=	QT_VERSION_SUFFIX=
_qt6_plist_sub=	QT_VERSION_SUFFIX=6

.include <bsd.port.mk>
