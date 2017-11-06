# Created by: perl@FreeBSD.org
# $FreeBSD$

PORTNAME=	Crypt-RHash
PORTVERSION=	0.94
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Compute hash sums and magnet links

LICENSE=	MIT

BROKEN_aarch64=	Fails to build: error Cannot detect CPU architechture
BROKEN_mips64=	Fails to build: error Cannot detect CPU architechture

USES=		perl5
USE_PERL5=	configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/Rhash/Rhash.so

.include <bsd.port.mk>
