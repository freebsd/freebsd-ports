# ex:ts=8
# New ports collection makefile for:	pdftohtml
# Date created:			1 Jun 2001
# Whom:				Soeren Boll Overgaard <boll@tolkien.dk>
#
# $FreeBSD$
#

PORTNAME=	pdftohtml
PORTVERSION=	0.31
CATEGORIES=	textproc
MASTER_SITES=	http://www.ra.informatik.uni-stuttgart.de/~gosho/pdftohtml/Download/ \
		http://ports.tolkien.dk/pdftohtml/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/}_test

MAINTAINER=	boll@tolkien.dk

ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:S/./_/}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdftohtml.bin ${PREFIX}/bin/pdftohtml
	${INSTALL_PROGRAM} ${WRKSRC}/pdftops.bin ${PREFIX}/bin/pdftops

.include <bsd.port.mk>
