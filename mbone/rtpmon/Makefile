# New ports collection makefile for:	rtpmon
# Version required:			1.0a7
# Date created:				1 November 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.ORG>
#
#   $Id: Makefile,v 1.3 1997/04/20 13:19:24 wosch Exp $
#

DISTNAME=	rtpmon-1.0a7
CATEGORIES=	mbone tk41
MASTER_SITES=	ftp://mm-ftp.cs.berkeley.edu/pub/rtpmon/

MAINTAINER=	fenner@FreeBSD.org

LIB_DEPENDS=	tk41\\.1:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
USE_X11=	yes
MAN1=		rtpmon.1

post-install:
	strip ${PREFIX}/bin/rtpmon

.include <bsd.port.mk>
