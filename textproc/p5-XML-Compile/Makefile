# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	XML-Compile
PORTVERSION=	1.35
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Compilation based XML processing

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Log-Report>=0.99:${PORTSDIR}/devel/p5-Log-Report \
		p5-XML-LibXML>=1.94:${PORTSDIR}/textproc/p5-XML-LibXML
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Deep>=0.095:${PORTSDIR}/devel/p5-Test-Deep \
		p5-XML-Compile-Tester>=0.90:${PORTSDIR}/devel/p5-XML-Compile-Tester

PERL_CONFIGURE=	yes

MAN1=		schema2example.1 \
		xml2yaml.1
MAN3=		XML::Compile.3 \
		XML::Compile::FAQ.3 \
		XML::Compile::Iterator.3 \
		XML::Compile::Schema.3 \
		XML::Compile::Schema::BuiltInFacets.3 \
		XML::Compile::Schema::BuiltInTypes.3 \
		XML::Compile::Schema::Instance.3 \
		XML::Compile::Schema::NameSpaces.3 \
		XML::Compile::Schema::Specs.3 \
		XML::Compile::Translate.3 \
		XML::Compile::Translate::Reader.3 \
		XML::Compile::Translate::Template.3 \
		XML::Compile::Translate::Writer.3 \
		XML::Compile::Util.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-MIME-Base64>=3.10:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS+=	p5-MIME-Base64>=3.10:${PORTSDIR}/converters/p5-MIME-Base64
.endif

.include <bsd.port.post.mk>
