# New ports collection makefile for:	xfmail
# http://Burka.NetVision.net.il/xfmail/xfmail.html
# Version required:     1.3
# Date created:		30 June 1996
# Whom:			gena
#
# $Id: Makefile,v 1.15 1998/09/17 00:32:45 asami Exp $
#

DISTNAME=       xfmail-1.3
CATEGORIES=     mail
MASTER_SITES=	ftp://burka.netvision.net.il/pub/xfmail/

MAINTAINER=	gena@NetVision.net.il

BROKEN_ELF=	xforms is a.out only

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		xforms.0:${PORTSDIR}/x11-toolkits/xforms

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
MAN1=		xfmail.1

.include <bsd.port.mk>
