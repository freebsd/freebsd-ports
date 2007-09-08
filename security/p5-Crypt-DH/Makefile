# New ports collection makefile for:    p5-Crypt-DH
# Date created:				2002/03/14
# Whom:					jesper
#
# $FreeBSD$
#

PORTNAME=	Crypt-DH
PORTVERSION=	0.06
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to a Diffie-Hellman key exchange system

PERL_CONFIGURE=	yes

MAN3=		Crypt::DH.3
PLIST_FILES=	%%SITE_PERL%%/Crypt/DH.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Crypt/DH/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Crypt/DH \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Crypt \
		%%SITE_PERL%%/Crypt

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS=	${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
