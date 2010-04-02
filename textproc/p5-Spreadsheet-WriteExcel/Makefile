# New ports collection makefile for:	Spreadsheet::WriteExcel
# Date created:		25 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Spreadsheet-WriteExcel
PORTVERSION=	2.37
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Write to a cross-platform Excel binary file

BUILD_DEPENDS=	${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${SITE_PERL}/OLE/Storage_Lite.pm:${PORTSDIR}/devel/p5-OLE-Storage_Lite \
		${SITE_PERL}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		chartex.1
MAN3=		Spreadsheet::WriteExcel.3 \
		Spreadsheet::WriteExcel::BIFFwriter.3 \
		Spreadsheet::WriteExcel::Big.3 \
		Spreadsheet::WriteExcel::Chart.3 \
		Spreadsheet::WriteExcel::Chart::Area.3 \
		Spreadsheet::WriteExcel::Chart::Bar.3 \
		Spreadsheet::WriteExcel::Chart::Column.3 \
		Spreadsheet::WriteExcel::Chart::External.3 \
		Spreadsheet::WriteExcel::Chart::Line.3 \
		Spreadsheet::WriteExcel::Chart::Pie.3 \
		Spreadsheet::WriteExcel::Chart::Scatter.3 \
		Spreadsheet::WriteExcel::Chart::Stock.3 \
		Spreadsheet::WriteExcel::Examples.3 \
		Spreadsheet::WriteExcel::Format.3 \
		Spreadsheet::WriteExcel::Formula.3 \
		Spreadsheet::WriteExcel::OLEwriter.3 \
		Spreadsheet::WriteExcel::Properties.3 \
		Spreadsheet::WriteExcel::Utility.3 \
		Spreadsheet::WriteExcel::Workbook.3 \
		Spreadsheet::WriteExcel::Worksheet.3

post-patch:
	@${FIND} ${WRKSRC} -name "*.p[lm]"| \
	${XARGS} ${PERL} -pi -e 's/\x0D(?=\x0A)//g'

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}/images
	@${MKDIR} ${DOCSDIR}/tpj_images
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/images/* ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/docs/tpj_images/* ${DOCSDIR}/tpj_images
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README \
		${WRKSRC}/examples/republic.png ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.txt ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
