# New ports collection makefile for:	xfmail
# Version required:	0.4
# Date created:		30 June 1996
# Whom:			gena
#
# $Id: Makefile,v 1.6 1996/11/10 21:32:49 obrien Exp $
#

DISTNAME=	xfmail
PKGNAME=	xfmail-0.4
CATEGORIES=	mail x11
MASTER_SITES=	ftp://burka.netvision.net.il/pub/xfmail/

MAINTAINER=	gena@NetVision.net.il

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		xforms\\.0\\.:${PORTSDIR}/x11/xforms

WRKSRC=		${WRKDIR}/xfmail/ui
USE_X11=	yes

pre-configure:
	@(cd ${WRKSRC} ; ${CP} Makefile.FreeBSD Makefile)

.include <bsd.port.mk>
