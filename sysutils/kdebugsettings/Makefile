PORTNAME=	kdebugsettings
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE application to enable/disable qCDebug
WWW=		https://projects.kde.org/projects/kde/kdeutils/kdebugsettings

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	completion config configwidgets coreaddons dbusaddons \
		guiaddons i18n iconthemes itemviews kio widgetsaddons \
		ecm:build
USE_QT=		core dbus gui testlib widgets \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
