# New ports collection makefile for:   ntop
# Version required:    0.2.2
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id$
#

DISTNAME=	ntop-0.4-src
PKGNAME=	ntop-0.4
CATEGORIES=	net
MASTER_SITES=	http://jake.unipi.it/~deri/ntop/

MAINTAINER=	billf@chc-chimes.com

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_AUTOCONF=	yes
ALL_TARGET=

post-install:
	strip ${PREFIX}/sbin/ntop

.include <bsd.port.mk>
