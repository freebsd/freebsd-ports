# New ports collection makefile for:	FWF Widgets
# Version required:	3.8
# Date created:		14 July 1995
# Whom:			jkh
#
# $Id: Makefile,v 1.4 1995/07/17 16:22:21 jkh Exp $
#

DISTNAME=	fwf-3.8
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.let.rug.nl/pub/FWF/

MAINTAINER=	jkh@FreeBSD.ORG

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/FWF
PATCH_STRIP=	-p1
XMKMF=		env X11BASE=${X11BASE} WRKSRC=${WRKSRC} ${FILESDIR}/xmkmf

.include <bsd.port.mk>
