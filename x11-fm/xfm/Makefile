# New ports collection makefile for:	xfm
# Date created:		28 December 1994
# Whom:			jc@irbs.com John Capo
#
# $FreeBSD$
#

PORTNAME=	xfm
PORTVERSION=	1.4.2.4
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/
MASTER_SITE_SUBDIR=	applications
DISTNAME=	${PORTNAME}-1.4.2p4

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d

WRKSRC=		${WRKDIR}/${PORTNAME}-1.4.2

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		xfm.1 xfmtype.1

.include <bsd.port.mk>
