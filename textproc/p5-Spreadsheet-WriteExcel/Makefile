# New ports collection makefile for:	Spreadsheet::WriteExcel
# Date created:		25 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Spreadsheet-WriteExcel
PORTVERSION= 	0.24
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Spreadsheet
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

PERL_CONFIGURE=	yes

MAN3=		Spreadsheet::WriteExcel::Worksheet.3 \
		Spreadsheet::WriteExcel::BIFFwriter.3 \
		Spreadsheet::WriteExcel::OLEwriter.3 \
		Spreadsheet::WriteExcel::Workbook.3 \
		Spreadsheet::WriteExcel::examples::WorkbookBig.3 \
		Spreadsheet::WriteExcel.3 Spreadsheet::WriteExcel::Format.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
