# New ports collection makefile for:	RDF::Notation3
# Date created:		21 Nov 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	RDF-Notation3
PORTVERSION=	0.70
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	RDF
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/RDF/Core.pm:${PORTSDIR}/textproc/p5-RDF-Core \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/RDFStore.pm:${PORTSDIR}/textproc/p5-RDFStore
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
	@${FIND} ${WRKSRC} -name "*.pm" | xargs ${PERL} -pi -e \
	'$$package=$$1 if /^package\s+([^\s;]*);/; s!^require 5.005_62;!!; s!^use warnings;!!; s!^our\s+(\$$)(VERSION)\s+=!$$1$${package}::$$2=!;'

.include <bsd.port.mk>
