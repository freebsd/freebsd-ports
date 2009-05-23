# New ports collection makefile for:	Spreadsheet::ParseExcel
# Date created:		25 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Spreadsheet-ParseExcel
PORTVERSION=	0.49
PORTEPOCH=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Get information from Excel file

BUILD_DEPENDS=	p5-OLE-Storage_Lite>=0.08:${PORTSDIR}/devel/p5-OLE-Storage_Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Spreadsheet::ParseExcel.3 \
		Spreadsheet::ParseExcel::Cell.3 \
		Spreadsheet::ParseExcel::Dump.3 \
		Spreadsheet::ParseExcel::FmtDefault.3 \
		Spreadsheet::ParseExcel::FmtJapan.3 \
		Spreadsheet::ParseExcel::FmtJapan2.3 \
		Spreadsheet::ParseExcel::FmtUnicode.3 \
		Spreadsheet::ParseExcel::Font.3 \
		Spreadsheet::ParseExcel::Format.3 \
		Spreadsheet::ParseExcel::SaveParser.3 \
		Spreadsheet::ParseExcel::SaveParser::Workbook.3 \
		Spreadsheet::ParseExcel::SaveParser::Worksheet.3 \
		Spreadsheet::ParseExcel::Utility.3 \
		Spreadsheet::ParseExcel::Workbook.3 \
		Spreadsheet::ParseExcel::Worksheet.3

post-install:

.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}/Excel
	@${INSTALL_DATA} ${WRKSRC}/sample/README ${WRKSRC}/sample/res* \
		${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/sample/*.pl ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample/Excel/* ${EXAMPLESDIR}/Excel
.endif

.include <bsd.port.mk>
