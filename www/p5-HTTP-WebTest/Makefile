# $FreeBSD$

PORTNAME=	HTTP-WebTest
PORTVERSION=	2.04
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Tests remote URLs or local web files

BUILD_DEPENDS=	\
	p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff \
	p5-libwww>=0:www/p5-libwww \
	p5-Test-MockObject>=0:devel/p5-Test-MockObject \

USES=		perl5
USE_PERL5=	configure
INSTALL_TARGET=	pure_install

.include <bsd.port.mk>
