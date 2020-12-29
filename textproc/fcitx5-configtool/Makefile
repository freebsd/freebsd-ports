# Created by: Ka Ho Ng <khng300@gmail.com>
# $FreeBSD$

PORTNAME=	fcitx5-configtool
DISTVERSION=	5.0.1-20
CATEGORIES=	textproc x11

MAINTAINER=	khng300@gmail.com
COMMENT=	Fcitx5 IM framework configuration tool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon \
		libFcitx5Core.so:textproc/fcitx5 \
		libFcitx5Qt5DBusAddons.so:textproc/fcitx5-qt
RUN_DEPENDS=	xkeyboard-config>=0:x11/xkeyboard-config \
		iso-codes>=0:misc/iso-codes

USES=		compiler:c++17-lang gettext-tools cmake kde:5 pkgconfig qt:5 xorg

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx
GH_TAGNAME=	b4fbd81

USE_KDE=	ecm coreaddons kdeclarative i18n itemviews kirigami2 package widgetsaddons
USE_QT=		concurrent core gui quickcontrols2 widgets x11extras buildtools_build qmake_build
USE_XORG=	x11 xkbfile
USE_LDCONFIG=	yes

CMAKE_ON=	ENABLE_KCM ENABLE_CONFIG_QT
CMAKE_OFF=	ENABLE_TEST

.include <bsd.port.mk>
