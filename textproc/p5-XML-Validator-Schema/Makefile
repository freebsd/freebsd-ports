# New ports collection makefile for:	textproc/p5-XML-Validator-Schema
# Date created:				Oct 14th 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	XML-Validator-Schema
PORTVERSION=	1.08
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Perl module for validating XML documents against a W3C XML Schema

BUILD_DEPENDS=	${SITE_PERL}/Tree/DAG_Node.pm:${PORTSDIR}/devel/p5-Tree-DAG_Node \
		${SITE_PERL}/XML/SAX/Exception.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/XML/Filter/BufferText.pm:${PORTSDIR}/textproc/p5-XML-Filter-BufferText
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Validator::Schema.3 \
		XML::Validator::Schema::Attribute.3 \
		XML::Validator::Schema::AttributeLibrary.3 \
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
