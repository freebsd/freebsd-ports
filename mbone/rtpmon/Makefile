# New ports collection makefile for:	rtpmon
# Version required:			1.0a5
# Date created:				1 November 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.ORG>
#
#   $Id: Makefile,v 1.1.1.1 1996/11/10 21:10:46 fenner Exp $
#

DISTNAME=	rtpmon-1.0a5
CATEGORIES=	mbone
MASTER_SITES=	ftp://mm-ftp.cs.berkeley.edu/pub/rtpmon/

MAINTAINER=	fenner@FreeBSD.org

LIB_DEPENDS=	tk41\\.1:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
USE_X11=	yes
MAN1=		rtpmon.1

post-install:
	strip ${PREFIX}/bin/rtpmon

.include <bsd.port.mk>
