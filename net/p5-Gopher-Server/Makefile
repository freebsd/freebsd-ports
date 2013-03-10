# Created by: Toni Viemer <toni.viemero@iki.fi>
# $FreeBSD$

PORTNAME=	Gopher-Server
PORTVERSION=	0.1.1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TMURRAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Backend for Gopher Servers

DEPRECATED=	Depends on p5-Net-Gopher which is deprecated and expired
EXPIRATION_DATE=	2013-04-10

RUN_DEPENDS=	p5-Net-Gopher>=0:${PORTSDIR}/net/p5-Net-Gopher \
				p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy \
				p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Gopher::Server::ParseRequest.3 \
		Gopher::Server::RequestHandler.3 \
		Gopher::Server::RequestHandler::DBI.3 \
		Gopher::Server::RequestHandler::File.3 \
		Gopher::Server::Response.3 \
		Gopher::Server::TypeMapper.3

.include <bsd.port.mk>
