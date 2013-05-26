# $FreeBSD$

PORTNAME=	Monoceros
PORTVERSION=	0.15
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KAZEBURO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	PSGI/Plack server w/ event driven connection manager, prefork workers

RUN_DEPENDS=	\
	p5-AnyEvent>=7.04:${PORTSDIR}/devel/p5-AnyEvent \
	p5-IO-FDPass>=1.0:${PORTSDIR}/devel/p5-IO-FDPass \
	p5-Net-CIDR-Lite>0:${PORTSDIR}/net/p5-Net-CIDR-Lite \
	p5-Plack>=1.0023:${PORTSDIR}/www/p5-Plack \
	p5-Starlet>=0.18:${PORTSDIR}/www/p5-Starlet
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-TCP>0:${PORTSDIR}/devel/p5-Test-TCP

PERL_MODBUILD=	yes

MAN3=	Monoceros.3 \
	Plack::Middleware::MonocerosStatus.3

.include <bsd.port.mk>
