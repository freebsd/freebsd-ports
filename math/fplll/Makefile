PORTNAME=	fplll
DISTVERSION=	5.4.1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lattice algorithms using floating-point arithmetic

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libqd.so:math/qd

USES=		autoreconf compiler:c++11-lang gmake libtool localbase:ldflags pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GITHUB=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

TEST_TARGET=	check

.include <bsd.port.mk>
