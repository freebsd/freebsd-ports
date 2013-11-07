# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	XML-SAXDriver-Excel
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl SAX driver for converting Excel files to XML

BUILD_DEPENDS=	p5-Spreadsheet-ParseExcel>=0.2603:${PORTSDIR}/textproc/p5-Spreadsheet-ParseExcel \
		p5-XML-SAX>=0.14:${PORTSDIR}/textproc/p5-XML-SAX
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_DOS2UNIX=	yes

.include <bsd.port.mk>
