# New ports collection makefile for:	xfmail
# http://Burka.NetVision.net.il/xfmail/xfmail.html
# Version required:     1.1
# Date created:		30 June 1996
# Whom:			gena
#
# $Id: Makefile,v 1.8 1997/01/10 04:59:16 ache Exp $
#

DISTNAME=       xfmail-1.1
CATEGORIES=     mail
MASTER_SITES=	ftp://burka.netvision.net.il/pub/xfmail/

MAINTAINER=	andreas@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		xforms\\.0\\.86:${PORTSDIR}/x11/xforms

WRKSRC=		${WRKDIR}/xfmail/ui
USE_X11=	yes

pre-configure:
	@(cd ${WRKSRC} ; ${CP} Makefile.FreeBSD Makefile)

.include <bsd.port.mk>
