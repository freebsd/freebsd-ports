# New ports collection makefile for:	rtpmon
# Version required:			1.0a7
# Date created:				1 November 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.ORG>
#
#   $Id: Makefile,v 1.7 1998/08/05 09:31:32 asami Exp $
#

DISTNAME=	rtpmon-1.0a7
CATEGORIES=	mbone tk42
MASTER_SITES=	ftp://mm-ftp.cs.berkeley.edu/pub/rtpmon/

MAINTAINER=	fenner@FreeBSD.org

LIB_DEPENDS=	tk42\\.1:${PORTSDIR}/x11-toolkits/tk42
BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
MAN1=		rtpmon.1

pre-configure:
	@cd ${WRKSRC}; autoconf

post-install:
	strip ${PREFIX}/bin/rtpmon

.include <bsd.port.mk>
