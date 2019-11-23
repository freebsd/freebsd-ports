# $FreeBSD$

PORTNAME=	nwchem
DISTVERSIONPREFIX=	v
DISTVERSION=	7.0.0
DISTVERSIONSUFFIX=	-beta1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance computational chemistry software

LICENSE=	ECL20
LICENSE_NAME=	Educational Community License (ECL) 2.0
LICENSE_FILE=	${WRKSRC}/../LICENSE.TXT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libblas.so:math/blas \
		libga.so:devel/ga \
		libmpich.so:net/mpich
RUN_DEPENDS=	nwchem-data>0:science/nwchem-data

USES=		fortran gmake perl5 shebangfix
SHEBANG_FILES=	../contrib/distro-tools/build_* ../contrib/add_* config/64_to_32
SHEBANG_GLOB=	*.sh
USE_GITHUB=	yes
GH_ACCOUNT=	nwchemgit
USE_PERL5=	build

MAKEFILE=	GNUmakefile
ARCH_64BIT=	${ARCH:C/.*64.*/64/:S/${ARCH}//}
MAKE_ENV=	NWCHEM_TOP=${WRKSRC}/.. NWCHEM_MODULES=all NWCHEM_LONG_PATHS=Y NWCHEM_TARGET=LINUX${ARCH_64BIT} USE_MPI=Y USE_INTERNALBLAS=Y EXTERNAL_GA_PATH=${LOCALBASE} \
		BLAS_SIZE=4 USE_64TO32=y

SUB_FILES=	nwchemrc

WRKSRC_SUBDIR=	src

BINARY_ALIAS=	gcc=${CC} gfortran=gfortran${GCC_DEFAULT}

PLIST_FILES=	bin/nwchem etc/nwchemrc

post-extract:
	@${RM} ${WRKSRC}/atomscf/src.orig

post-patch:
	@${REINPLACE_CMD} 's|nwchrc="/etc/nwchemrc"|nwchrc="${PREFIX}/etc/nwchemrc"|' ${WRKSRC}/util/util_nwchemrc.F

pre-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} nwchem_config && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} 64_to_32

do-install:
	${INSTALL_DATA} ${WRKDIR}/nwchemrc ${STAGEDIR}${PREFIX}/etc/nwchemrc
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/LINUX${ARCH_64BIT}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-test:
	@cd ${WRKSRC}/../QA && NWCHEM_TOP=${WRKSRC}/.. NWCHEM_TARGET=LINUX64 ./doqmtests.mpi

.include <bsd.port.mk>
