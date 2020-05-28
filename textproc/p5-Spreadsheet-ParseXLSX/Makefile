# $FreeBSD$

PORTNAME=	Spreadsheet-ParseXLSX
PORTVERSION=	0.27
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for parsing XLSX files

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CryptX>=0:security/p5-CryptX \
		p5-XML-Twig>=0:textproc/p5-XML-Twig \
		p5-OLE-Storage_Lite>=0:devel/p5-OLE-Storage_Lite \
		p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-Spreadsheet-ParseExcel>=0:textproc/p5-Spreadsheet-ParseExcel \
		p5-Graphics-ColorUtils>=0:graphics/p5-Graphics-ColorUtils

USES=		perl5

USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
