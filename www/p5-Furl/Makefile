# New ports collection makefile for:	Furl
# Date created:		09 Jul 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Furl
PORTVERSION=	0.38
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOKUHIROM
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of lightning-fast URL fetcher

RUN_DEPENDS=	\
	p5-HTTP-Parser-XS>=0.11:${PORTSDIR}/www/p5-HTTP-Parser-XS
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-TCP>=0:${PORTSDIR}/devel/p5-Test-TCP

PERL_CONFIGURE=	yes

MAN3=	Furl.3 \
	Furl::HTTP.3 \
	Furl::Headers.3 \
	Furl::Response.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
TEST_DEPENDS+=	p5-Test-Simple>=0.96:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
