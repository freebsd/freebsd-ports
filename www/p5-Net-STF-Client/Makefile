# $FreeBSD$

PORTNAME=	Net-STF-Client
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for STF Client

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:devel/p5-Class-Accessor-Lite \
	p5-Furl>0:www/p5-Furl \
	p5-libwww>0:www/p5-libwww \
	p5-URI>0:net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-Test-Requires>0:devel/p5-Test-Requires \
	p5-Test-TCP>0:devel/p5-Test-TCP \
	p5-Test-Simple>0:devel/p5-Test-Simple \
	p5-Plack>0:www/p5-Plack

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
