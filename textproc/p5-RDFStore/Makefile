# New ports collection makefile for:	RDFStore
# Date created:	   30 May 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	RDFStore
PORTVERSION=	0.51
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/A/AR/AREGGIORI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl API for RDF Storage

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BDB=	yes

PERL_CONFIGURE=	yes

MAN3=		DBD::RDFStore.3 DBMS.3 RDFStore.3 \
		RDFStore::Digest::Digestable.3 RDFStore::Literal.3 \
		RDFStore::Model.3 RDFStore::NodeFactory.3 RDFStore::Object.3 \
		RDFStore::Parser.3 RDFStore::Parser::NTriples.3 \
		RDFStore::Parser::SiRPAC.3 \
		RDFStore::Parser::Styles::RDFStore::Model.3 \
		RDFStore::Parser::Styles::RDFStore::Statement.3 \
		RDFStore::RDFNode.3 RDFStore::Resource.3 \
		RDFStore::SchemaModel.3 RDFStore::Serializer.3 \
		RDFStore::Serializer::NTriples.3 RDFStore::Serializer::RDFXML.3 \
		RDFStore::Serializer::RSS.3 RDFStore::Statement.3 \
		RDFStore::Util::Digest.3 RDFStore::Util::UTF8.3 \
		RDFStore::VirtualModel.3 RDFStore::Vocabulary::Generator.3 \
		RDQL::Parser.3 Util::BLOB.3

pre-configure:
	@${ECHO} "INCLUDE=${BDB_INCLUDE_DIR}" > ${WRKSRC}/arch_conf.in
	@${ECHO} "LIB=${BDB_LIB_DIR}" >> ${WRKSRC}/arch_conf.in
	@${ECHO} "DBNAME=-l${BDB_LIB_NAME}" >> ${WRKSRC}/arch_conf.in

.include <bsd.port.mk>
