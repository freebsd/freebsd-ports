# New ports collection makefile for:	p5-JavaScript-RPC
# Date created:		30 March 2006
# Whom:			Tony Shadwick <tshadwick@oss-solutions.com>
#
# $FreeBSD$
#

PORTNAME=	JavaScript-RPC
PORTVERSION=	0.3
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	JavaScript
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Remote procedure calls from JavaScript

PERL_CONFIGURE=	yes

MAN3=	JavaScript::RPC::Server::CGI.3 JavaScript::RPC.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires Perl 5.8.0 or superior. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
