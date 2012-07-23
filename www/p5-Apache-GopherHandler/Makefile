# New ports collection makefile for:	p5-Apache-GopherHandler
# Date created:				2004-03-31
# Whom:					Toni Viemerö <toni.viemero@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	Apache-GopherHandler
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Gopher protocol implementation for Apache2

RUN_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2 \
		p5-Gopher-Server>=0:${PORTSDIR}/net/p5-Gopher-Server
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_MODBUILD=	yes
USE_APACHE=	20+

MAN3=		Apache::GopherHandler.3 \
		Apache::GopherHandler::TiedSocket.3

.include <bsd.port.mk>
