# New ports collection makefile for:   ntop
# Version required:    1.1
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.7 1998/11/18 11:31:43 asami Exp $
#

DISTNAME=	ntop-1.1-src
PKGNAME=	ntop-1.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.unipi.it/pub/local/ntop/source/ \
		ftp://ftp.ee.lbl.gov/ \
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
