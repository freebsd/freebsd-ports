# Created by: will
# $FreeBSD$

PORTNAME=	Math-GMP
PORTVERSION=	2.13
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that provides an interface to the GMP library

LICENSE=	LGPL20+

BUILD_DEPENDS=	p5-Devel-CheckLib>=0.9:devel/p5-Devel-CheckLib
LIB_DEPENDS=	libgmp.so:math/gmp

USE_PERL5=	configure
USES=		localbase perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Math/GMP/GMP.so

.include <bsd.port.mk>
