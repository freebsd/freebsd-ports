# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Plack-Middleware-ForceEnv
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Force set environment variables for testing

BUILD_DEPENDS=	p5-Plack>=0.9925:${PORTSDIR}/www/p5-Plack
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN3=		Plack::Middleware::ForceEnv.3

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
