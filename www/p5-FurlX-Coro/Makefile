# New ports collection makefile for:	FurlX::Coro
# Date created:		31 Dec 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	FurlX-Coro
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/G/GF/GFUJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for multiple HTTP requests with Coro

RUN_DEPENDS=	\
	p5-Coro>0:${PORTSDIR}/devel/p5-Coro \
	p5-Furl>0:${PORTSDIR}/www/p5-Furl
BUILD_DEPENDS=	\
	${RUN_DEPENDS} \
	p5-Test-Requires>0:${PORTSDIR}/devel/p5-Test-Requires

PERL_CONFIGURE=	yes

MAN3=	FurlX::Coro.3 \
	FurlX::Coro::HTTP.3

.include <bsd.port.mk>
