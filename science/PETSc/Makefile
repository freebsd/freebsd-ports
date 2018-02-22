# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	PETSc
DISTVERSION=	3.8.3
CATEGORIES=	science devel
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/petsc/release-snapshots/
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Suite of data structures and routines from Argonne National Laboratory

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmpich.so:net/mpich2

USES=		blaslapack fortran gmake python:2.7 shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-shared-libraries=1 \
		--with-mpi-dir=${LOCALBASE} \
		CFLAGS="${CFLAGS} -msse2" CXXFLAGS="${CXXFLAGS} -msse2" CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" LIBS=""
USE_XORG=	x11
MAKEFILE=	makefile
SHEBANG_FILES=	bin/*.py bin/popup bin/saws/SAWs.py bin/saws/*.bash bin/sendToJenkins
USE_LDCONFIG=	yes
BINARY_ALIAS=	python=${PYTHON_CMD}

DATADIR=	${PREFIX}/share/${PORTNAME:tl}
PLIST_SUB=	SHLIB=${DISTVERSION} SHL=${DISTVERSION:C/\.[0-9]$//}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpetsc.so.${DISTVERSION}
	@${FIND} ${STAGEDIR}${PREFIX} \( -name "*.html" -o -name "*.mod" \) -delete
	@cd ${STAGEDIR}${PREFIX} && ${RM} -r bin/win32fe bin/uncrustify.cfg lib/petsc
	@${RM} -r ${STAGEDIR}${DATADIR}/examples # examples are a mess as installed

.include <bsd.port.mk>
