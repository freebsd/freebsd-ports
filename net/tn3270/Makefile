# New ports collection makefile for:	tn3270
# Date created:		30 August 1999
# Whom:			markm
#
# $FreeBSD$
#

PORTNAME=	tn3270
PORTVERSION=	4.4
CATEGORIES=	net
MASTER_SITES=	http://freefall.freebsd.org/~markm/ \
		ftp://ftp.za.freebsd.org/pub/FreeBSD/distfiles/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/distfiles/
DISTNAME=	tn3270

MAINTAINER=	markm@FreeBSD.ORG

MAN1=		tn3270.1 mset.1
MAN5=		map3270.5
MANCOMPRESSED=	maybe

LIBTELNETDIR?=	/usr/src/lib/libtelnet

post-extract:
	@if [ ! -d ${LIBTELNETDIR} ]; then \
		${ECHO} "You need libtelnet sources in"; \
		${ECHO} "${LIBTELNETDIR}"; \
		${ECHO} "to build this port."; \
	exit 1; \
	fi
	${CP} -rp ${LIBTELNETDIR} ${WRKSRC}

do-configure:
	${ECHO} "BINDIR=	${PREFIX}/bin" > ${WRKDIR}/Makefile.inc
	${ECHO} "MANDIR=	${PREFIX}/man/man" >> ${WRKDIR}/Makefile.inc
do-build:
	cd ${WRKSRC}; \
	${MAKE} depend; \
	${MAKE} all

.include <bsd.port.mk>
