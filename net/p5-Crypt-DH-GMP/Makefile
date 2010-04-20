# New ports collection makefile for:  Crypt-DH-GMP
# Date created: 04 February 2010
# Whom: andrey@kostenko.name
#
# $FreeBSD$

PORTNAME=	Crypt-DH-GMP
PORTVERSION=	0.00006
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Crypt::DH Using GMP Directly

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

PERL_CONFIGURE=	YES
MAN3=	Crypt::DH::GMP.3 \
	Crypt::DH::GMP::Compat.3

.include <bsd.port.mk>
