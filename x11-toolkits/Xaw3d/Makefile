# New ports collection makefile for:	Xaw3d
# Version required:	1.3
# Date created:		18 November 1994
# Whom:			asami
#
# $Id: Makefile,v 1.10 1995/08/26 09:14:59 asami Exp $
#

DISTNAME=	Xaw3d-1.3
CATEGORIES+=	x11
MASTER_SITES=	ftp://crl.dec.com/pub/X11/contrib/widgets/Xaw3d/R6.1/

MAINTAINER=	asami@FreeBSD.ORG

WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
USE_IMAKE=	yes

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
