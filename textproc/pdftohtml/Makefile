# ex:ts=8
# New ports collection makefile for:	pdftohtml
# Date created:			1 Jun 2001
# Whom:				Soeren Boll Overgaard <boll@tolkien.dk>
#
# $FreeBSD$
#

PORTNAME=	pdftohtml
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/}

MAINTAINER=	erwin@lansing.dk

RUN_DEPENDS=	${LOCALBASE}/bin/gs:${PORTSDIR}/print/ghostscript-gnu

WRKSRC=		${WRKDIR}/${PORTNAME}

pre-patch:
.for file in goo/Makefile xpdf/Makefile
	@${MV} ${WRKSRC}/${file} ${WRKSRC}/${file}.orig
	@${SED} -e "s|-O2||; s|-g||" ${WRKSRC}/${file}.orig \
		> ${WRKSRC}/${file}
.endfor

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/pdftohtml ${PREFIX}/bin

.include <bsd.port.mk>
