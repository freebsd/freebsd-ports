# New ports collection makefile for:	FWF Widgets
# Version required:	3.8
# Date created:		14 July 1995
# Whom:			jkh
#
# $Id: Makefile,v 1.8 1996/11/18 11:42:32 asami Exp $
#

DISTNAME=	fwf-3.8
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.let.rug.nl/pub/FWF/

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/FWF
PATCH_STRIP=	-p1
XMKMF=		env X11BASE=${X11BASE} WRKSRC=${WRKSRC} sh ${FILESDIR}/xmkmf

.include <bsd.port.mk>
