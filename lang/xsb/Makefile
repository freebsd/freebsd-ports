# New ports collection makefile for:	xsb
# Date created:		29 Jul 2001
# Whom:			Christopher Rued
#
# $FreeBSD$
#

PORTNAME=	XSB
PORTVERSION=	2.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}

MAINTAINER=	c.rued@xsb.com
COMMENT=	A tabled Logic Programming and Deductive Database system

WRKSRC=		${WRKDIR}/XSB/build
USE_GMAKE=	yes

MAN1=	xsb.1

PLIST_SUB+=	MACHINE_ARCH=${MACHINE_ARCH} \
		OPSYS=${OPSYS:S/BSD/bsd/g:S/F/f/g:S/O/o/g:S/N/n/g}

do-build:
	@ cd ${WRKSRC} ; \
	./configure ; \
	./makexsb ; \
	./makexsb dynmodule

do-install:
	@ ${CP} -r ${WRKDIR}/XSB ${PREFIX} ; \
	${INSTALL_MAN} ${WRKDIR}/XSB/docs/userman/xsb.1 ${MAN1PREFIX}/man/man1 ; \
	${LN} -s ${PREFIX}/XSB/docs ${PREFIX}/share/xsb ; \
	${ECHO_CMD} XSB is now installed. ; \
	${ECHO_CMD} To run it, execute ${PREFIX}/XSB/bin/xsb ; \
	${ECHO_CMD} The user manual is in ${PREFIX}/share/xsb

.include <bsd.port.mk>
