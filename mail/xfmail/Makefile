# New ports collection makefile for:	xfmail
# Version required:	0.3
# Date created:		01 October 1995
# Whom:			gena
#
# $Id: Makefile,v 1.1.1.1 1995/10/03 01:20:06 jkh Exp $
#

DISTNAME=	xfmail
PKGNAME=	xfmail-0.3b
CATEGORIES+=	mail x11
MASTER_SITES=	ftp://burka.netvision.net.il/pub/xfmail/work/

MAINTAINER=	gena@NetVision.net.il

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		forms\\.0\\.:${PORTSDIR}/x11/xforms

USE_X11=	yes
WRKSRC=		${WRKDIR}/xfmail/ui

pre-configure:
	@(cd ${WRKSRC} ; cp Makefile.FreeBSD Makefile)

.include <bsd.port.mk>
