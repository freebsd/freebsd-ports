# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Crypt-Curve25519
PORTVERSION=	0.05
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate shared secret using elliptic-curve Diffie-Hellman function

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=		Fails to install: error adding symbols: File in wrong format
BROKEN_mips=	Fails to build: -m32 flag is not supported by this configuration
BROKEN_mips64=	Fails to build: -m32 flag is not supported by this configuration
BROKEN_powerpc64=	Fails to build: architecture of input file is incompatible with powerpc:common64 output
BROKEN_sparc64=	Fails to build: -m32 flag is not supported by this configuration

USE_PERL5=	configure
USES=		perl5 ssl

MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/Curve25519/Curve25519.so

.include <bsd.port.mk>
