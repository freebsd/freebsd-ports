# New ports collection makefile for:  Crypt-DH-GMP
# Date created: 04 February 2010
# Whom: andrey@kostenko.name
#
# $FreeBSD$

PORTNAME=	Crypt-DH-GMP
PORTVERSION=	0.00006
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrey@kostenko.name
COMMENT=	Crypt::DH Using GMP Directly

RUN_DEPENDS=	libgmp>=0:${PORTSDIR}/math/libgmp4
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	YES
MAN3=	Crypt::DH::GMP.3 \
	Crypt::DH::GMP::Compat.3

.include <bsd.port.mk>
