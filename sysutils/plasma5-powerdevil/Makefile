# $FreeBSD$

PORTNAME=	powerdevil
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 tool to manage the power consumption settings

RUN_DEPENDS=	${LOCALBASE}/libexec/upowerd:sysutils/upower

USES=		cmake compiler:c++11-lib cpe gettext kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	activities auth bookmarks codecs completion configwidgets \
		coreaddons crash config dbusaddons ecm emoticons globalaccel \
		guiaddons i18n idletime iconthemes init itemmodels itemviews \
		jobwidgets kdelibs4support kio libkscreen notifications \
		notifyconfig parts plasma-workspace service solid sonnet \
		textwidgets unitconversion wayland widgetsaddons windowsystem \
		xmlgui
USE_QT=		core dbus gui network printsupport widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	xcb

.include <bsd.port.mk>
