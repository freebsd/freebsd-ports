# New ports collection makefile for:	pdflib
# Date created:		Mon Jan 18 17:03:33 CET 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pdflib
PORTVERSION=	3.03
CATEGORIES=	print
MASTER_SITES=	http://www.pdflib.com/pdflib/download/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/afm/Courier:${PORTSDIR}/print/afm
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

RESTRICTED=	"many odd restrictions on usage and distribution"
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-perl5=${PERL} \
		--with-jpeg=${PREFIX} \
		--with-pnglib=${PREFIX} \
		--enable-shared-pdflib \
		--enable-cxx \
		--with-zlib=/usr

do-install:
	${INSTALL_DATA} ${WRKSRC}/pdflib/.libs/libpdf.so.3 ${PREFIX}/lib
	${LN} -s libpdf.so.3 ${PREFIX}/lib/libpdf.so
	${INSTALL_DATA} ${WRKSRC}/pdflib/pdflib.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/pdflib
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/pdflib
.endif

.include <bsd.port.mk>
