# New ports collection makefile for:   ntop
# Version required:    1.1a3
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.5 1998/11/12 15:21:53 billf Exp $
#

DISTNAME=
PKGNAME=	ntop-1.1a3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.unipi.it/pub/local/ntop/snapshots/ \
		ftp://ftp.ee.lbl.gov/ \
		http://www.FreeBSD.org/~billf/
DISTFILES=	libpcap-0.4.tar.Z ${NTOPDISTFILE}.tar.gz

MAINTAINER=	billf@FreeBSD.org

NTOPDISTFILE=	ntop-1.1a3
WRKSRC=		${WRKDIR}/${NTOPDISTFILE}
USE_AUTOCONF=	yes
ALL_TARGET=
INSTALL_TARGET=	install

MAN8=		ntop.8

post-patch:
	@cd ${WRKDIR}/libpcap-0.4/; ./configure; make

post-install:
	strip ${PREFIX}/sbin/ntop

.include <bsd.port.mk>
