# $FreeBSD$

PORTNAME=	user-manager
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 user manager

LIB_DEPENDS=	libpwquality.so:security/libpwquality
RUN_DEPENDS=	accountsservice>=0:sysutils/accountsservice

USES=		cmake compiler:c++11-lib cpe gettext \
		kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash ecm emoticons guiaddons i18n iconthemes \
		init itemmodels itemviews jobwidgets kcmutils kdelibs4support \
		kio notifications parts service solid sonnet textwidgets \
		unitconversion widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network printsupport widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	${QT_PLUGINDIR}

.include <bsd.port.mk>
