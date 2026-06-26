PORTNAME=	Crypt-SysRandom-XS
PORTVERSION=	0.011
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LEONT
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl interface to system randomness, XS version
WWW=		https://metacpan.org/dist/Crypt-SysRandom-XS

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	distbuild

post-configure:
	@${REINPLACE_CMD} -e 's|-Wl|&,-L${LOCALBASE}/lib/perl5/${PERL_VER}/mach/CORE,-lperl|' ${WRKSRC}/_build/graph

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/SysRandom/XS/XS.so

.include <bsd.port.mk>
