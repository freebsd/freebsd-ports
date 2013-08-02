# Created by: Michael Haro <mharo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-DSA
PORTVERSION=	1.17
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DSA signature and key generation

RUN_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Convert-PEM>=0:${PORTSDIR}/converters/p5-Convert-PEM \
		p5-Data-Buffer>=0:${PORTSDIR}/misc/p5-Data-Buffer \
		p5-File-Which>=0.05:${PORTSDIR}/sysutils/p5-File-Which
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Crypt::DSA::Key::SSH2.3 Crypt::DSA.3 Crypt::DSA::Key.3 \
		Crypt::DSA::Key::PEM.3 Crypt::DSA::Signature.3 \
		Crypt::DSA::KeyChain.3 Crypt::DSA::Util.3

.include <bsd.port.mk>
