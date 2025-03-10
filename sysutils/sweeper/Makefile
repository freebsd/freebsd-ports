PORTNAME=	sweeper
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cleans temporal files for KDE
WWW=		https://utils.kde.org/projects/sweeper/

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	activities-stats auth bookmarks codecs config configwidgets \
		coreaddons crash i18n kio service sonnet textwidgets \
		widgetsaddons xmlgui \
		ecm:build
USE_QT=		base

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
