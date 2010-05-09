# New ports collection makefile for:	vacuum-im
# Date created:		2009-12-09
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	vacuum
PORTVERSION=	1.0.1
CATEGORIES=	net-im
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-im
DISTNAME=	${PORTNAME}-${PORTVERSION}-source

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Crossplatform Jabber client

PROJECTHOST=	${PORTNAME}${PKGNAMESUFFIX}

USE_QT_VER=	4
USE_LDCONFIG=	yes
QT_COMPONENTS=	gui xml qmake_build uic_build moc_build rcc_build \
		network linguist_build webkit

DESKTOP_ENTRIES="Vacuum-IM" "Modular, crossplatform Jabber client" \
		"${DATADIR}/resources/menuicons/shared/mainwindowlogo96.png" "${PORTNAME}" \
		"Qt;Network;InstantMessaging;" ${FALSE}

QMAKEFLAGS+=	INSTALL_PREFIX="${PREFIX}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${PORTNAME}.pro

.include <bsd.port.mk>
