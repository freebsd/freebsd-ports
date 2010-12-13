# New ports collection makefile for:	nmapsi4
# Date created:		2009-10-30
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	nmapsi4
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-alpha3

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	GUI frontend for the nmap scanning utility

RUN_DEPENDS=	${LOCALBASE}/bin/nmap:${PORTSDIR}/security/nmap

BROKEN=		does not compile

USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui xml qmake_build uic_build moc_build rcc_build network linguist

post-install:
	${CHMOD} 755 ${PREFIX}/bin/${PORTNAME}
	${CHMOD} 755 ${PREFIX}/bin/${PORTNAME}-logr

.include <bsd.port.mk>
