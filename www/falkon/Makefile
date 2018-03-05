# $FreeBSD$

PORTNAME=	falkon
DISTVERSION=	3.0.0
CATEGORIES=	www
MASTER_SITES=	KDE/stable/falkon/${DISTVERSION:R}/src/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Web browser based on WebKit engine and Qt Framework

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource desktop-file-utils kde:5 ssl tar:xz
USE_KDE=	wallet
USE_QT5=	core dbus gui location network printsupport qml quick \
		sql webchannel webengine widgets x11extras \
		buildtools_build qmake_build
USE_XORG=	xcb

USE_LDCONFIG=	yes

.include <bsd.port.mk>
