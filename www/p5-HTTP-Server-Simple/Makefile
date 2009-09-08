# New ports collection makefile for:	www/p5-HTTP-Server-Simple
# Date created:				30 March 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Server-Simple
PORTVERSION=	0.40
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A very simple standalone HTTP daemon

RUN_DEPENDS=	p5-URI>0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTTP::Server::Simple.3 \
	HTTP::Server::Simple::CGI.3 \
	HTTP::Server::Simple::CGI::Environment.3

.include <bsd.port.mk>
