# New ports collection makefile for:	p5-Crypt-DSA
# Date created:				Tue Sep 11 10:31:23 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-DSA
PORTVERSION=	0.12
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	mharo@FreeBSD.org

PERLBASE=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

BUILD_DEPENDS=	${PERLBASE}/Crypt/Random.pm:${PORTSDIR}/security/p5-Crypt-Random \
		${PERLBASE}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${PERLBASE}/${PERL_ARCH}/Math/Pari.pm:${PORTSDIR}/math/p5-Math-Pari \
		${PERLBASE}/Convert/PEM.pm:${PORTSDIR}/converters/p5-Convert-PEM

RESTRICTED=	"Crypto; export-controlled"

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Crypt::DSA::Key::SSH2.3 Crypt::DSA.3 Crypt::DSA::Key.3 \
		Crypt::DSA::Key::PEM.3 Crypt::DSA::Signature.3 \
		Crypt::DSA::KeyChain.3 Crypt::DSA::Util.3

.include <bsd.port.mk>
