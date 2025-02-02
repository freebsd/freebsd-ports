PORTNAME=	kbackup
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	sysutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Backup program with an easy to use user interface
WWW=		https://utils.kde.org/projects/kbackup/

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		qt:6 shared-mime-info tar:xz xorg
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons guiaddons i18n iconthemes itemviews jobwidgets kio \
		notifications service solid statusnotifieritem widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
