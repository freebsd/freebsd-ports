PORTNAME=	FlintQS
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quadratic Sieve integer factorization algorithm
WWW=		http://www.friedspace.com/QS/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		autoreconf gmake localbase:ldflags
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	sagemath

USE_CXXSTD=	c++14 # fix compilation failure on 14 due to use of the 'register' keyword

PLIST_FILES=	bin/QuadraticSieve

.include <bsd.port.mk>
