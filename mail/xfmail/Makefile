# New ports collection makefile for:	xfmail
# http://Burka.NetVision.net.il/xfmail/xfmail.html
# Version required:     1.3
# Date created:		30 June 1996
# Whom:			gena
#
# $Id: Makefile,v 1.10 1998/01/10 18:36:55 jdp Exp $
#

DISTNAME=       xfmail-1.3
CATEGORIES=     mail
MASTER_SITES=	ftp://burka.netvision.net.il/pub/xfmail/

MAINTAINER=	gena@NetVision.net.il

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		xforms\\.0\\.88\\.1:${PORTSDIR}/x11/xforms

USE_X11=	yes
GNU_CONFIGURE=	yes
MAN1=		xfmail.1

.include <bsd.port.mk>
