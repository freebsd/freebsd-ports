# New ports collection makefile for:	Spreadsheet::WriteExcel
# Date created:		25 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Spreadsheet-WriteExcel
PORTVERSION=	0.34
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Spreadsheet
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Spreadsheet::WriteExcel.3 \
		Spreadsheet::WriteExcel::BIFFwriter.3 \
		Spreadsheet::WriteExcel::Big.3 \
		Spreadsheet::WriteExcel::Format.3 \
		Spreadsheet::WriteExcel::Formula.3 \
		Spreadsheet::WriteExcel::OLEwriter.3 \
		Spreadsheet::WriteExcel::Utility.3 \
		Spreadsheet::WriteExcel::Workbook.3 \
		Spreadsheet::WriteExcel::WorkbookBig.3 \
		Spreadsheet::WriteExcel::Worksheet.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-configure:
		${MV} ${WRKSRC}/WriteExcel/doc	${WRKSRC}
		${MV} ${WRKSRC}/WriteExcel/examples	${WRKSRC}
		${PERL} -pi -e 's:WriteExcel/(doc|examples):\1:g' \
			${WRKSRC}/MANIFEST

post-install:
.ifndef(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
		@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
		${INSTALL_DATA} ${WRKSRC}/examples/* \
			${PREFIX}/share/examples/${PORTNAME}
.endif

.include <bsd.port.mk>
