PORTNAME=	kde-cli-tools
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 non-interactive system tools
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib cpe desktop-file-utils gettext kde:5 \
		qt:5 tar:xz xorg
USE_KDE=	activities auth codecs completion config configwidgets \
		coreaddons i18n iconthemes init jobwidgets kcmutils kdesu kio \
		parts plasma-workspace pty service solid sonnet textwidgets \
		widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus gui network svg widgets x11extras xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11
CPE_VENDOR=	kde

.include <bsd.port.mk>
