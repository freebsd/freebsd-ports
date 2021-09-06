PORTNAME=	powerdevil
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 tool to manage the power consumption settings

LIB_DEPENDS=	libudev.so:devel/libudev-devd
RUN_DEPENDS=	${LOCALBASE}/libexec/upowerd:sysutils/upower

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig qt:5 \
		tar:xz xorg
USE_KDE=	activities auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons emoticons \
		globalaccel guiaddons i18n iconthemes idletime init itemmodels \
		itemviews jobwidgets kio libkscreen notifications notifyconfig \
		parts plasma-workspace service solid sonnet textwidgets \
		unitconversion wayland widgetsaddons windowsystem xmlgui \
		doctools_build ecm_build
USE_QT=		concurrent core dbus gui network printsupport widgets \
		x11extras xml \
		buildtools_build qmake_build
USE_XORG=	xcb

.include <bsd.port.mk>
