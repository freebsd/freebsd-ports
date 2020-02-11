# Created by: will
# $FreeBSD$

PORTNAME=	Math-GMP
PORTVERSION=	2.20
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that provides an interface to the GMP library

LICENSE=	LGPL20+

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		localbase perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e '/Alien::GMP/d' ${WRKSRC}/META.json ${WRKSRC}/META.yml ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e 's|Alien::Base::Wrapper->mm_args|"LIBS" => ["-lgmp"]|' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/GMP/GMP.so

.include <bsd.port.mk>
