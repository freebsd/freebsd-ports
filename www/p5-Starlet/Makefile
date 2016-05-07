# $FreeBSD$

PORTNAME=	Starlet
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KAZUHO
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for standalone HTTP/1.0 server

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Parallel-Prefork>=0.13:devel/p5-Parallel-Prefork \
	p5-Plack>=0.992:www/p5-Plack \
	p5-Server-Starter>=0.06:net/p5-Server-Starter
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-TCP>0:devel/p5-Test-TCP
# TODO: maybe need p5-libwww

USES=	perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
