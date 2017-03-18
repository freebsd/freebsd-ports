# Created by: Lev Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	XML-XSH
PORTVERSION=	1.8.4
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	This is xsh - an XML Editing Shell

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/Artistic
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-LibXSLT>=0:textproc/p5-XML-LibXSLT \
		p5-XML-LibXML-Iterator>=0:textproc/p5-XML-LibXML-Iterator \
		p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent \
		p5-XML-XUpdate-LibXML>=0:textproc/p5-XML-XUpdate-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}

DEPRECATED=	Deprecated by upstream
EXPIRATION_DATE=2017-03-31

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
