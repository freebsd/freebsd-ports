# New ports collection makefile for:	xsb
# Date created:		29 Jul 2001
# Whom:			Christopher Rued
#
# $FreeBSD$
#

PORTNAME=	XSB
PORTVERSION=	2.4
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= xsb

MAINTAINER=	c.rued@xsb.com

WRKSRC=		${WRKDIR}/XSB/build

PLIST_SUB+=     MACHINE_ARCH=${MACHINE_ARCH} OPSYS=${OPSYS:S/BSD/bsd/g:S/F/f/g:S/O/o/g:S/N/n/g}

do-build:
	@ cd ${WRKSRC} ; \
	./configure  ; \
	./makexsb

do-install:
	@ ${CP} -r ${WRKDIR}/XSB ${PREFIX} ; \
	${LN} -s ${PREFIX}/XSB/docs ${PREFIX}/share/xsb ; \
	${ECHO} XSB is now installed. ; \
	${ECHO} To run it, execute ${PREFIX}/XSB/bin/xsb ; \
	${ECHO} The user manual is in ${PREFIX}/share/xsb

.include <bsd.port.mk>
