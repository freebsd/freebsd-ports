# New ports collection makefile for:   ntop
# Version required:    1.0
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.4 1998/11/12 00:01:32 billf Exp $
#

DISTNAME=	ntop-1.0.src
PKGNAME=	ntop-1.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.unipi.it/pub/local/ntop/source/

MAINTAINER=	billf@chc-chimes.com

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_AUTOCONF=	yes
ALL_TARGET=
INSTALL_TARGET=	install
CFLAGS+=	-D__dead=

MAN8=		ntop.8

post-extract:

	${CP} ${FILESDIR}/ethertype.h ${WRKSRC}
	${CP} ${FILESDIR}/gnuc.h ${WRKSRC}

post-install:
	strip ${PREFIX}/sbin/ntop

.include <bsd.port.mk>
