PORTNAME=	khelpcenter
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 application to show KDE application documentation
WWW=		https://projects.kde.org/projects/kde/workspace/khelpcenter

LIB_DEPENDS=	libxapian.so:databases/xapian-core

USES=		cmake compiler:c++11-lib desktop-file-utils gettext gnome \
		kde:6 python:env,run qt:6 shebangfix tar:xz xorg
USE_GNOME=	libxml2
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons dbusaddons i18n itemmodels itemviews jobwidgets \
		kcmutils kio parts service solid sonnet texttemplate \
		textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
# This port depends on doctools; we need the entities and such for runtime
# documentation support, where all the other KDE Plasma parts need it
# only for the build-time documentation-generation.
USE_KDE+=	doctools
USE_QT=		base webengine
USE_XORG=	x11
SHEBANG_FILES=	searchhandlers/khc_mansearch.py

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
