# New ports collection makefile for:	pdflib
# Date created:		Mon Jan 18 17:03:33 CET 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pdflib
PORTVERSION=	2.01
CATEGORIES=	print
MASTER_SITES=	http://www.pdflib.com/pdflib/download/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/lib/afm/Courier:${PORTSDIR}/print/afm
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl5=${PERL} \
		--with-tiff=${PREFIX} \
		--with-jpeg=${PREFIX} \
		--with-zlib=/usr

do-install:
	${INSTALL_DATA} ${WRKSRC}/pdflib/libpdf.so.2 ${PREFIX}/lib
	${LN} -s libpdf.so.2 ${PREFIX}/lib/libpdf.so
	${INSTALL_DATA} ${WRKSRC}/pdflib/pdflib.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pdflib
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/pdflib
.endif

.include <bsd.port.mk>
