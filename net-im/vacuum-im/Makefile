# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vacuum
PORTVERSION=	1.2.2
CATEGORIES=	net-im
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-im

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Crossplatform Jabber client

LICENSE=	GPLv3

PROJECTHOST=	${PORTNAME}${PKGNAMESUFFIX}

USE_XZ=	yes
USES=		cmake
USE_XORG=	xscrnsaver
USE_LDCONFIG=	yes
USE_QT4=	gui xml qmake_build uic_build moc_build rcc_build \
		network linguist_build webkit
MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS CHANGELOG COPYING README TRANSLATORS

DESKTOP_ENTRIES="Vacuum-IM" "Modular, crossplatform Jabber client" \
		"${PREFIX}/share/pixmaps/vacuum.png" "${PORTNAME}" \
		"Qt;Network;InstantMessaging;" false

.include <bsd.port.mk>
