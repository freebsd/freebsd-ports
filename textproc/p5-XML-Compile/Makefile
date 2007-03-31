# New ports collection makefile for:	p5-XML-Compile
# Date created:		2006-08-29
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	XML-Compile
PORTVERSION=	0.17
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Compilation based XML processing

RUN_DEPENDS=	p5-XML-LibXML>=1.61:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-Data-Dump-Streamer>=2.03:${PORTSDIR}/devel/p5-Data-Dump-Streamer \
    		p5-Math-BigInt>=1.77:${PORTSDIR}/math/p5-Math-BigInt
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::Compile.3 XML::Compile::SOAP::Operation.3 \
	XML::Compile::Dumper.3 XML::Compile::Schema.3 \
	XML::Compile::Schema::BuiltInFacets.3 \
	XML::Compile::Schema::BuiltInTypes.3 \
	XML::Compile::Schema::Instance.3 \
	XML::Compile::Schema::NameSpaces.3 \
	XML::Compile::Schema::Specs.3 \
	XML::Compile::Schema::Template.3 \
	XML::Compile::Schema::Translate.3 \
	XML::Compile::Schema::XmlReader.3 \
	XML::Compile::Schema::XmlWriter.3 \
	XML::Compile::WSDL.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires Perl 5.8 or above. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
