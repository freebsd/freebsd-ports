# Created by: Andrey Kostenko <andrey@kostenko.name>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-RunAfterRequest
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Run code after the response has been sent

BUILD_DEPENDS=	p5-Catalyst-Component-InstancePerContext>=0:www/p5-Catalyst-Component-InstancePerContext \
		p5-Catalyst-Runtime>=5.80004:www/p5-Catalyst-Runtime \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS+=	p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Module-Find>=0:devel/p5-Module-Find \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
