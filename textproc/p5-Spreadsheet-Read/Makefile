PORTNAME=	Spreadsheet-Read
PORTVERSION=	0.87
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HMBRAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read the data from a spreadsheet
WWW=		https://metacpan.org/release/Spreadsheet-Read

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Spreadsheet-ReadSXC>=0.26:textproc/p5-Spreadsheet-ReadSXC \
		p5-Spreadsheet-XLSX>=0.15:textproc/p5-Spreadsheet-XLSX \
		p5-Text-CSV>=1.97:textproc/p5-Text-CSV \
		p5-Text-CSV_XS>=1.36:textproc/p5-Text-CSV_XS
TEST_DEPENDS=	p5-Test-NoWarnings>0:devel/p5-Test-NoWarnings

USES=		perl5 tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes

CONFLICTS_INSTALL=	catdoc libxls xls2txt

.include <bsd.port.mk>
