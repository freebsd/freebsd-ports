# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Spreadsheet-WriteExcel
PORTVERSION=	2.39
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write to a cross-platform Excel binary file

BUILD_DEPENDS=	p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent \
		p5-OLE-Storage_Lite>=0:${PORTSDIR}/devel/p5-OLE-Storage_Lite \
		p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	"*.p[lm]"

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
