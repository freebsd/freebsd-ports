# ex:ts=8
# Ports collection makefile for:	p5-HTTP-Request-AsCGI
# Date created:			Nov 16, 2005
# Whom:				Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Request-AsCGI
PORTVERSION=	0.5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Setup a CGI enviroment from a HTTP::Request

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-libwww>=5.805:${PORTSDIR}/www/p5-libwww \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTTP::Request::AsCGI.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires at least Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
