# New ports collection makefile for:	FWF Widgets
# Version required:	3.8
# Date created:		14 July 1995
# Whom:			jkh
#
# $Id: Makefile,v 1.9 1997/01/06 12:14:26 jkh Exp $
#

DISTNAME=	fwf-3.8
CATEGORIES=	x11
MASTER_SITES=   ${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=     widgets

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/FWF
PATCH_STRIP=	-p1
XMKMF=		env X11BASE=${X11BASE} WRKSRC=${WRKSRC} sh ${FILESDIR}/xmkmf

.include <bsd.port.mk>
