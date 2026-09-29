PORTNAME=	ruqola
MASTER_SITES=	KDE/stable/${PORTNAME}/
DISTVERSION=	2.5.3
PORTREVISION=	2
CATEGORIES=	net-im kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Rocket.Chat client
WWW=		https://apps.kde.org/ruqola/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake kde:6 gettext qt:6 tar:xz
USE_KDE=	archive codecs colorscheme config coreaddons crash \
		dbusaddons i18n iconthemes idletime itemviews kio \
		ktextaddons notifications notifyconfig prison purpose \
		sonnet statusnotifieritem syntaxhighlighting \
		textwidgets userfeedback xmlgui \
		doctools:build ecm:build
USE_QT=		base multimedia networkauth \
		websockets
# KDE Plasma
USE_KDE+=	activities

CMAKE_OFF=	OPTION_DISABLE_NETWORKMANAGER

PLIST_SUB=	SO_VER=${DISTVERSION}

.include <bsd.port.mk>
