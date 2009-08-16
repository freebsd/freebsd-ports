# New ports collection makefile for:	textproc/p5-XML-Validator-Schema
# Date created:				Oct 14th 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	XML-Validator-Schema
PORTVERSION=	1.10
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for validating XML documents against a W3C XML Schema

BUILD_DEPENDS=	${SITE_PERL}/Tree/DAG_Node.pm:${PORTSDIR}/devel/p5-Tree-DAG_Node \
		${SITE_PERL}/XML/SAX/Exception.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/XML/Filter/BufferText.pm:${PORTSDIR}/textproc/p5-XML-Filter-BufferText \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Validator::Schema.3 \
		XML::Validator::Schema::Attribute.3 \
		XML::Validator::Schema::AttributeLibrary.3 \
		XML::Validator::Schema::AttributeNode.3 \
		XML::Validator::Schema::ComplexTypeNode.3 \
		XML::Validator::Schema::ElementLibrary.3 \
		XML::Validator::Schema::ElementNode.3 \
		XML::Validator::Schema::ElementRefNode.3 \
		XML::Validator::Schema::Library.3 \
		XML::Validator::Schema::ModelNode.3 \
		XML::Validator::Schema::Node.3 \
		XML::Validator::Schema::Parser.3 \
		XML::Validator::Schema::RootNode.3 \
		XML::Validator::Schema::SimpleType.3 \
		XML::Validator::Schema::SimpleTypeNode.3 \
		XML::Validator::Schema::TypeLibrary.3 \
		XML::Validator::Schema::Util.3

.if !defined(NOPORTDOCS)
PORTDOCS=	ANNOUNCE Changes README TODO

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
