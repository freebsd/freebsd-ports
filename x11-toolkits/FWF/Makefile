# New ports collection makefile for:	FWF Widgets
# Date created:		14 July 1995
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	fwf
PORTVERSION=	4.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=libs/X/fwf

MAINTAINER=	jseger@FreeBSD.org

.if ${MACHINE_ARCH} == "alpha"
BROKEN=		../../lib/libfwf.a: cannot read symbols
.endif

USE_MOTIF=	yes
USE_IMAKE=	yes
USE_XPM=	yes
WRKSRC=		${WRKDIR}/FWF
XMKMF=		${SETENV} X11BASE=${X11BASE} WRKSRC=${WRKSRC} sh ${FILESDIR}/xmkmf

.include <bsd.port.mk>
