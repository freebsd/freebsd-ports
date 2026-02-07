PORTNAME=	excel2csv
PORTVERSION=	1.07
CATEGORIES=	textproc perl5
PKGNAMEPREFIX=	p5-

MAINTAINER=	rosenke@dssgmbh.de
COMMENT=	Convert Microsoft Excel spreadsheets to CSV format
WWW=		https://github.com/xevo/xls2csv

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Locale-libintl>0:devel/p5-Locale-libintl \
		p5-Spreadsheet-ParseExcel>0:textproc/p5-Spreadsheet-ParseExcel \
		p5-Spreadsheet-XLSX>0:textproc/p5-Spreadsheet-XLSX \
		p5-Text-CSV_XS>0:textproc/p5-Text-CSV_XS \
		p5-Text-Iconv>0:converters/p5-Text-Iconv \
		p5-Unicode-Map>0:converters/p5-Unicode-Map

USES=		perl5
USE_PERL5=	configure
USE_GITHUB=	yes
GH_ACCOUNT=	xevo
GH_PROJECT=	xls2csv
GH_TAGNAME=	49386af

NO_ARCH=	yes

.include <bsd.port.mk>
