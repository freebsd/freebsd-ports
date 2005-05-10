# New ports collection makefile for:	HTTP::Server::Simple::Mason
# Date created:				28 April 2005
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Server-Simple-Mason
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	An abstract baseclass for a standalone mason server

BUILD_DEPENDS=	${SITE_PERL}/HTTP/Server/Simple.pm:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		${SITE_PERL}/Apache/Mason.pm:${PORTSDIR}/www/p5-HTML-Mason \
		${SITE_PERL}/Hook/LexWrap.pm:${PORTSDIR}/devel/p5-Hook-LexWrap
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=yes

MAN3=	HTTP::Server::Simple::Mason.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=	requires Perl 5.6 or newer. Install lang/perl5 or lang/perl5.8, and try again
.endif

.include <bsd.port.post.mk>
