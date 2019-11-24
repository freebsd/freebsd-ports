# $FreeBSD$

PORTNAME=	fplll
DISTVERSION=	5.3.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lattice algorithms using floating-point arithmetic

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		autoreconf compiler:c++11-lang gmake libtool localbase:ldflags
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GITHUB=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
