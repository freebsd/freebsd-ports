# New ports collection makefile for:	p5-Net-Random
# Date created:				Wed Dec 14 11:40:50 CST 2005
# Whom:	      				clsung
#
# $FreeBSD$
#

PORTNAME=	Net-Random
PORTVERSION=	1.3
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A perl5 module to get random data from online sources

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	YES

MAN3=		Net::Random.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
