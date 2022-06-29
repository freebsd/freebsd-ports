# PORTNAME block
PORTNAME=	libnormaliz
DISTVERSION=	3.9.0
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	https://github.com/Normaliz/Normaliz/releases/download/v${PORTVERSION}/
DISTNAME=	normaliz-${PORTVERSION}

# MAINTAINER block
MAINTAINER=	moritz@schmi.tt
COMMENT=	Compute Hilbert bases and enumerative data of rational polyhedra

CONFLICTS_BUILD=	e-antic # math/e-antic should be a dependency but it fails: https://github.com/Normaliz/Normaliz/issues/380

# LICENSE block
LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

# Dependencies block
LIB_DEPENDS=	libgmp.so:math/gmp \
		libnauty.so:math/nauty

# USES block
USES=		autoreconf compiler:c++11-lang gmake libtool localbase
USE_LDCONFIG=	yes

# bsd.ports.mk block
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

TEST_TARGET=	check # at least one test is known to fail: https://github.com/Normaliz/Normaliz/issues/378

# Options block
OPTIONS_DEFINE=		COCOA DOCS FLINT OPENMP

COCOA_DESC=		Link with libcocoa.a (might cause circular dependency)
FLINT_DESC=		Link with libflint.so

COCOA_BUILD_DEPENDS=	${LOCALBASE}/lib/libcocoa.a:math/cocoalib
COCOA_CONFIGURE_WITH=	cocoalib
COCOA_BROKEN=		fails to compile a test program, see https://github.com/Normaliz/Normaliz/issues/379

FLINT_LIB_DEPENDS=	libflint.so:math/flint2 \
			libmpfr.so:math/mpfr
FLINT_CONFIGURE_WITH=	flint
FLINT_LDFLAGS=		-lpthread

OPENMP_CONFIGURE_ENABLE=	openmp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/Normaliz.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
