# New ports collection makefile for:	p5-Apache-GopherHandler
# Date created:				2004-03-31
# Whom:					Toni Viemerö <toni.viemero@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	Apache-GopherHandler
PORTVERSION=	0.1
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	toni.viemero@iki.fi
COMMENT=	Gopher protocol implementation for Apache2

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache2/mod_perl.pm:${PORTSDIR}/www/mod_perl2 \
		${SITE_PERL}/Gopher/Server/ParseRequest.pm:${PORTSDIR}/net/p5-Gopher-Server
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

BROKEN=		Broken due the new mod_perl2 API
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

MAN3=		Apache::GopherHandler.3 \
		Apache::GopherHandler::TiedSocket.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		"Needs perl 5.6.0 or higher, install lang/perl5 or lang/perl5.8 and try again"
.endif

.include <bsd.port.post.mk>
