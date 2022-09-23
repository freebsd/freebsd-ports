PORTNAME=	sweeper
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cleans temporal files for KDE
WWW=		https://utils.kde.org/projects/sweeper/

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	activities-stats auth bookmarks codecs config configwidgets \
		coreaddons crash i18n kio service sonnet textwidgets \
		widgetsaddons xmlgui
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
