# New ports collection makefile for:	Plack::Middleware::ReverseProxy
# Date created:		03 Apr 2010
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Middleware-ReverseProxy
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to support app to run as a reverse proxy backend

RUN_DEPENDS=	\
	p5-Plack>0:${PORTSDIR}/www/p5-Plack \
	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Plack::Middleware::ReverseProxy.3

.include <bsd.port.mk>
