# $FreeBSD$

PORTNAME=		falkon
DISTVERSION=		2.1.99.20180209
CATEGORIES=		www

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Web browser based on the Qt Framework

LICENSE=			GPLv3
LICENSE_FILE=		${WRKSRC}/LICENSE

BUILD_DEPENDS=	kf5-extra-cmake-modules>=0:devel/kf5-extra-cmake-modules

USES=		cmake:outsource desktop-file-utils ssl
USE_QT5=	core dbus gui location network printsupport qml quick \
		sql webchannel webengine widgets x11extras \
		buildtools_build qmake_build
USE_XORG=	xcb

USE_LDCONFIG=	yes
USE_GITHUB=		yes
GH_ACCOUNT=	KDE
GH_TAGNAME=	31e4d5f

OPTIONS_DEFINE=	KWALLET
OPTIONS_SUB=	yes
KWALLET_DESC=	KDE5 Wallet Integration
KWALLET_USE=	kde=wallet
KWALLET_USES=	kde:5

CONFLICTS_INSTALL=	qupzilla-qt[45]*

.include <bsd.port.mk>
