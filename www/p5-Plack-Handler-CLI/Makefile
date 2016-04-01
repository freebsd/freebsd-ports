# $FreeBSD$

PORTNAME=	Plack-Handler-CLI
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for command line interface to PSGI applications

RUN_DEPENDS=	\
	p5-Mouse>0:devel/p5-Mouse \
	p5-Plack>=0.99:www/p5-Plack \
	p5-URI>0:net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-HTTP-Request-AsCGI>0:www/p5-HTTP-Request-AsCGI \
	p5-Test-Requires>0:devel/p5-Test-Requires \
	p5-Test-TCP>0:devel/p5-Test-TCP \
	p5-Router-Simple>0:www/p5-Router-Simple

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
