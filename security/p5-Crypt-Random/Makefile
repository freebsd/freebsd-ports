# New ports collection makefile for:	p5-Crypt-Random
# Date created:				Tue Sep 11 10:47:19 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-Random
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	mharo@FreeBSD.org
COMMENT=	Cryptographically Secure, True Random Number Generator

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Math/Pari.pm:${PORTSDIR}/math/p5-Math-Pari \
		${SITE_PERL}/Class/Loader.pm:${PORTSDIR}/devel/p5-Class-Loader
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Crypt::Random.3

.include <bsd.port.mk>
