PORTNAME=	openmolcas
DISTVERSION=	22.02
PORTREVISION=	2
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum chemistry software package

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	build breaks: Symbol 'maxfilesize' at (1) has no IMPLICIT type; did you mean 'mxfile'?

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR}
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libsz.so:science/libaec \
		libxc.so:science/libxc

USES=		cmake fortran python shebangfix
USE_GCC=	yes # see https://gitlab.com/Molcas/OpenMolcas/-/issues/351

USE_GITLAB=	yes
GL_ACCOUNT=	Molcas
GL_PROJECT=	OpenMolcas
GL_COMMIT=	f8df69cf87b241a15ebc82d72a8f9a031a385dd4

USE_GITHUB=	nodefault
GH_TUPLE=	Reference-LAPACK:lapack:aa631b4b:lapack/External/lapack \
		libwfa:libwfa:bbe3392a:libwfa/External/libwfa

SHEBANG_FILES=	sbin/help_doc sbin/help_func sbin/help_basis sbin/setup sbin/verify sbin/version

CMAKE_ARGS=	-DEXTERNAL_LIBXC:STRING=${LOCALBASE} \
		-DFREEBSD_PYTHON_VER:STRING=${PYTHON_VER}
#CMAKE_ON=	# for EFPLIB, MSYM see https://gitlab.com/Molcas/OpenMolcas/-/issues/350, for WFA - hdf5 needs updating
CMAKE_OFF=	BUILD_TESTING

CMAKE_INSTALL_PREFIX=	${DATADIR} # installed into DATADIR because it doesn't respect UNIX file path conventions, see https://gitlab.com/Molcas/OpenMolcas/-/issues/352

BINARY_ALIAS=	cpp=${CPP} # cpp is called from cmake scripts

post-install:
	# remove unused static libraries, see https://gitlab.com/Molcas/OpenMolcas/-/issues/354
	@${RM} -r ${STAGEDIR}${CMAKE_INSTALL_PREFIX}/lib
	# remove unnecessary fines
	@${RM} ${STAGEDIR}${CMAKE_INSTALL_PREFIX}/CONTRIBUTORS.md
	@${RM} ${STAGEDIR}${CMAKE_INSTALL_PREFIX}/LICENSE
	# remove empty doc directory
	@${RMDIR} ${STAGEDIR}${DATADIR}/doc

.include <bsd.port.mk>
