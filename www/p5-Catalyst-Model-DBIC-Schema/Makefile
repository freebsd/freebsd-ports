# New ports collection makefile for:	www/p5-Catalyst-Model-DBIC-Schema
# Date created:				13 Feb 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Model-DBIC-Schema
PORTVERSION=	0.25
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	DBIx::Class::Schema Model Class

BUILD_DEPENDS=	\
	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
	p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel \
	p5-Class-Accessor>=0.22:${PORTSDIR}/devel/p5-Class-Accessor \
	p5-Class-C3>=0.20:${PORTSDIR}/devel/p5-Class-C3 \
	p5-Class-C3-XS>=0.08:${PORTSDIR}/devel/p5-Class-C3-XS \
	p5-Class-Data-Accessor>=0.02:${PORTSDIR}/devel/p5-Class-Data-Accessor \
	p5-DBIx-Class>=0.07006:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
	p5-UNIVERSAL-require>=0.10:${PORTSDIR}/devel/p5-UNIVERSAL-require \
	p5-DBIx-Class-Schema-Loader>=0.04005:${PORTSDIR}/databases/p5-DBIx-Class-Schema-Loader
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	Catalyst::Helper::Model::DBIC::Schema.3 \
	Catalyst::Model::DBIC::Schema.3 \
	Catalyst::TraitFor::Model::DBIC::Schema::Caching.3 \
	Catalyst::TraitFor::Model::DBIC::Schema::Replicated.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,^feature, .. m,;$$,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
