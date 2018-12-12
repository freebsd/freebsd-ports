# $FreeBSD$

PORTNAME=	libgridxc
DISTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	https://launchpad.net/${PORTNAME}/trunk/${DISTVERSION:R}/+download/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to compute the exchange and correlation energy and potentials

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../BSD_LICENSE

USES=		fortran gmake tar:tgz
USE_LDCONFIG=	yes

MAKEFILE=	makefile
ALL_TARGET=	default

WRKSRC_SUBDIR=	src

BUILD_WRKSRC=	${WRKSRC}/../build
TMP_STAGEDIR=	${WRKDIR}/tmp_stage
MAKE_ENV=	INSTALL_DIR=${TMP_STAGEDIR}${PREFIX} FREEBSD_LOCALBASE=${LOCALBASE} LIBXC_ROOT=${LOCALBASE}

BINARY_ALIAS=	make=${GMAKE}

OPTIONS_DEFINE=		MPI LIBXC
OPTIONS_DEFAULT=	MPI LIBXC

MPI_MAKE_ENV=		WITH_MPI=1
MPI_LIB_DEPENDS=	libmpich.so:net/mpich

LIBXC_DESC=		Use libxc for exchange-correlation functionals for DFT
LIBXC_MAKE_ENV=		WITH_LIBXC=1
LIBXC_LIB_DEPENDS=	libxc.so:science/libxc

post-patch:
	@${MKDIR} ${BUILD_WRKSRC}
	@${CAT} ${WRKSRC}/../extra/fortran.mk \
		| ${SED} '\
			s|FC_SERIAL=gfortran|&${GCC_DEFAULT}|; \
			s|FFLAGS= -O2|& -fPIC|' \
		> ${BUILD_WRKSRC}/fortran.mk

do-configure:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${SH} ../src/config.sh

do-build:
	@cd ${BUILD_WRKSRC} && ${MKDIR} ${TMP_STAGEDIR} && ${SETENV} ${MAKE_ENV} ${SH} ../src/build.sh

do-install:
	cd ${TMP_STAGEDIR} && ${COPYTREE_SHARE} . ${STAGEDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/mk && ${MV} ${STAGEDIR}${PREFIX}/*.mk ${STAGEDIR}${PREFIX}/share/mk

.include <bsd.port.mk>
