# New ports collection makefile for:	tn3270
# Version required:	4.4BSD-Lite
# Date created:		30 August 1999
# Whom:			markm
#
# $FreeBSD$
#

DISTNAME=	tn3270
PKGNAME=	tn3270-4.4
CATEGORIES=	net
MASTER_SITES=	http://freefall.freebsd.org/~markm/ \
		ftp://ftp.za.freebsd.org/pub/FreeBSD/distfiles/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/distfiles/

MAINTAINER=	markm@FreeBSD.ORG

MAN1=		tn3270.1 mset.1
MAN5=		map3270.5
MANCOMPRESSED=	maybe

do-configure:
	${ECHO} "BINDIR=	${PREFIX}/bin" > ${WRKDIR}/Makefile.inc
	${ECHO} "MANDIR=	${PREFIX}/man/man" >> ${WRKDIR}/Makefile.inc
do-build:
	cd ${WRKSRC}; \
	${MAKE} depend; \
	${MAKE} all

.include <bsd.port.mk>
