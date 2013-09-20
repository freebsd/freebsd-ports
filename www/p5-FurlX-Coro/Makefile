# $FreeBSD$

PORTNAME=	FurlX-Coro
PORTVERSION=	1.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GFUJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for multiple HTTP requests with Coro

RUN_DEPENDS=	\
	p5-Coro>0:${PORTSDIR}/devel/p5-Coro \
	p5-Furl>0:${PORTSDIR}/www/p5-Furl
BUILD_DEPENDS=	\
	${RUN_DEPENDS} \
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	modbuild

MAN3=	FurlX::Coro.3 \
	FurlX::Coro::HTTP.3

NO_STAGE=	yes
.include <bsd.port.mk>
