PORTNAME=	Digest-SipHash
PORTVERSION=	0.21
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Perl XS interface to the SipHash algorithm
WWW=		https://metacpan.org/dist/Digest-SipHash

LICENSE=	ART20

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Digest/SipHash/SipHash.so

.include <bsd.port.mk>
