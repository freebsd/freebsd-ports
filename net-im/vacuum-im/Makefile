# New ports collection makefile for:	vacuum-im
# Date created:		2009-12-09
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	vacuum
PORTVERSION=	1.2.0
CATEGORIES=	net-im
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-im

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Crossplatform Jabber client

LICENSE=	GPLv3

PROJECTHOST=	${PORTNAME}${PKGNAMESUFFIX}

USE_XZ=	yes
USE_CMAKE=	yes
USE_XORG=	xscrnsaver
USE_LDCONFIG=	yes
USE_QT4=	gui xml qmake_build uic_build moc_build rcc_build \
		network linguist_build webkit
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="Vacuum-IM" "Modular, crossplatform Jabber client" \
		"${PREFIX}/share/pixmaps/vacuum.png" "${PORTNAME}" \
		"Qt;Network;InstantMessaging;" false

.include <bsd.port.mk>
