# New ports collection makefile for:   ntop
# Version required:    0.2.2
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.2 1998/08/11 09:57:51 andreas Exp $
#

DISTNAME=	ntop-0.4-src
PKGNAME=	ntop-0.4
CATEGORIES=	net
MASTER_SITES=	http://jake.unipi.it/~deri/ntop/

MAINTAINER=	billf@chc-chimes.com

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_AUTOCONF=	yes
ALL_TARGET=
INSTALL_TARGET=	install install-man
CFLAGS+=	-D__dead=

MAN8=		ntop.8

post-install:
	strip ${PREFIX}/sbin/ntop

.include <bsd.port.mk>
