# New ports collection makefile for:	xfmail
# Version required:	0.3
# Date created:		01 October 1995
# Whom:			gena
#
# $Id: $
#

DISTNAME=	xfmail
PKGNAME=	xfmail-0.3-beta
CATEGORIES+=	mail x11
MASTER_SITES=	ftp://burka.netvision.net.il/pub/xfmail/work/
WRKSRC=		${WRKDIR}/xfmail/ui

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		forms\\.0\\.:${PORTSDIR}/x11/xforms

PREFIX=		/usr/X11R6

MAINTAINER=	gena@NetVision.net.il

pre-configure:
	@(cd ${WRKSRC} ; cp Makefile.FreeBSD Makefile)

.include <bsd.port.mk>
