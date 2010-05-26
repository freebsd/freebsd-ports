# New ports collection makefile for:	p5-Spreadsheet-Read
# Date created:		2010-03-08
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Spreadsheet-Read
PORTVERSION=	0.40
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/H/HM/HMBRAND
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	steve@mouf.net
COMMENT=	Read the data from a spreadsheet

BUILD_DEPENDS=	${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/mach/Text/CSV_XS.pm:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		${SITE_PERL}/Text/CSV.pm:${PORTSDIR}/textproc/p5-Text-CSV \
		${SITE_PERL}/Test/NoWarnings.pm:${PORTSDIR}/devel/p5-Test-NoWarnings \
		${SITE_PERL}/Spreadsheet/ReadSXC.pm:${PORTSDIR}/textproc/p5-Spreadsheet-ReadSXC \
		${SITE_PERL}/Spreadsheet/ParseExcel.pm:${PORTSDIR}/textproc/p5-Spreadsheet-ParseExcel
RUN_DEPENDS=	${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/mach/Text/CSV_XS.pm:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		${SITE_PERL}/Text/CSV.pm:${PORTSDIR}/textproc/p5-Text-CSV \
		${SITE_PERL}/Test/NoWarnings.pm:${PORTSDIR}/devel/p5-Test-NoWarnings \
		${SITE_PERL}/Spreadsheet/ReadSXC.pm:${PORTSDIR}/textproc/p5-Spreadsheet-ReadSXC \
		${SITE_PERL}/Spreadsheet/ParseExcel.pm:${PORTSDIR}/textproc/p5-Spreadsheet-ParseExcel

PERL_CONFIGURE=	yes

MAN3=	Spreadsheet::Read.3

.include <bsd.port.mk>
