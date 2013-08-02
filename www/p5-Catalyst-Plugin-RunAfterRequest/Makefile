# Created by: Andrey Kostenko <andrey@kostenko.name>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-RunAfterRequest
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Run code after the response has been sent

RUN_DEPENDS=	p5-Catalyst-Component-InstancePerContext>=0:${PORTSDIR}/www/p5-Catalyst-Component-InstancePerContext \
		p5-Catalyst-Runtime>=5.80004:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
BUILD_DEPENDS:=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Module-Find>=0:${PORTSDIR}/devel/p5-Module-Find \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

MAN3=		Catalyst::Plugin::RunAfterRequest.3 \
			Catalyst::Model::Role::RunAfterRequest.3

.include <bsd.port.mk>
