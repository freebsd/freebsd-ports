# Created by: will
# $FreeBSD$

PORTNAME=	Math-GMP
PORTVERSION=	2.11
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that provides an interface to the GMP library

LICENSE=	LGPL20 LGPL21 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Devel-CheckLib>=0.9:devel/p5-Devel-CheckLib
LIB_DEPENDS=	libgmp.so:math/gmp

CONFIGURE_ARGS=	INC=-I${LOCALBASE}/include LIBS="-L${LOCALBASE}/lib -lgmp"
USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/GMP/GMP.so

.include <bsd.port.mk>
