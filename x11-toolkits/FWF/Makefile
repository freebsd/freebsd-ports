# New ports collection makefile for:	FWF Widgets
# Version required:	3.8
# Date created:		14 July 1995
# Whom:			jkh
#
# $Id$
#

DISTNAME=	fwf-3.8
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.let.rug.nl/pub/FWF

MAINTAINER=	jkh@FreeBSD.ORG

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/FWF
PATCH_STRIP=	-p1
XMKMF=		env X11BASE=${X11BASE} WRKSRC=${WRKSRC} ${FILESDIR}/xmkmf
X_NO_MAKE_MAKEFILES=yes

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
