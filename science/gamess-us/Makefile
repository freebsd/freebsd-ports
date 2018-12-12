# $FreeBSD$

PORTNAME=	gamess
DISTVERSION=	20181013
PORTREVISION=	3
CATEGORIES=	science
PKGNAMESUFFIX=	-us # "US" fork
DISTNAME=	gamess-current

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General Atomic and Molecular Electronic Structure System (US)

LICENSE=	GAMESS_LICENSE
LICENSE_NAME=	GAMESS User License Agreement
LICENSE_FILE=	${FILESDIR}/license.txt
LICENSE_PERMS=	# none

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	only implemented for 64 and 32 bit Intel architectures
BROKEN_i386=	Integer too big for its kind at (1) (in file quanpo.f:16518:34)

USES=		fortran gmake

WRKSRC=		${WRKDIR}/gamess

BINARY_ALIAS=	gcc=${CC} gfortran=gfortran${GCC_DEFAULT}

GAMES_VERNO=	00
GAMES_ENV=	GMS_PATH=${WRKSRC} GMS_BUILD_DIR=${WRKSRC} GMS_TARGET=${ARCH:S/amd64/linux64/:S/i386/linux32/} \
		GMS_FORTRAN=gfortran GMS_GFORTRAN_VERNO=7.3 \
		GMS_VERSION=${GAMES_VERNO} GMS_BUILD_PATH=${WRKSRC} \
		GMS_OPENMP=false GMS_BG_MODEL="" GMS_SUN_OS_VERNO="" GMS_MAC_OSX_VERNO="" \
		GMS_IFORT_VERNO="" GMS_SUN_FORT_VERNO="" GMS_L64_OPT="" GMS_MATHLIB="${GMS_MATHLIB}" GMS_MATHLIB_PATH=${LOCALBASE}/lib \
		GMS_MKL_VERNO="" GMS_DDI_COMM="sockets" GMS_MPI_LIB="" GMS_MPI_PATH="" GMS_MVAPICH2_VERNO="" \
		GMS_OFED_PATH="" GMS_ARMCI_PATH="" GMS_MSUCC="" GMS_LIBCCHEM="" GMS_PHI="" GMS_SHMTYPE="posix"

PLIST_SUB+=	GAMES_VERNO=${GAMES_VERNO}
SUB_LIST+=	GAMES_VERNO=${GAMES_VERNO}
SUB_FILES=	pkg-message

OPTIONS_RADIO=		MATHLIB
OPTIONS_RADIO_MATHLIB=	ATLAS OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS
MATHLIB_DESC=		Math library

ATLAS_VARS=		GMS_MATHLIB=atlas
ATLAS_LIB_DEPENDS=	libatlas.so:math/atlas

OPENBLAS_VARS=		GMS_MATHLIB=openblas
OPENBLAS_LIB_DEPENDS=	libopenblas.so:math/openblas

.include <bsd.port.pre.mk>

# Check for gamess sources and prompt how to download them
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	license restrictions require registration and manual fetching of the distribution\
	source. Please visit https://www.msg.chem.iastate.edu/gamess/License_Agreement.html\
	with a browser. You will be required to agree to the license terms, enter your e-mail\
	address, check any box under "Source Code Distributions", and submit your download request.\
	Once you download the file ${DISTFILES}, please put it into ${DISTDIR}/${DISTFILES} and\
	run 'make' again
.endif

do-configure:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GAMES_ENV} ./config

do-build:
	@cd ${WRKSRC}/ddi && ${SETENV} ${MAKE_ENV} ./compddi && ${MV} ddikick.x ..
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./compall
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./lked gamess ${GAMES_VERNO}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rungms ${STAGEDIR}${PREFIX}/bin
	@${REINPLACE_CMD} -i '' 's|^set GMSPATH=.*|set GMSPATH=${DATADIR}|' ${STAGEDIR}${PREFIX}/bin/rungms
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gamess.${GAMES_VERNO}.x ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/ddikick.x ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/gms-files.csh ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/tools
	${INSTALL_SCRIPT} ${WRKSRC}/tools/remd.csh ${STAGEDIR}${DATADIR}/tools/remd.csh
	cd ${WRKSRC} && ${COPYTREE_SHARE} auxdata ${STAGEDIR}${DATADIR}/

do-test:
	@${REINPLACE_CMD} -i '' 's|^set GMSPATH=.*|set GMSPATH=${WRKSRC}|' ${WRKSRC}/rungms
	@cd ${WRKSRC} && \
		${MKDIR} ../gamess-devv && \
		${SETENV} ${MAKE_ENV} ./runall ${GAMES_VERNO} && \
		${SETENV} ${MAKE_ENV} tests/standard/checktst

.include <bsd.port.post.mk>
