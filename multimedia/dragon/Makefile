PORTNAME=	dragon
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	multimedia kde kde-applications
PKGNAMESUFFIX=	-player

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE multimedia player with a focus on simplicity
WWW=		https://www.kde.org/applications/multimedia/dragonplayer/

LICENSE=	GPLv2

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:6 \
		qt:6 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons doctools i18n iconthemes jobwidgets kio \
		notifications parts phonon service solid sonnet textwidgets \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

CONFLICTS_INSTALL=	dragon # bin/dragon

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
