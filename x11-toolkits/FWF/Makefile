# New ports collection makefile for:	FWF Widgets
# Version required:	4.0
# Date created:		14 July 1995
# Whom:			jkh
#
# $Id: Makefile,v 1.16 1998/12/22 07:51:27 asami Exp $
#

DISTNAME=	fwf-4.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SUNSITE}	\
		ftp://ftp.let.rug.nl/pub/FWF/
MASTER_SITE_SUBDIR=libs/X/fwf

MAINTAINER=	jseger@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/FWF
XMKMF=		env X11BASE=${X11BASE} WRKSRC=${WRKSRC} sh ${FILESDIR}/xmkmf

.include <bsd.port.mk>
