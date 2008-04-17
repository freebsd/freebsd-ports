# New ports collection makefile for:	p5-Apache-GopherHandler
# Date created:				2004-03-31
# Whom:					Toni Viemerö <toni.viemero@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	Apache-GopherHandler
PORTVERSION=	0.1
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Gopher protocol implementation for Apache2

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2 \
		${SITE_PERL}/Gopher/Server/ParseRequest.pm:${PORTSDIR}/net/p5-Gopher-Server
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Apache::GopherHandler.3 \
		Apache::GopherHandler::TiedSocket.3

.include <bsd.port.mk>
