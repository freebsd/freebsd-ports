# $FreeBSD$

PORTNAME=	Plack-Middleware-Throttle
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of rate-limiting incoming HTTP requests for Plack

RUN_DEPENDS=	\
	p5-DateTime>0:devel/p5-DateTime \
	p5-libwww>0:www/p5-libwww \
	p5-Moose>0:devel/p5-Moose \
	p5-Plack>0:www/p5-Plack
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
