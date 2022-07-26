PORTNAME=	openmolcas
DISTVERSION=	22.06
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum chemistry software package

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	build breaks: Symbol 'maxfilesize' at (1) has no IMPLICIT type; did you mean 'mxfile'?

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR} \
		chemps2:science/chemps2
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libsz.so:science/libaec \
		libxc.so:science/libxc

USES=		cmake:testing fortran python shebangfix
USE_GCC=	yes # see https://gitlab.com/Molcas/OpenMolcas/-/issues/351

USE_GITLAB=	yes
GL_ACCOUNT=	Molcas
GL_PROJECT=	OpenMolcas
GL_COMMIT=	17238da5c339c41ddf14ceb88f139d57143d7a14

USE_GITHUB=	nodefault
GH_TUPLE=	Reference-LAPACK:lapack:aa631b4b:lapack/External/lapack \
		ilyak:libefp:7d1ff5fd:libefp/External/efp \
		mcodev31:libmsym:0c47befe:libmsym/External/libmsym \
		libwfa:libwfa:bbe3392a:libwfa/External/libwfa

SHEBANG_FILES=	sbin/help_doc sbin/help_func sbin/help_basis sbin/setup sbin/verify sbin/version
SHEBANG_GLOB=	*.py

CMAKE_ON=	CHEMPS2 EFPLIB MSYM # TODO GEN1INT - package doesn't install itself, WFA - breaks due to https://gitlab.com/conradsnicta/armadillo-code/-/issues/216
CMAKE_ARGS=	-DEXTERNAL_LIBXC:STRING=${LOCALBASE} \
		-DFREEBSD_PYTHON_VER:STRING=${PYTHON_VER}
CMAKE_OFF=	BUILD_TESTING

CMAKE_INSTALL_PREFIX=	${DATADIR} # installed into DATADIR because it doesn't respect UNIX file path conventions, see https://gitlab.com/Molcas/OpenMolcas/-/issues/352

BINARY_ALIAS=	cpp=${CPP} # cpp is called from cmake scripts
BINARY_ALIAS+=	python3=${PYTHON_CMD} # cpp is called from cmake scripts

post-patch:
	# fix python path
	@${REINPLACE_CMD} -e "s|'/usr/bin/env python3'|'${PYTHON_CMD}'|" ${WRKSRC}/Tools/pymolcas/export.py

post-install:
	# remove unused static libraries, see https://gitlab.com/Molcas/OpenMolcas/-/issues/354
	@${RM} -r ${STAGEDIR}${CMAKE_INSTALL_PREFIX}/lib
	# remove unnecessary fines
	@${RM} ${STAGEDIR}${CMAKE_INSTALL_PREFIX}/CONTRIBUTORS.md
	@${RM} ${STAGEDIR}${CMAKE_INSTALL_PREFIX}/LICENSE
	# remove empty include directory
	@${RMDIR} ${STAGEDIR}${DATADIR}/include
	# remove empty doc directory
	@${RMDIR} ${STAGEDIR}${DATADIR}/doc

post-test: # A total of 5 test(s) failed, with 3 critical failure(s), see https://gitlab.com/Molcas/OpenMolcas/-/issues/369
	@cd ${BUILD_WRKSRC} && ${STAGEDIR}${DATADIR}/pymolcas verify

.include <bsd.port.mk>
