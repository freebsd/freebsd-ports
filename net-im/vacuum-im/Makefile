# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vacuum
PORTVERSION=	1.2.5
CATEGORIES=	net-im
PKGNAMESUFFIX=	-im

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Crossplatform Jabber client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	Vacuum-IM
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}

USES=		cmake
USE_XORG=	xscrnsaver
USE_LDCONFIG=	yes
USE_QT4=	gui xml qmake_build uic_build moc_build rcc_build \
		network linguist_build webkit

PORTDOCS=	AUTHORS CHANGELOG COPYING README TRANSLATORS

DESKTOP_ENTRIES="Vacuum-IM" "Modular, crossplatform Jabber client" \
		"${PREFIX}/share/pixmaps/vacuum.png" "${PORTNAME}" \
		"Qt;Network;InstantMessaging;" false

.include <bsd.port.mk>
