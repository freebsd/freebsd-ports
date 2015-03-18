# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Plack-Middleware-MethodOverride
PORTVERSION=	0.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Override REST methods to Plack apps via POST

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Plack>=0:${PORTSDIR}/www/p5-Plack
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1.41:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.06:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
