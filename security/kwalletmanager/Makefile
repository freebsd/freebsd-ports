PORTNAME=	kwalletmanager
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Password manager for KDE
WWW=		https://utils.kde.org/projects/kwalletmanager/

USES=		cmake compiler:c++11-lang desktop-file-utils gettext \
		kde:5 qt:5 tar:xz xorg
USE_KDE=	archive auth codecs config configwidgets coreaddons crash \
		dbusaddons doctools emoticons i18n iconthemes init \
		itemmodels itemviews kcmutils kdelibs4support kio \
		jobwidgets notifications service wallet widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
