# New ports collection makefile for:    memtest
# Date created:         18 Jun 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	memtest
PORTVERSION=	2.93.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.qcc.sk.ca/~charlesc/software/memtester/
DISTNAME=	${PORTNAME}er-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Utility to test for faulty memory subsystem

USE_BZIP2=	yes
USE_GMAKE=	yes

MAN1=	${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>
