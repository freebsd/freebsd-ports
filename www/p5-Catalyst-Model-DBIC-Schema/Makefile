# New ports collection makefile for:	www/p5-Catalyst-Model-DBIC-Schema
# Date created:				13 Feb 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Model-DBIC-Schema
PORTVERSION=	0.25
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	DBIx::Class::Schema Model Class

BUILD_DEPENDS=	\
	p5-Catalyst-Runtime>=5.80005:${PORTSDIR}/www/p5-Catalyst-Runtime \
	p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel \
	p5-CatalystX-Component-Traits>=0.03:${PORTSDIR}/www/p5-CatalystX-Component-Traits \
	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
	p5-Moose-Autobox>=0:${PORTSDIR}/devel/p5-Moose-Autobox \
	p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
	p5-DBIx-Class>=0.08107:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
	p5-Carp-Clan>=0:${PORTSDIR}/devel/p5-Carp-Clan \
	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
	p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Helper::Model::DBIC::Schema.3 \
	Catalyst::Model::DBIC::Schema.3 \
	Catalyst::TraitFor::Model::DBIC::Schema::Caching.3 \
	Catalyst::TraitFor::Model::DBIC::Schema::Replicated.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,^feature, .. m,;$$,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
