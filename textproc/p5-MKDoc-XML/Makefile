# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MKDoc-XML
PORTVERSION=	0.75
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BPOSTLE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The MKDoc XML Toolkit

BUILD_DEPENDS=	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	MKDoc::XML.3 \
	MKDoc::XML::Decode.3 \
	MKDoc::XML::Dumper.3 \
	MKDoc::XML::Encode.3 \
	MKDoc::XML::Stripper.3 \
	MKDoc::XML::Tagger.3 \
	MKDoc::XML::Token.3 \
	MKDoc::XML::Tokenizer.3 \
	MKDoc::XML::TreeBuilder.3 \
	MKDoc::XML::TreePrinter.3

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
