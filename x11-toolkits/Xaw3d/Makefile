# New ports collection makefile for:	Xaw3d
# Version required:	1.2a
# Date created:		18 November 1994
# Whom:			asami
#
# $Id: Makefile,v 1.9 1995/08/25 06:53:19 asami Exp $
#

DISTNAME=	Xaw3d-1.2a
CATEGORIES+=	x11
MASTER_SITES=	ftp://crl.dec.com/pub/X11/contrib/widgets/Xaw3d/R6/

MAINTAINER=	asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
USE_IMAKE=	yes

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
