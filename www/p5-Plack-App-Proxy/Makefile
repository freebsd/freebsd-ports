# $FreeBSD$

PORTNAME=	Plack-App-Proxy
PORTVERSION=	0.25
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LEEDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Plack extension for proxy requests

RUN_DEPENDS=	\
	p5-AnyEvent-HTTP>=1.44:${PORTSDIR}/www/p5-AnyEvent-HTTP \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-Plack>=0.9913:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires \
	p5-Test-TCP>0:${PORTSDIR}/devel/p5-Test-TCP

PERL_CONFIGURE=	yes

MAN3=	Plack::App::Proxy.3 \
	Plack::App::Proxy::Backend.3 \
	Plack::App::Proxy::Backend::AnyEvent::HTTP.3 \
	Plack::App::Proxy::Backend::LWP.3 \
	Plack::App::Proxy::Test.3 \
	Plack::Middleware::Proxy::AddVia.3 \
	Plack::Middleware::Proxy::Connect.3 \
	Plack::Middleware::Proxy::LoadBalancer.3 \
	Plack::Middleware::Proxy::RewriteLocation.3

.include <bsd.port.mk>
