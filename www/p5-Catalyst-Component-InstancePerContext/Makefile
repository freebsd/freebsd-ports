# Created by: Charlie & <root@dev2.rambler.ru>
# $FreeBSD$

PORTNAME=	Catalyst-Component-InstancePerContext
PORTVERSION=	0.001001
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Return a new instance a component on each request

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Runtime>=0:www/p5-Catalyst-Runtime	\
		p5-Moose>=0:devel/p5-Moose

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
