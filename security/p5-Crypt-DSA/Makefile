# New ports collection makefile for:	p5-Crypt-DSA
# Date created:				Tue Sep 11 10:31:23 PDT 2001
# Whom:	      				Michael Haro <mharo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-DSA
PORTVERSION=	1.16
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DSA signature and key generation

RUN_DEPENDS=	${SITE_PERL}/Math/BigInt.pm:${PORTSDIR}/math/p5-Math-BigInt \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/Convert/PEM.pm:${PORTSDIR}/converters/p5-Convert-PEM \
		${SITE_PERL}/Data/Buffer.pm:${PORTSDIR}/misc/p5-Data-Buffer \
		p5-File-Which>=0.05:${PORTSDIR}/sysutils/p5-File-Which
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Crypt::DSA::Key::SSH2.3 Crypt::DSA.3 Crypt::DSA::Key.3 \
		Crypt::DSA::Key::PEM.3 Crypt::DSA::Signature.3 \
		Crypt::DSA::KeyChain.3 Crypt::DSA::Util.3

.include <bsd.port.mk>
