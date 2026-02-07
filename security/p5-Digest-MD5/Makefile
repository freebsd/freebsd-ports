PORTNAME=	Digest-MD5
PORTVERSION=	2.59
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the MD5 algorithm
WWW=		https://metacpan.org/release/Digest-MD5

LICENSE=	ARTPERL10

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Digest/MD5/MD5.so

.include <bsd.port.mk>
