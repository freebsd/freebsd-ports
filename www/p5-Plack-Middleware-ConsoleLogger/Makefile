# New ports collection makefile for:	Plack::Middleware::ConsoleLogger
# Date created:		16 May 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Middleware-ConsoleLogger
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to write logs to Firebug or Webkit Inspector

RUN_DEPENDS=	\
	p5-Plack>=0.99:${PORTSDIR}/www/p5-Plack \
	p5-JavaScript-Value-Escape>0:${PORTSDIR}/lang/p5-JavaScript-Value-Escape
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=	Plack::Middleware::ConsoleLogger.3

.include <bsd.port.mk>
