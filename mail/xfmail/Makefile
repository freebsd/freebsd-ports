# New ports collection makefile for:	xfmail
# http://Burka.NetVision.net.il/xfmail/xfmail.html
# Version required:     1.2
# Date created:		30 June 1996
# Whom:			gena
#
# $Id: Makefile,v 1.9 1997/06/22 10:46:33 andreas Exp $
#

DISTNAME=       xfmail-1.2
CATEGORIES=     x11 mail
MASTER_SITES=	ftp://burka.netvision.net.il/pub/xfmail/

MAINTAINER=	gena@NetVision.net.il

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		xforms\\.0\\.88:${PORTSDIR}/x11/xforms

USE_X11=	yes
GNU_CONFIGURE=	yes
MAN1=		xfmail.1

.include <bsd.port.mk>
