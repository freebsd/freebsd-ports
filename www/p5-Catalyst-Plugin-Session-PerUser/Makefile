# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Session-PerUser
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Per user sessions (instead of per browser sessions)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Catalyst-Plugin-Authentication>=0:www/p5-Catalyst-Plugin-Authentication \
		p5-Catalyst-Plugin-Session>=0.06:www/p5-Catalyst-Plugin-Session \
		p5-Hash-Merge>=0:textproc/p5-Hash-Merge \
		p5-MRO-Compat>=0:devel/p5-MRO-Compat \
		p5-Moose>=0:devel/p5-Moose \
		p5-Object-Signature>=0:devel/p5-Object-Signature \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
