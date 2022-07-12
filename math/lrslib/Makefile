PORTNAME=	lrslib
PORTVERSION=	071a
CATEGORIES=	math
MASTER_SITES=	http://cgm.cs.mcgill.ca/~avis/C/lrslib/archive/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reverse search algorithm for vertex enumeration/convex hull problems

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	error: __int128 is not supported on this target
BROKEN_powerpc=	error: __int128 is not supported on this target
BROKEN_armv6=	error: __int128 is not supported on this target

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		compiler:c11 gmake libtool localbase:ldflags
USE_LDCONFIG=	yes

MAKEFILE=	makefile

ALL_TARGET=	all-shared

MAKE_ARGS=	CFLAGS="${CFLAGS}" INCLUDEDIR=${LOCALBASE}/include LIBDIR=${LOCALBASE}/lib

LDFLAGS+=	-lthr

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} bin/* lib/*.so

.include <bsd.port.mk>
