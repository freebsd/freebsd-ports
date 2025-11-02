PORTNAME=	fcitx5-configtool
DISTVERSION=	5.1.11
CATEGORIES=	textproc x11
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Fcitx5 IM framework configuration tool
WWW=		https://github.com/fcitx/fcitx5-configtool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

qt5_PKGNAMESUFFIX=	-qt5
qt6_PKGNAMESUFFIX=	-qt6

LIB_DEPENDS=	libFcitx5Core.so:textproc/fcitx5 \
		libFcitx5Qt6DBusAddons.so:textproc/fcitx5-qt@qt6 \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		xkeyboard-config>=0:x11/xkeyboard-config

USES=		cmake compiler:c++17-lang gettext-tools gl \
		kde:6 pkgconfig qt:6 \
		tar:zst xorg
USE_GL=		opengl

PLIST_SUB=	VER=${PORTVERSION}

LIB_DEPENDS+=	libKF6Svg.so:graphics/kf6-ksvg \
		libKF6KCMUtilsQuick.so:devel/kf6-kcmutils
USE_KDE=	config coreaddons ecm i18n iconthemes itemviews \
		kdeclarative kirigami2 libplasma package service \
		widgetsaddons
USE_QT=		base declarative
CMAKE_OFF=	ENABLE_TEST

USE_XORG=	x11 xkbfile
USE_LDCONFIG=	yes

CMAKE_ON=	ENABLE_CONFIG_QT ENABLE_KCM

.include <bsd.port.mk>
