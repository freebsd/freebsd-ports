# ex:ts=8
# New ports collection makefile for:	pdftohtml
# Date created:			1 Jun 2001
# Whom:				Soeren Boll Overgaard <boll@tolkien.dk>
#
# $FreeBSD$
#

PORTNAME=	pdftohtml
PORTVERSION=	0.32b
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_0_32b

MAINTAINER=	boll@fork.dk

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pdftohtml.bin ${PREFIX}/bin/pdftohtml
	${INSTALL_PROGRAM} ${WRKSRC}/pdftops.bin ${PREFIX}/bin/pdftops
post-install:
	strip ${PREFIX}/bin/pdftohtml
	strip ${PREFIX}/bin/pdftops

.include <bsd.port.mk>
