# New ports collection makefile for:	rtpmon
# Version required:			1.0a5
# Date created:				1 November 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.ORG>
#
#   $Id$
#

DISTNAME=	rtpmon-1.0a5
CATEGORIES+=	mbone
MASTER_SITES=	ftp://mm-ftp.cs.berkeley.edu/pub/rtpmon/

MAINTAINER=	fenner@FreeBSD.org

LIB_DEPENDS=	tk41\\.1:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
USE_X11=	yes

post-install:
	strip ${PREFIX}/bin/rtpmon
	${COMPRESS_MAN} ${PREFIX}/man/man1/rtpmon.1

.include <bsd.port.mk>
