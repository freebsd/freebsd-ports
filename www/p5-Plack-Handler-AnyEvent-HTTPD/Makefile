# $FreeBSD$

PORTNAME=	Plack-Handler-AnyEvent-HTTPD
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Plack handler to run PSGI apps on AnyEvent::HTTPD

RUN_DEPENDS=	\
	p5-AnyEvent-HTTPD>0:www/p5-AnyEvent-HTTPD \
	p5-libwww>0:www/p5-libwww \
	p5-Plack>=0.9903:www/p5-Plack \
	p5-URI>0:net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-TCP>0:devel/p5-Test-TCP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
