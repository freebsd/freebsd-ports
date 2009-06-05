# New ports collection makefile for:	p5-XML-Compile
# Date created:		2006-08-29
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	XML-Compile
PORTVERSION=	1.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Compilation based XML processing

RUN_DEPENDS=	p5-IO>=1.22:${PORTSDIR}/devel/p5-IO \
		p5-Log-Report>=0.17:${PORTSDIR}/devel/p5-Log-Report \
		p5-Math-BigInt>=1.77:${PORTSDIR}/math/p5-Math-BigInt \
		p5-XML-RegExp>=0.02:${PORTSDIR}/textproc/p5-XML-RegExp \
		p5-XML-LibXML>=1.65:${PORTSDIR}/textproc/p5-XML-LibXML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=	xml2yaml.1 schema2example.1
MAN3=	XML::Compile.3 \
	XML::Compile::FAQ.3 \
	XML::Compile::Iterator.3 XML::Compile::Util.3 \
	XML::Compile::Schema.3 \
	XML::Compile::Schema::BuiltInFacets.3 \
	XML::Compile::Schema::BuiltInTypes.3 \
	XML::Compile::Schema::Instance.3 \
	XML::Compile::Schema::NameSpaces.3 \
	XML::Compile::Schema::Specs.3 \
	XML::Compile::Translate.3 \
	XML::Compile::Translate::Reader.3 \
	XML::Compile::Translate::Template.3 \
	XML::Compile::Translate::Writer.3

.include <bsd.port.mk>
