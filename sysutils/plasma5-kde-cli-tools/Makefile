PORTNAME=	kde-cli-tools
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 non-interactive system tools
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib cpe desktop-file-utils gettext kde:5 \
		qt:5 tar:xz xorg
USE_KDE=	activities auth bookmarks codecs completion config \
		configwidgets coreaddons crash emoticons guiaddons i18n \
		iconthemes init itemmodels itemviews jobwidgets kcmutils \
		kdeclarative kdesu kio notifications parts plasma-workspace \
		pty service solid sonnet textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus declarative gui network printsupport svg \
		widgets x11extras xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11
CPE_VENDOR=	kde

.include <bsd.port.mk>
