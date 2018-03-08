# $FreeBSD$

PORTNAME=		falkon
DISTVERSION=		3.0.0
CATEGORIES=		www

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Web browser based on the Qt Framework

LICENSE=			GPLv3
LICENSE_FILE=		${WRKSRC}/COPYING

USES=		cmake:outsource desktop-file-utils ssl kde:5
USE_KDE=	ecm_build
USE_QT5=	core dbus gui location network printsupport qml quick \
		sql webchannel webengine widgets x11extras \
		buildtools_build qmake_build
USE_XORG=	xcb

USE_LDCONFIG=	yes
USE_GITHUB=		yes
GH_ACCOUNT=	KDE
GH_TAGNAME=	0118c0cb966b2c15823945730a7aaa5b3dca545d

OPTIONS_DEFINE=	KWALLET
OPTIONS_SUB=	yes
KWALLET_DESC=	KDE5 Wallet Integration
KWALLET_USE=	kde=wallet

.include <bsd.port.mk>
