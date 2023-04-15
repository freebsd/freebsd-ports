PORTNAME=	systemsettings
DISTVERSION=	${KDE_PLASMA_VERSION}.1
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 system settings
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib gettext gstreamer kde:5 qt:5 tar:xz \
		xorg
USE_GSTREAMER=	curl openh264 vpx
USE_KDE=	activities activities-stats auth codecs completion config \
		configwidgets coreaddons crash dbusaddons guiaddons i18n \
		iconthemes itemmodels itemviews jobwidgets js kcmutils \
		kdeclarative khtml kio kirigami2 notifications package parts \
		plasma-framework plasma-workspace runner service solid sonnet \
		textwidgets widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus declarative gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
