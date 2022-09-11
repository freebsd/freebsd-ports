PORTNAME=	kdf
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Shows free space of devices for KDE
WWW=		https://utils.kde.org/projects/kdf/

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons doctools \
		i18n iconthemes jobwidgets kcmutils kio notifications service solid \
		widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
