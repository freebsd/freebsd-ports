# $FreeBSD$

PORTNAME=	CGI-Application-PSGI
PORTVERSION=	1.00
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of PSGI Adapter for CGI::Application

RUN_DEPENDS=	\
	p5-CGI-Application>0:www/p5-CGI-Application \
	p5-CGI-PSGI>0:www/p5-CGI-PSGI
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
