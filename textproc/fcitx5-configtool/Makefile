PORTNAME=	fcitx5-configtool
DISTVERSION=	5.1.6
CATEGORIES=	textproc x11
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Fcitx5 IM framework configuration tool
WWW=		https://github.com/fcitx/fcitx5-configtool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

BUILD_DEPENDS=	fcitx5-qt5>=5.0.2:textproc/fcitx5-qt@qt5 \
		fcitx5>=5.0.10:textproc/fcitx5 \
		iso-codes>=0:misc/iso-codes
LIB_DEPENDS=	libFcitx5Core.so:textproc/fcitx5 \
		libFcitx5Qt5DBusAddons.so:textproc/fcitx5-qt \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		xkeyboard-config>=0:x11/xkeyboard-config

USES=		cmake compiler:c++17-lang gettext-tools kde:5 pkgconfig qt:5 \
		tar:zst xorg

PLIST_SUB=	VER=${PORTVERSION}

USE_KDE=	config coreaddons ecm i18n iconthemes itemviews \
		kdeclarative kirigami2 package plasma-framework service \
		widgetsaddons
USE_QT=		concurrent core dbus declarative gui widgets \
		x11extras buildtools:build qmake:build
USE_XORG=	x11 xkbfile
USE_LDCONFIG=	yes

CMAKE_ON=	ENABLE_CONFIG_QT ENABLE_KCM
CMAKE_OFF=	ENABLE_TEST USE_QT6

.include <bsd.port.mk>
