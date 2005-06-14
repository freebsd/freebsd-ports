# New ports collection makefile for:	xmms-eq-skins
# Date created:			13 Jun 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	xmms-eq-skins
PORTVERSION=	0.2
CATEGORIES=	x11-themes
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	equ
DISTNAME=	eq-xmms-skins-${PORTVERSION}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Additional skins for the XMMS EQ plugin

RUN_DEPENDS=	${X11BASE}/lib/xmms/Effect/libeq.so:${PORTSDIR}/audio/xmms-eq

USE_BZIP2=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/EQskins
NO_BUILD=	yes

SKINSDIR=	${PREFIX}/lib/xmms/EQskins
PLIST_SUB=	SKINSDIR="${SKINSDIR:S,^${PREFIX}/,,}"

do-install:
	${MKDIR} ${SKINSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.tgz ${SKINSDIR}

.include <bsd.port.mk>
