# $FreeBSD$

PORTNAME=	FurlX-Coro
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GFUJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for multiple HTTP requests with Coro

RUN_DEPENDS=	\
	p5-Coro>0:devel/p5-Coro \
	p5-Furl>0:www/p5-Furl
BUILD_DEPENDS=	\
	${RUN_DEPENDS} \
	p5-Test-Requires>0:devel/p5-Test-Requires

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
