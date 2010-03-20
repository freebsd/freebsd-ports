# New ports collection makefile for:	p5-HTTP-Server-Simple-PSGI
# Date created:		2010-03-16
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	HTTP-Server-Simple-PSGI
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@c0decafe.net
COMMENT=	PSGI handler for HTTP::Server::Simple

RUN_DEPENDS=	${SITE_PERL}/HTTP/Server/Simple.pm:${PORTSDIR}/www/p5-HTTP-Server-Simple

USE_PERL5=	YES
PERL_CONFIGURE=	YES

MAN3=		HTTP::Server::Simple::PSGI.3

.include <bsd.port.mk>
