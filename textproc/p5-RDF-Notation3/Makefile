# New ports collection makefile for:	RDF::Notation3
# Date created:		21 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	RDF-Notation3
PORTVERSION=	0.83
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	RDF
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	RDF Notation3 parser

BUILD_DEPENDS=	${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/RDF/Core.pm:${PORTSDIR}/textproc/p5-RDF-Core \
		${SITE_PERL}/RDFStore.pm:${PORTSDIR}/textproc/p5-RDFStore
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		RDF::Notation3.3 RDF::Notation3::PrefTriples.3 \
		RDF::Notation3::RDFCore.3 RDF::Notation3::RDFStore.3 \
		RDF::Notation3::ReaderFile.3 RDF::Notation3::ReaderString.3 \
		RDF::Notation3::SAX.3 RDF::Notation3::Template::TReader.3 \
		RDF::Notation3::Template::TTriples.3 \
		RDF::Notation3::Template::TXML.3 RDF::Notation3::Triples.3 \
		RDF::Notation3::XML.3

pre-patch:
	@${FIND} ${WRKSRC} -name "*.pm" | ${XARGS} ${PERL} -pi -e \
	'$$package=$$1 if /^package\s+([^\s;]*);/; s!^require 5.005_62;!!; s!^use warnings;!!; s!^our\s+(\$$)(VERSION)\s+=!$$1$${package}::$$2=!;'

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+= ${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

.include <bsd.port.post.mk>
