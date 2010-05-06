# New ports collection makefile for:	www/p5-Catalyst-Model-DBIC-Schema
# Date created:				13 Feb 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	Catalyst-Model-DBIC-Schema
PORTVERSION=	0.41
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBIx::Class::Schema Model Class

RUN_DEPENDS=	p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan \
		p5-Catalyst-Runtime>=5.80005:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-CatalystX-Component-Traits>=0.14:${PORTSDIR}/www/p5-CatalystX-Component-Traits \
		p5-DBIx-Class>=0.08114:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

PERL_CONFIGURE=	5.8.1+
MAN3=	Catalyst::Helper::Model::DBIC::Schema.3 \
	Catalyst::Model::DBIC::Schema.3 \
	Catalyst::TraitFor::Model::DBIC::Schema::Caching.3 \
	Catalyst::TraitFor::Model::DBIC::Schema::Replicated.3 \
	Catalyst::TraitFor::Model::DBIC::Schema::SchemaProxy.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,^feature, .. m,;$$,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
