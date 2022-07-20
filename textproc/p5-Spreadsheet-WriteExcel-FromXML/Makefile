PORTNAME=	Spreadsheet-WriteExcel-FromXML
PORTVERSION=	1.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create an Excel Spreadsheet from XML

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-OLE-Storage_Lite>=0:devel/p5-OLE-Storage_Lite \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-Spreadsheet-WriteExcel>=0:textproc/p5-Spreadsheet-WriteExcel

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
