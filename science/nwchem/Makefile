# $FreeBSD$

PORTNAME=	nwchem
DISTVERSION=	6.8.1-release-94
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g1a262862b
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-performance computational chemistry software

LICENSE=	ECL20
LICENSE_NAME=	Educational Community License (ECL) 2.0
LICENSE_FILE=	${WRKSRC}/../LICENSE.TXT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_i386=	Compiling basis.F...  f951: sorry, unimplemented: 64-bit mode not compiled in

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libblas.so:math/blas \
		libga.so:devel/ga \
		libmpich.so:net/mpich2

USES=		fortran gmake shebangfix
SHEBANG_FILES=	../contrib/distro-tools/build_* ../contrib/add_*
SHEBANG_GLOB=	*.sh
USE_GITHUB=	yes
GH_ACCOUNT=	nwchemgit
MAKEFILE=	GNUmakefile
MAKE_ENV=	NWCHEM_TOP=${WRKSRC}/.. NWCHEM_MODULES=all NWCHEM_LONG_PATHS=Y NWCHEM_TARGET=LINUX64 USE_MPI=Y USE_INTERNALBLAS=Y EXTERNAL_GA_PATH=${LOCALBASE} BLAS_SIZE=4

SUB_FILES=	nwchemrc

WRKSRC_SUBDIR=	src
BINARY_ALIAS=	gcc=${CC}

post-patch:
	@${REINPLACE_CMD} 's|nwchrc="/etc/nwchemrc"|nwchrc="${PREFIX}/etc/nwchemrc"|' ${WRKSRC}/util/util_nwchemrc.F

do-install:
	${INSTALL_DATA} ${WRKDIR}/nwchemrc ${STAGEDIR}${PREFIX}/etc/nwchemrc
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/LINUX64/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}.shadow
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "LD_PRELOAD=${PREFIX}/lib/gcc${GCC_DEFAULT}/libgcc_s.so ${PREFIX}/bin/${PORTNAME}.shadow \""$$"@\"" \
	) > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/basis && ${COPYTREE_SHARE} libraries ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/libraryps
.for d in development_psps HGH_LDA library1 library2 ofpw_default paw_default pspw_default pspw_new pspw_old Spin_Orbit TETER TM
	cd ${WRKSRC}/nwpw/libraryps && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR}/libraryps/
.endfor

.include <bsd.port.mk>
