# ex:ts=8
# New ports collection makefile for:	pdftohtml
# Date created:			1 Jun 2001
# Whom:				Soeren Boll Overgaard <boll@tolkien.dk>
#
# $FreeBSD$
#

PORTNAME=	pdftohtml
PORTVERSION=	0.33a
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://ports.tolkien.dk/pdftohtml/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/}

MAINTAINER=	boll@fork.dk

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GMAKE=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/pdftohtml ${PREFIX}/bin

.include <bsd.port.mk>
