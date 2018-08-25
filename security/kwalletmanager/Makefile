# $FreeBSD$

PORTNAME=	kwalletmanager
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Password manager for KDE

USES=		cmake:outsource desktop-file-utils gettext kde:5 qt:5 tar:xz
USE_KDE=	archive auth codecs config configwidgets coreaddons crash \
		dbusaddons doctools ecm emoticons i18n iconthemes init \
		itemmodels itemviews kcmutils kdelibs4support kio \
		jobwidgets notifications service wallet widgetsaddons \
		windowsystem xmlgui
USE_QT=		core dbus gui network widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
