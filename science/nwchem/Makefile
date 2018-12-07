# $FreeBSD$

PORTNAME=	nwchem
PORTVERSION=	6.8.1.20181107
CATEGORIES=	science

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	ce7c387b4f37c70947cb3b41a6beaf8fce628634.patch:-p2

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

USES=		fortran gmake ${ARCH_64BIT:S/^$/perl5/:S/64//} shebangfix
SHEBANG_FILES=	../contrib/distro-tools/build_* ../contrib/add_*
SHEBANG_GLOB=	*.sh
USE_GITHUB=	yes
GH_ACCOUNT=	nwchemgit
GH_TAGNAME=	master-oct22_2018-21-gd3913ef8b
USE_PERL5=	build

MAKEFILE=	GNUmakefile
ARCH_64BIT=	${ARCH:C/.*64.*/64/:S/${ARCH}//}
MAKE_ENV=	NWCHEM_TOP=${WRKSRC}/.. NWCHEM_MODULES=all NWCHEM_LONG_PATHS=Y NWCHEM_TARGET=LINUX${ARCH_64BIT} USE_MPI=Y USE_INTERNALBLAS=Y EXTERNAL_GA_PATH=${LOCALBASE} \
		BLAS_SIZE=4 USE_64TO32=y

SUB_FILES=	nwchemrc

WRKSRC_SUBDIR=	src

BINARY_ALIAS=	gcc=${CC} gfortran=gfortran${GCC_DEFAULT}

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
	cd ${WRKSRC}/basis && ${COPYTREE_SHARE} libraries ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/libraryps
.for d in development_psps HGH_LDA library1 library2 ofpw_default paw_default pspw_default pspw_new pspw_old Spin_Orbit TETER TM
	cd ${WRKSRC}/nwpw/libraryps && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR}/libraryps/
.endfor

.include <bsd.port.mk>
