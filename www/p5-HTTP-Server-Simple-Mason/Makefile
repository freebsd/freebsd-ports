# New ports collection makefile for:	HTTP::Server::Simple::Mason
# Date created:				28 April 2005
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Server-Simple-Mason
PORTVERSION=	0.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	An abstract baseclass for a standalone mason server

BUILD_DEPENDS=	${SITE_PERL}/HTTP/Server/Simple.pm:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		${SITE_PERL}/Apache/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason \
		${SITE_PERL}/Hook/LexWrap.pm:${PORTSDIR}/devel/p5-Hook-LexWrap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=yes

MAN3=	HTTP::Server::Simple::Mason.3

.include <bsd.port.mk>
