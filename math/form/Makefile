# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	form
PORTVERSION=	4.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Symbolic Manipulation System

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		autoreconf gmake localbase
USE_GITHUB=	yes

GNU_CONFIGURE=	yes

GH_ACCOUNT=	vermaseren

OPTIONS_DEFINE=	DOXYGEN OPENMPI
OPTIONS_SUB=	yes

CONFIGURE_ARGS+=	--enable-scalar \
			--enable-largefile \
			--with-api=posix \
			--disable-native

MPICC?=			${LOCALBASE}/mpi/openmpi/bin/mpicc
MPICXX?=		${LOCALBASE}/mpi/openmpi/bin/mpic++

DOXYGEN_BROKEN=		fails to build
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

OPENMPI_CONFIGURE_ENABLE=	parform

OPENMPI_CONFIGURE_ENV+=	MPICC="${MPICC}" MPICXX="${MPICXX}"

OPENMPI_LIB_DEPENDS=	libmpi.so:net/openmpi \
			libgcc_s.so.1:lang/gcc5

post-patch:
	@${REINPLACE_CMD} -e 's| -O3||' ${WRKSRC}/configure.ac

post-build-DOXYGEN-on:
	(cd ${WRKSRC}/doc/manual; ${MAKE_CMD} html pdf)

post-install-DOXYGEN-on:
	(cd ${WRKSRC}/doc/manual && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/doc/manual/manual.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
