# New ports collection makefile for:	wbd
# Date created:		11 May 2001
# Whom:			assar
#
# $FreeBSD$
#

PORTNAME=	wbd
PORTVERSION=	1.0u4
CATEGORIES=	mbone
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/wbd/1.0ucl4/
DISTNAME=	wbd-1.0ucl4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A shared drawing (whiteboard) tool using multicast, compatible with wb

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

PLIST_FILES=	bin/wbd
WRKSRC=		${WRKDIR}/wbd
MAKEFILE=	makefile

.include <bsd.port.mk>
