PORTNAME=	fplll
DISTVERSION=	5.4.5
CATEGORIES=	math
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lattice algorithms using floating-point arithmetic
WWW=		https://github.com/fplll/fplll

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libqd.so:math/qd

USES=		autoreconf compiler:c++11-lang gmake libtool localbase:ldflags pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

TEST_TARGET=	check

.include <bsd.port.mk>
