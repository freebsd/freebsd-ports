# New ports collection makefile for:	xfmail
# Version required:	0.4
# Date created:		30 June 1996
# Whom:			gena
#
# $Id: Makefile,v 1.4 1995/11/22 04:57:00 asami Exp $
#

DISTNAME=	xfmail
PKGNAME=	xfmail-0.4
CATEGORIES+=	mail x11
MASTER_SITES=	ftp://burka.netvision.net.il/pub/xfmail/

MAINTAINER=	gena@NetVision.net.il

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		xforms\\.0\\.:${PORTSDIR}/x11/xforms

USE_X11=	yes
WRKSRC=		${WRKDIR}/xfmail/ui

pre-configure:
	@(cd ${WRKSRC} ; cp Makefile.FreeBSD Makefile)

.include <bsd.port.mk>
