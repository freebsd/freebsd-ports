# New ports collection makefile for:	Spreadsheet::WriteExcel
# Date created:		25 Dec 2000
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Spreadsheet-WriteExcel
PORTVERSION= 	0.23
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Spreadsheet
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@protey.ru

USE_PERL5=	yes

MAN3=		Spreadsheet::WriteExcel::Worksheet.3 \
		Spreadsheet::WriteExcel::BIFFwriter.3 \
		Spreadsheet::WriteExcel::OLEwriter.3 \
		Spreadsheet::WriteExcel::Workbook.3 \
		Spreadsheet::WriteExcel::examples::WorkbookBig.3 \
		Spreadsheet::WriteExcel.3 Spreadsheet::WriteExcel::Format.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL PREFIX=${PREFIX}

.include <bsd.port.mk>
