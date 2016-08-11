# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	Spreadsheet-Read
PORTVERSION=	0.64
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HMBRAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Read the data from a spreadsheet

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-stringy>0:devel/p5-IO-stringy \
		p5-Text-CSV_XS>=0.71:textproc/p5-Text-CSV_XS \
		p5-Text-CSV>=1.33:textproc/p5-Text-CSV \
		p5-Spreadsheet-ReadSXC>=0.20:textproc/p5-Spreadsheet-ReadSXC \
		p5-Spreadsheet-ParseExcel>=0.13:textproc/p5-Spreadsheet-ParseExcel
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-NoWarnings>0:devel/p5-Test-NoWarnings

USES=		perl5 tar:tgz
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
