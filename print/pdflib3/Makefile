# New ports collection makefile for:	pdflib
# Version required:	0.6
# Date created:		Mon Jan 18 17:03:33 CET 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	pdflib-0.6
CATEGORIES=	print
MASTER_SITES=	http://www.ifconnection.de/~tm/software/pdflib/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.ORG

RUN_DEPENDS=	${PREFIX}/lib/afm/Courier:${PORTSDIR}/print/afm
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff34 \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GMAKE=	yes
MAKEFILE=	makefile.gcc

pre-build:
	${SED} -e "s#!!PREFIX!!#${PREFIX}#" < ${WRKSRC}/pdf.h > ${WRKSRC}/pdf.h.tmp
	${MV} ${WRKSRC}/pdf.h.tmp ${WRKSRC}/pdf.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/libpdf.a ${PREFIX}/lib
.for prg in imagepdf pdfclock pdfdemo pdfgraph text2pdf
	${INSTALL_PROGRAM} ${WRKSRC}/${prg} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/pdf.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pdflib
	${INSTALL_DATA} ${WRKSRC}/PDFlib-0.6.pdf ${PREFIX}/share/doc/pdflib
.endif

.include <bsd.port.mk>
