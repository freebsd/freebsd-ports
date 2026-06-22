PORTNAME=	purpose
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	3
CATEGORIES=	misc kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Offers available actions for a specific purpose

DEPRECATED=	has its functionality stripped for coinstallability with Plasma 6

USES=		cmake compiler:c++11-lang gettext gnome \
		kde:5 pkgconfig qt:5 tar:xz xorg
USE_GNOME=	intltool
USE_KDE=	config completion coreaddons i18n kio \
		kirigami2 notifications jobwidgets prison service solid \
		widgetsaddons windowsystem \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
