# New ports collection makefile for:	www/p5-Catalyst-Model-DBIC-Schema
# Date created:				13 Feb 2005
# Whom:					Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Model-DBIC-Schema
PORTVERSION=	0.13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	DBIx::Class::Schema Model Class

BUILD_DEPENDS=	\
	p5-Catalyst>=5.64:${PORTSDIR}/www/p5-Catalyst \
	p5-Class-Accessor>=0.22:${PORTSDIR}/devel/p5-Class-Accessor \
	p5-Class-Data-Accessor>=0.02:${PORTSDIR}/devel/p5-Class-Data-Accessor \
	p5-DBIx-Class>=0.05007:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-UNIVERSAL-require>=0.10:${PORTSDIR}/devel/p5-UNIVERSAL-require \
	p5-DBIx-Class-Schema-Loader>=0.02007:${PORTSDIR}/databases/p5-DBIx-Class-Schema-Loader \
	p5-Test-Simple>=0.32:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Catalyst::Helper::Model::DBIC::SchemaLoader.3 \
	Catalyst::Helper::Model::DBIC::Schema.3 \
	Catalyst::Model::DBIC::Schema.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500800
IGNORE=	requires Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
