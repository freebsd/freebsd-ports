# New ports collection makefile for:	xfmail
# http://Burka.NetVision.net.il/xfmail/xfmail.html
# Version required:     1.3
# Date created:		30 June 1996
# Whom:			gena
#
# $Id: Makefile,v 1.17 1998/12/07 20:46:39 billf Exp $
#

DISTNAME=       xfmail-1.3
CATEGORIES=     mail
MASTER_SITES=	ftp://burka.netvision.net.il/pub/xfmail/

MAINTAINER=	gena@NetVision.net.il

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		xforms.0:${PORTSDIR}/x11-toolkits/xforms

# depends on xforms
ONLY_FOR_ARCHS=	i386

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
MAN1=		xfmail.1

.include <bsd.port.mk>
