# New ports collection makefile for:   ntop
# Version required:    1.1
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

DISTNAME=	ntop-1.1-src
PKGNAME=	ntop-1.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.unipi.it/pub/local/ntop/source/ \
		http://www.freenix.no/~anders/ \
		ftp://totem.fix.no/pub/mirrors/misc/

MAINTAINER=	billf@FreeBSD.org

HAS_CONFIGURE=	yes
ALL_TARGET=
INSTALL_TARGET=	install install-man
WRKSRC=		${WRKDIR}/${PKGNAME}

MAN8=		ntop.8

post-install:
	strip ${PREFIX}/sbin/ntop

.include <bsd.port.mk>
