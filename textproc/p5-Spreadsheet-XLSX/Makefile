# $FreeBSD$

PORTNAME=	Spreadsheet-XLSX
PORTVERSION=	0.15
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Perl extension for reading MS Excel 2007 files

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Spreadsheet-ParseExcel>0:textproc/p5-Spreadsheet-ParseExcel \
		p5-Archive-Zip>=1.18:archivers/p5-Archive-Zip

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
