PORTNAME=	kwalletmanager
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Password manager for KDE

USES=		cmake compiler:c++11-lang desktop-file-utils gettext \
		kde:5 qt:5 tar:xz
USE_KDE=	archive auth codecs config configwidgets coreaddons crash \
		dbusaddons doctools emoticons i18n iconthemes init \
		itemmodels itemviews kcmutils kdelibs4support kio \
		jobwidgets notifications service wallet widgetsaddons \
		windowsystem xmlgui \
		ecm_build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
