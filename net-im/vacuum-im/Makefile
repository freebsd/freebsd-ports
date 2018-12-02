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

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USE_GITHUB=	yes
GH_ACCOUNT=	Vacuum-IM
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}

USES=		cmake qt:4
USE_CXXSTD=	c++98
USE_XORG=	xscrnsaver
USE_LDCONFIG=	yes
USE_QT=		gui xml qmake_build uic_build moc_build rcc_build \
		network linguist_build webkit

PORTDOCS=	AUTHORS CHANGELOG COPYING README TRANSLATORS

DESKTOP_ENTRIES="Vacuum-IM" "Modular, crossplatform Jabber client" \
		"${PREFIX}/share/pixmaps/vacuum.png" "${PORTNAME}" \
		"Qt;Network;InstantMessaging;" false

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
