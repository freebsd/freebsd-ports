PORTNAME=	Spreadsheet-Read
PORTVERSION=	0.91
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
RUN_DEPENDS=	p5-Data-Peek>=0.52:devel/p5-Data-Peek
TEST_DEPENDS=	p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings

USES=		perl5 tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes

CONFLICTS_INSTALL=	catdoc libxls xls2txt

OPTIONS_DEFINE=	CSV GNUMERIC ODS SXC TOOLS XLS XLSX
OPTIONS_DEFAULT=CSV GNUMERIC ODS SXC XLS XLSX
CSV_DESC=	Parse CSV streams
GNUMERIC_DESC=	Parse Gnumeric spreadsheets
ODS_DESC=	Parse OpenOffice spreadsheets
SXC_DESC=	Parse OpenOffice spreadsheets old style
TOOLS_DESC=	Spreadsheet tools
XLS_DESC=	Parse Microsoft Excel files
XLSX_DESC=	Parse Microsoft Excel 2007+ files

CSV_BUILD_DEPENDS=	p5-Text-CSV>=2.03:textproc/p5-Text-CSV \
			p5-Text-CSV_XS>=1.52:textproc/p5-Text-CSV_XS
CSV_RUN_DEPENDS=	p5-Text-CSV>=2.03:textproc/p5-Text-CSV \
			p5-Text-CSV_XS>=1.52:textproc/p5-Text-CSV_XS
GNUMERIC_BUILD_DEPENDS=	p5-Spreadsheet-ReadGnumeric>=0.4:textproc/p5-Spreadsheet-ReadGnumeric
GNUMERIC_RUN_DEPENDS=	p5-Spreadsheet-ReadGnumeric>=0.4:textproc/p5-Spreadsheet-ReadGnumeric
ODS_BUILD_DEPENDS=	p5-Spreadsheet-ReadSXC>=0.38:textproc/p5-Spreadsheet-ReadSXC
ODS_RUN_DEPENDS=	p5-Spreadsheet-ReadSXC>=0.38:textproc/p5-Spreadsheet-ReadSXC
SXC_BUILD_DEPENDS=	p5-Spreadsheet-ReadSXC>=0.38:textproc/p5-Spreadsheet-ReadSXC
SXC_RUN_DEPENDS=	p5-Spreadsheet-ReadSXC>=0.38:textproc/p5-Spreadsheet-ReadSXC
TOOLS_BUILD_DEPENDS=	p5-Tk>=804.036:x11-toolkits/p5-Tk \
			p5-Tk-TableMatrix>=0:x11-toolkits/p5-Tk-TableMatrix
TOOLS_RUN_DEPENDS=	p5-Tk>=804.036:x11-toolkits/p5-Tk \
			p5-Tk-TableMatrix>=0:x11-toolkits/p5-Tk-TableMatrix
XLS_BUILD_DEPENDS=	p5-Spreadsheet-ParseExcel>=0.65:textproc/p5-Spreadsheet-ParseExcel
XLS_RUN_DEPENDS=	p5-Spreadsheet-ParseExcel>=0.65:textproc/p5-Spreadsheet-ParseExcel
XLSX_BUILD_DEPENDS=	p5-Spreadsheet-ParseExcel>=0:textproc/p5-Spreadsheet-ParseExcel \
			p5-Spreadsheet-ParseXLSX>=0.27:textproc/p5-Spreadsheet-ParseXLSX
XLSX_RUN_DEPENDS=	p5-Spreadsheet-ParseExcel>=0:textproc/p5-Spreadsheet-ParseExcel \
			p5-Spreadsheet-ParseXLSX>=0.27:textproc/p5-Spreadsheet-ParseXLSX

.include <bsd.port.mk>
