# New ports collection makefile for:    p5-Crypt-DH
# Date created:				2002/03/14
# Whom:					jesper
#
# $FreeBSD$
#

PORTNAME=	Crypt-DH
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	jesper@FreeBSD.org
COMMENT=	Perl5 interface to a Diffie-Hellman key exchange system

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Math/Pari.pm:${PORTSDIR}/math/p5-Math-Pari \
		${SITE_PERL}/Crypt/Random.pm:${PORTSDIR}/security/p5-Crypt-Random
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Crypt::DH.3
PLIST_FILES=	%%SITE_PERL%%/Crypt/DH.pm \
		%%SITE_PERL%%/%%PERL_ARCH%%/auto/Crypt/DH/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/Crypt/DH

.include <bsd.port.mk>
