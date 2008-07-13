# New ports collection makefile for:	rtpmon
# Date created:				1 November 1996
# Whom:	      Bill Fenner <fenner@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rtpmon
PORTVERSION=	1.0a7
PORTREVISION=	5
CATEGORIES=	mbone tk
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to monitor loss in multicast sessions

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

DEPRECATED=	abandoned upstream, needs gcc32 which is going to be removed
EXPIRATION_DATE=2008-08-15

USE_AUTOTOOLS=	autoconf:261:env
GNU_CONFIGURE=	yes
USE_GCC=	3.2
MAN1=		rtpmon.1
PLIST_FILES=	bin/rtpmon

.include <bsd.port.pre.mk>

pre-configure:
	@cd ${WRKSRC}; ${CHMOD} +w configure; ${AUTOCONF}

post-install:
	${STRIP_CMD} ${PREFIX}/bin/rtpmon

.include <bsd.port.post.mk>
