# New ports collection makefile for:   ntop
# Version required:    1.1a3
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.6 1998/11/17 21:36:13 billf Exp $
#

DISTNAME=	ntop-1.1a3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.unipi.it/pub/local/ntop/snapshots/ \
		ftp://ftp.ee.lbl.gov/ \
		http://www.FreeBSD.org/~billf/
DISTFILES=	libpcap-0.4.tar.Z ${DISTNAME}.tar.gz

MAINTAINER=	billf@FreeBSD.org

USE_AUTOCONF=	yes
ALL_TARGET=
INSTALL_TARGET=	install

MAN8=		ntop.8

post-patch:
	@cd ${WRKDIR}/libpcap-0.4/; ./configure; make

post-install:
	strip ${PREFIX}/sbin/ntop

.include <bsd.port.mk>
