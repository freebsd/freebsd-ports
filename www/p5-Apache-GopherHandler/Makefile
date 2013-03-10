# Created by: Toni Viemerö <toni.viemero@iki.fi>
# $FreeBSD$

PORTNAME=	Apache-GopherHandler
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Gopher protocol implementation for Apache2

DEPRECATED=	Depends on p5-Net-Gopher which is deprecated and expired
EXPIRATION_DATE=	2013-04-10

RUN_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2 \
		p5-Gopher-Server>=0:${PORTSDIR}/net/p5-Gopher-Server
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_MODBUILD=	yes
USE_APACHE=	22+

MAN3=		Apache::GopherHandler.3 \
		Apache::GopherHandler::TiedSocket.3

.include <bsd.port.mk>
