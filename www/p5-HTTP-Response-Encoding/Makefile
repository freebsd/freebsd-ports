# New ports collection makefile for:	p5-HTTP-Response-Encoding
# Date created:		2007-10-27
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Response-Encoding
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Adds encoding() to HTTP::Response

RUN_DEPENDS=	${SITE_PERL}/HTTP/Response.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		HTTP::Response::Encoding.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
IGNORE=		requires Perl 5.8.5 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
