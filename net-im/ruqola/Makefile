PORTNAME=	ruqola
MASTER_SITES=	KDE/stable/${PORTNAME}/
DISTVERSION=	2.5.2
CATEGORIES=	net-im kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Rocket.Chat client
WWW=		https://apps.kde.org/ruqola/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake compiler:c++11-lang kde:6 gettext localbase:ldflags qt:6 tar:xz xorg
USE_KDE=	archive auth bookmarks codecs colorscheme completion config configwidgets \
		coreaddons crash dbusaddons guiaddons i18n iconthemes idletime itemviews \
		jobwidgets kio ktextaddons notifications notifyconfig \
		prison purpose service solid sonnet statusnotifieritem syntaxhighlighting \
		textwidgets widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		base multimedia networkauth \
		websockets
USE_XORG=	x11

PLIST_SUB=	SO_VER=${DISTVERSION}

.include <bsd.port.mk>
