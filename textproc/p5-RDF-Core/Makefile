# New ports collection makefile for:	RDF-Core
# Date created:	   30 May 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	RDF-Core
PORTVERSION=	0.31
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	RDF
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	An object oriented Perl modules for handling tasks related to RDF

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		RDF::Core.3 RDF::Core::Constants.3 RDF::Core::Enumerator.3 \
		RDF::Core::Enumerator::DB_File.3 \
		RDF::Core::Enumerator::Memory.3 \
		RDF::Core::Enumerator::Postgres.3 RDF::Core::Evaluator.3 \
		RDF::Core::Function.3 RDF::Core::Literal.3 RDF::Core::Model.3 \
		RDF::Core::Model::Parser.3 RDF::Core::Model::Serializer.3 \
		RDF::Core::ModelSet.3 RDF::Core::Node.3 \
		RDF::Core::NodeFactory.3 RDF::Core::Parser.3 RDF::Core::Query.3 \
		RDF::Core::Resource.3 RDF::Core::Schema.3 \
		RDF::Core::Serializer.3 RDF::Core::Statement.3 \
		RDF::Core::Storage.3 RDF::Core::Storage::DB_File.3 \
		RDF::Core::Storage::Memory.3 RDF::Core::Storage::Postgres.3

DOCSUBDIR=	/ RDF RDF/Core RDF/Core/Enumerator RDF/Core/Model \
		RDF/Core/Storage

pre-patch:
	@${FIND} ${WRKSRC} -name "*.pm" | ${XARGS} ${PERL} -pi -e \
	'$$package=$$1 if /^package\s+([^\s;]*);/; s!^require 5.005_62;!!; s!^use warnings;!!; s!^our\s+(\$$)(VERSION)\s+=!$$1$${package}::$$2=!;'

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
.for DOCDIR in ${DOCSUBDIR}
	@${MKDIR} ${DOCSDIR}/${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/${DOCDIR}/*.html	${DOCSDIR}/${DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
