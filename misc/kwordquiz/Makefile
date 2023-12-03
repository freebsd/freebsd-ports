PORTNAME=	kwordquiz
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	misc education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Flash card trainer for KDE Applications
WWW=		https://www.kde.org/applications/education/kwordquiz

BUILD_DEPENDS=	kirigami-addons>=0:x11-toolkits/kirigami-addons
RUN_DEPENDS=	kirigami-addons>=0:x11-toolkits/kirigami-addons

USES=		cmake compiler:c++11-lang desktop-file-utils gettext \
		kde:5 qt:5 tar:xz xorg
USE_KDE=	attica auth bookmarks codecs completion config configwidgets \
		coreaddons crash doctools emoticons guiaddons i18n \
		iconthemes init itemmodels itemviews jobwidgets kdeclarative \
		kdelibs4support kio libkeduvocdocument newstuff notifications \
		notifyconfig parts phonon service solid sonnet textwidgets \
		unitconversion widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		core dbus gui network multimedia printsupport widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
