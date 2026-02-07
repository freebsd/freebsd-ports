PORTNAME=	form
DISTVERSION=	5.0.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/form-dev/form/releases/download/v${DISTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Symbolic Manipulation System
WWW=		https://www.nikhef.nl/~form/ \
		https://github.com/form-dev/form

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libzstd.so:archivers/zstd

USES=		autoreconf gmake localbase

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-native \
			--enable-largefile \
			--enable-scalar \
			--with-api=posix

OPTIONS_DEFINE=	DOXYGEN OPENMPI
OPTIONS_SUB=	yes

MPICC?=		${LOCALBASE}/mpi/openmpi/bin/mpicc
MPICXX?=	${LOCALBASE}/mpi/openmpi/bin/mpic++

DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
OPENMPI_LIB_DEPENDS=		libgcc_s.so.1:lang/gcc9 \
				libmpi.so:net/openmpi
OPENMPI_CONFIGURE_ENABLE=	parform
OPENMPI_CONFIGURE_ENV+=		MPICC="${MPICC}" \
				MPICXX="${MPICXX}"

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-build-DOXYGEN-on:
	(cd ${WRKSRC}/doc/manual; ${MAKE_CMD} html pdf)

post-install-DOXYGEN-on:
	(cd ${WRKSRC}/doc/manual && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/doc/manual/manual.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
