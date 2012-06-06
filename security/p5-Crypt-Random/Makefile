# New ports collection makefile for:	p5-Crypt-Random
# Date created:				Tue Sep 11 10:47:19 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-Random
PORTVERSION=	1.25
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cryptographically Secure, True Random Number Generator

BUILD_DEPENDS=	p5-Math-Pari>=0:${PORTSDIR}/math/p5-Math-Pari \
		p5-Class-Loader>=0:${PORTSDIR}/devel/p5-Class-Loader
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Crypt::Random.3

.include <bsd.port.mk>
