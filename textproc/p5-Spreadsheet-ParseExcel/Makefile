# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Spreadsheet-ParseExcel
PORTVERSION=	0.59
PORTEPOCH=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Get information from Excel file

BUILD_DEPENDS=	p5-OLE-Storage_Lite>=0.19:${PORTSDIR}/devel/p5-OLE-Storage_Lite \
		p5-Crypt-RC4>=0:${PORTSDIR}/security/p5-Crypt-RC4 \
		p5-Digest-Perl-MD5>=0:${PORTSDIR}/security/p5-Digest-Perl-MD5
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

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

NO_STAGE=	yes
post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}/Excel
	${INSTALL_DATA} ${WRKSRC}/sample/README ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sample/*.pl ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/Excel/* ${EXAMPLESDIR}/Excel
.endif

.include <bsd.port.mk>
