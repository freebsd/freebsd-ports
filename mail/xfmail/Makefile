# New ports collection makefile for:	xfmail
# Version required:	0.3
# Date created:		01 October 1995
# Whom:			gena
#
# $Id: Makefile,v 1.3 1995/10/05 12:36:18 asami Exp $
#

DISTNAME=	xfmail
PKGNAME=	xfmail-0.3
CATEGORIES+=	mail x11
MASTER_SITES=	ftp://burka.netvision.net.il/pub/xfmail/

MAINTAINER=	gena@NetVision.net.il

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		xforms\\.0\\.:${PORTSDIR}/x11/xforms

USE_X11=	yes
WRKSRC=		${WRKDIR}/xfmail-0.3/ui

pre-configure:
	@(cd ${WRKSRC} ; cp Makefile.FreeBSD Makefile)

.include <bsd.port.mk>
