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
COMMENT=	A program to montior loss in multicast sessions

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

WANT_AUTOCONF_VER=253
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
MAN1=		rtpmon.1
PLIST_FILES=	bin/rtpmon

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

pre-configure:
	@cd ${WRKSRC}; ${CHMOD} +w configure; ${AUTOCONF}

post-install:
	${STRIP_CMD} ${PREFIX}/bin/rtpmon

.include <bsd.port.post.mk>
