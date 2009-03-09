# New ports collection makefile for:	Catalyst-Engine-HTTP-Prefork
# Date created:	   18 Apr 2008
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Engine-HTTP-Prefork
PORTVERSION=	0.50
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	High-performance pre-forking Catalyst engine

RUN_DEPENDS=	p5-Catalyst-Runtime>=5.7012:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Net-Server>=0.97:${PORTSDIR}/net/p5-Net-Server \
		${SITE_PERL}/${PERL_ARCH}/HTTP/HeaderParser/XS.pm:${PORTSDIR}/www/p5-HTTP-HeaderParser-XS \
		${SITE_PERL}/${PERL_ARCH}/Cookie/XS.pm:${PORTSDIR}/www/p5-CGI-Cookie-XS \
		${SITE_PERL}/HTTP/Body.pm:${PORTSDIR}/www/p5-HTTP-Body
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=		Catalyst::Engine::HTTP::Prefork.3

.include <bsd.port.mk>
