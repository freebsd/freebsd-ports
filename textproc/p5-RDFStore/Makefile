# New ports collection makefile for:	RDFStore
# Date created:	   30 May 2002
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	RDFStore
PORTVERSION=	0.42
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	RDF
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl API for RDF Storage

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/Digest.pm:${PORTSDIR}/security/p5-Digest \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Data::MagicTie.3 RDFStore.3 RDFStore::Literal.3 \
		RDFStore::Model.3 RDFStore::NodeFactory.3 \
		RDFStore::Parser::OpenHealth.3 RDFStore::Parser::SiRPAC.3 \
		RDFStore::Parser::Styles::MagicTie.3 RDFStore::RDFNode.3 \
		RDFStore::Resource.3 RDFStore::SchemaModel.3 \
		RDFStore::SetModel.3 RDFStore::Stanford::Digest.3 \
		RDFStore::Stanford::Digest::Abstract.3 \
		RDFStore::Stanford::Digest::Digestable.3 \
		RDFStore::Stanford::Digest::Generic.3 \
		RDFStore::Stanford::Digest::MD5.3 \
		RDFStore::Stanford::Digest::SHA1.3 \
		RDFStore::Stanford::Digest::Util.3 \
		RDFStore::Stanford::Literal.3 RDFStore::Stanford::Model.3 \
		RDFStore::Stanford::NodeFactory.3 RDFStore::Stanford::RDFNode.3 \
		RDFStore::Stanford::Resource.3 RDFStore::Stanford::SetModel.3 \
		RDFStore::Stanford::Statement.3 \
		RDFStore::Stanford::VirtualModel.3 \
		RDFStore::Stanford::Vocabulary::Generator.3 \
		RDFStore::Statement.3 RDFStore::VirtualModel.3

.include <bsd.port.mk>
