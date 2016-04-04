# $FreeBSD$

PORTNAME=	HTTP-MobileAgent-Plugin-Charset
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to plugin Encode::JP::Mobile for HTTP::MobileAgent

RUN_DEPENDS=	\
	p5-HTTP-MobileAgent>=0.26:www/p5-HTTP-MobileAgent
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
