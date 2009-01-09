# New ports collection makefile for:	www/p5-HTTP-Server-Simple-Recorder
# Date created:				27 December 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Server-Simple-Recorder
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Mixin to record HTTP::Server::Simple's sockets

BUILD_DEPENDS=	${SITE_PERL}/HTTP/Server/Simple.pm:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		${SITE_PERL}/Test/HTTP/Server/Simple.pm:${PORTSDIR}/www/p5-Test-HTTP-Server-Simple \
		${SITE_PERL}/IO/Tee.pm:${PORTSDIR}/devel/p5-IO-Tee
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	HTTP::Server::Simple::Recorder.3

.include <bsd.port.mk>
