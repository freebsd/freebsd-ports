# New ports collection makefile for:	rtpmon
# Date created:				1 November 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rtpmon
PORTVERSION=	1.0a7
PORTREVISION=	1
CATEGORIES=	mbone tk83
MASTER_SITES=	ftp://mm-ftp.cs.berkeley.edu/pub/rtpmon/

MAINTAINER=	fenner@FreeBSD.org

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83
BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
MAN1=		rtpmon.1

pre-configure:
	@cd ${WRKSRC}; ${CHMOD} +w configure; autoconf

post-install:
	strip ${PREFIX}/bin/rtpmon

.include <bsd.port.mk>
