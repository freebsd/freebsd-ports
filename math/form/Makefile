PORTNAME=	form
PORTVERSION=	4.3.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	math

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	28e15eaf0856a0a012795298d6a4b570e764a8b1.patch:-p1 # https://github.com/vermaseren/form/issues/422

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Symbolic Manipulation System
WWW=		https://www.nikhef.nl/~form/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		autoreconf gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	vermaseren

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

post-build-DOXYGEN-on:
	(cd ${WRKSRC}/doc/manual; ${MAKE_CMD} html pdf)

post-install-DOXYGEN-on:
	(cd ${WRKSRC}/doc/manual && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/doc/manual/manual.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
