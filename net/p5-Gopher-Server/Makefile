# New ports collection makefile for:	p5-Gopher-Server
# Date created:				2004-03-31
# Whom:					Toni Viemer?<toni.viemero@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	Gopher-Server
PORTVERSION=	0.1.1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/T/TM/TMURRAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Backend for Gopher Servers

RUN_DEPENDS=	${SITE_PERL}/Net/Gopher.pm:${PORTSDIR}/net/p5-Net-Gopher \
				${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
				${SITE_PERL}/Test/Exception.pm:${PORTSDIR}/devel/p5-Test-Exception
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Gopher::Server::ParseRequest.3 \
		Gopher::Server::RequestHandler.3 \
		Gopher::Server::RequestHandler::DBI.3 \
		Gopher::Server::RequestHandler::File.3 \
		Gopher::Server::Response.3 \
		Gopher::Server::TypeMapper.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"needs at least perl 5.6.0 to work"
.endif

.include <bsd.port.post.mk>
