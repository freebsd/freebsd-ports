# New ports collection makefile for:	rtpmon
# Version required:			1.0a7
# Date created:				1 November 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.ORG>
#
#   $Id: Makefile,v 1.5 1997/09/25 00:10:58 fenner Exp $
#

DISTNAME=	rtpmon-1.0a7
CATEGORIES=	mbone tk42
MASTER_SITES=	ftp://mm-ftp.cs.berkeley.edu/pub/rtpmon/

MAINTAINER=	fenner@FreeBSD.org

LIB_DEPENDS=	tk42\\.1:${PORTSDIR}/x11/tk42
BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf

GNU_CONFIGURE=	yes
USE_X11=	yes
MAN1=		rtpmon.1

pre-configure:
	@cd ${WRKSRC}; autoconf

post-install:
	strip ${PREFIX}/bin/rtpmon

.include <bsd.port.mk>
