# New ports collection makefile for:	xfmail
# http://Burka.NetVision.net.il/xfmail/xfmail.html
# Version required:     1.0
# Date created:		30 June 1996
# Whom:			gena
#
# $Id: Makefile,v 1.7 1996/11/17 07:42:58 obrien Exp $
#

DISTNAME=       xfmail-1.0
CATEGORIES=     mail
MASTER_SITES=	ftp://burka.netvision.net.il/pub/xfmail/

MAINTAINER=	gena@NetVision.net.il

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		xforms\\.0\\.:${PORTSDIR}/x11/xforms

WRKSRC=		${WRKDIR}/xfmail/ui
USE_X11=	yes

pre-configure:
	@(cd ${WRKSRC} ; ${CP} Makefile.FreeBSD Makefile)

.include <bsd.port.mk>
