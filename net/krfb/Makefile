# $FreeBSD$

PORTNAME=	krfb
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	VNC server for KDE

LIB_DEPENDS=	libvncserver.so:net/libvncserver \
		libxcb-image.so:x11/xcb-util-image

USES=		alias cmake:outsource compiler:c++11-lib gettext jpeg \
		kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		crash dbusaddons dnssd doctools ecm i18n notifications \
		wallet widgetsaddons xmlgui
USE_QT=		core dbus gui network widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	x11 xcb xdamage xext xtst

OPTIONS_DEFINE=		TELEPATHY DOCS
OPTIONS_SUB=		yes
TELEPATHY_DESC=		Support for Telepathy Tubes
TELEPATHY_LIB_DEPENDS=	libtelepathy-qt5.so:net-im/telepathy-qt@qt5

.include <bsd.port.mk>
