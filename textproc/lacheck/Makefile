# New ports collection makefile for:	lacheck
# Date created:		8 February 2002
# Whom:			Uwe Pierau <uwe.pierau@tu-clausthal.de>
#
# $FreeBSD$
#

PORTNAME=	lacheck
PORTVERSION=	1.26
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.dina.kvl.dk/pub/Staff/Per.Abrahamsen/mirror/ftp/lacheck/ \
		http://ftp.agh.edu.pl/pub/tex/support/lacheck/

MAINTAINER=	uwe.pierau@tu-clausthal.de
COMMENT=	A tool for finding common mistakes in LaTeX documents

MAN1=		lacheck.1
PLIST_FILES=	bin/lacheck
ALL_TARGET=	lacheck lacheck.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lacheck ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lacheck.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
