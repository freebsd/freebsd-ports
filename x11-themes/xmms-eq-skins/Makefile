# New ports collection makefile for:	xmms-eq-skins
# Date created:			13 Jun 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	xmms-eq-skins
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	x11-themes
MASTER_SITES=	SF/equ/eq-xmms-skins/${PORTVERSION}
DISTNAME=	eq-xmms-skins-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Additional skins for the XMMS EQ plugin

RUN_DEPENDS=	${LOCALBASE}/lib/xmms/Effect/libeq.so:${PORTSDIR}/audio/xmms-eq

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/EQskins
NO_BUILD=	yes

SKINSDIR=	${PREFIX}/lib/xmms/EQskins
PLIST_SUB=	SKINSDIR="${SKINSDIR:S,^${PREFIX}/,,}"

do-install:
	${MKDIR} ${SKINSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.tgz ${SKINSDIR}

.include <bsd.port.mk>
