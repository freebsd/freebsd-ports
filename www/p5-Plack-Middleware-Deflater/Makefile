# New ports collection makefile for:	Plack::Middleware::Deflater
# Date created:		30 Nov 2009
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Plack-Middleware-Deflater
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to compress response body with Gzip or Deflate

RUN_DEPENDS=	\
	p5-Plack>0:${PORTSDIR}/www/p5-Plack
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Plack::Middleware::Deflater.3

.include <bsd.port.mk>
