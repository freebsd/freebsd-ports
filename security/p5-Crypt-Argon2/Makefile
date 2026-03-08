PORTNAME=	Crypt-Argon2
DISTVERSION=	0.030
CATEGORIES=	security
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LEONT
PKGNAMEPREFIX=	p5-

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	Perl interface to the Argon2 key derivation functions
WWW=		https://metacpan.org/release/Crypt-Argon2

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/README

MY_DEPENDS=	p5-Pod-Coverage-TrustPod>0:devel/p5-Pod-Coverage-TrustPod \
		p5-Test-Pod>0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>1.08:devel/p5-Test-Pod-Coverage
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		perl5
USE_PERL5=	distbuild

_PERL_LIB=	${LOCALBASE}/lib/perl5/${PERL_VER}/mach/CORE

post-configure:
	${REINPLACE_CMD} -e "s|-Wl|-Wl,-L${_PERL_LIB},-lperl|" \
		${WRKSRC}/_build/graph

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/Argon2/Argon2.so

.include <bsd.port.mk>
