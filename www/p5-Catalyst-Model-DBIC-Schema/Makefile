# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Model-DBIC-Schema
PORTVERSION=	0.65
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBIx::Class::Schema Model Class

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Carp-Clan>=0:devel/p5-Carp-Clan \
		p5-Catalyst-Component-InstancePerContext>=0:www/p5-Catalyst-Component-InstancePerContext \
		p5-Catalyst-Devel>=1.0:www/p5-Catalyst-Devel \
		p5-Catalyst-Runtime>=5.80005:www/p5-Catalyst-Runtime \
		p5-CatalystX-Component-Traits>=0.14:www/p5-CatalystX-Component-Traits \
		p5-DBIx-Class>=0.08114:databases/p5-DBIx-Class \
		p5-DBIx-Class-Cursor-Cached>=0:databases/p5-DBIx-Class-Cursor-Cached \
		p5-DBIx-Class-Schema-Loader>=0.04005:databases/p5-DBIx-Class-Schema-Loader \
		p5-Hash-Merge>=0:textproc/p5-Hash-Merge \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Module-Runtime>=0.012:devel/p5-Module-Runtime \
		p5-Moose>=1.12:devel/p5-Moose \
		p5-MooseX-MarkAsMethods>=0.13:devel/p5-MooseX-MarkAsMethods \
		p5-MooseX-NonMoose>=0.16:devel/p5-MooseX-NonMoose \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-MooseX-Types-LoadableClass>=0.009:devel/p5-MooseX-Types-LoadableClass \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-namespace-autoclean>=0.09:devel/p5-namespace-autoclean \
		p5-namespace-clean>=0:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Requires>=0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
