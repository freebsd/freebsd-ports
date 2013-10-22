# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	RDF-Core
PORTVERSION=	0.51
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Object oriented Perl modules for handling tasks related to RDF

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

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

NO_STAGE=	yes
post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
.for DOCDIR in ${DOCSUBDIR}
	@${MKDIR} ${DOCSDIR}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${DOCDIR}/*.html	${DOCSDIR}/${DOCDIR}
.endfor
.endif

.include <bsd.port.mk>
