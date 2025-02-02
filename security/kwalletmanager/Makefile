PORTNAME=	kwalletmanager
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Password manager for KDE
WWW=		https://utils.kde.org/projects/kwalletmanager/

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		qt:6 tar:xz xorg
USE_KDE=	archive auth codecs config configwidgets coreaddons crash \
		dbusaddons doctools i18n iconthemes itemmodels itemviews \
		jobwidgets kcmutils kio notifications service \
		statusnotifieritem wallet widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
