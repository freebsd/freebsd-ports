# New ports collection makefile for:    p5-Crypt-OpenSSL-DSA
# Date created:				2002/09/20
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Crypt-OpenSSL-DSA
PORTVERSION=	0.13
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to DSA signature verification using OpenSSL

PERL_CONFIGURE=	yes

MAN3=		Crypt::OpenSSL::DSA.3 Crypt::OpenSSL::DSA::Signature.3

post-patch:
	@${RM} ${WRKSRC}/lib/Crypt/OpenSSL/DSA.pm.orig

.include <bsd.port.mk>
