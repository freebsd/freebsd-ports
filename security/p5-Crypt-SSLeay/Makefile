# Created by: Alfred Perlstein <alfred@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-SSLeay
PORTVERSION=	0.72
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to allow p5-libwww LWP to make https connections

LICENSE=	ART20

BUILD_DEPENDS=	p5-LWP-Protocol-https>=6.02:www/p5-LWP-Protocol-https \
		p5-Path-Class>=0.26:devel/p5-Path-Class \
		p5-Try-Tiny>=0.19:lang/p5-Try-Tiny
RUN_DEPENDS=	p5-LWP-Protocol-https>=6.02:www/p5-LWP-Protocol-https

USES=		perl5
USE_PERL5=	configure
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--no-live-tests

.include <bsd.port.mk>
