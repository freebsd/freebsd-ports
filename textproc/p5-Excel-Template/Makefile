# Created by: Espen Tagestad <espen@tagestad.no>
# $FreeBSD$

PORTNAME=	Excel-Template
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Perl module for templating Excel files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-stringy>=0:devel/p5-IO-stringy \
		p5-Test-Exception>=0.21:devel/p5-Test-Exception \
		p5-XML-Parser>=0:textproc/p5-XML-Parser \
		p5-Spreadsheet-WriteExcel>=0:textproc/p5-Spreadsheet-WriteExcel \
		p5-Test-Deep>=0:devel/p5-Test-Deep
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
