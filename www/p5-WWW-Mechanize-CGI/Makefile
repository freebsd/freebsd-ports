# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Mechanize-CGI
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Use WWW::Mechanize with CGI applications

RUN_DEPENDS=	p5-HTTP-Request-AsCGI>=0.2:www/p5-HTTP-Request-AsCGI \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
