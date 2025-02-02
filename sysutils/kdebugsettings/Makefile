PORTNAME=	kdebugsettings
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE application to enable/disable qCDebug
WWW=		https://projects.kde.org/projects/kde/kdeutils/kdebugsettings

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	completion config configwidgets coreaddons dbusaddons \
		guiaddons i18n iconthemes itemviews kio widgetsaddons xmlgui \
		ecm:build
USE_QT=		base

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
