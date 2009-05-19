# New ports collection makefile for:    lapack
# Date created:         2 July 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	lapack
PORTVERSION=	3.2.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/lapack/ \
		http://netlib.org/lapack/ \
		http://scicomp.ewha.ac.kr/netlib/lapack/ \
		http://service-spi.web.cern.ch/service-spi/external/tarFiles/
DISTFILES=	lapack-${PORTVERSION}.tgz manpages-3.2.0.tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A library of Fortran 77 subroutines for linear algebra

LIB_DEPENDS=	blas.2:${PORTSDIR}/math/blas

USE_FORTRAN=	yes
DIST_SUBDIR=	lapack
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "amd64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

MANSRC=${WRKDIR}/lapack-3.2.0
WRKSRC_SHARED=${WRKSRC}_shared
FFLAGS_SHARED=${FPIC}
WRKSRC_PROFILE=${WRKSRC}_profile
FFLAGS_PROFILE=-pg

SVERSION=4
BLAS=	-L${LOCALBASE}/lib -lblas

pre-fetch:
	@${ECHO} "You can override F77 and FFLAGS on the command line."

.include "${FILESDIR}/manpages"

post-patch:
	@${CP} ${WRKSRC}/INSTALL/make.inc.gfortran ${WRKSRC}/make.inc
	@${CP} -r ${WRKSRC} ${WRKSRC_SHARED}
	@${CP} -r ${WRKSRC} ${WRKSRC_PROFILE}
	@${REINPLACE_CMD} -e 's,%%F77%%,${F77},g' \
			  -e 's,%%FFLAGS%%,${FFLAGS},g' \
			  -e 's,%%EXTRAFLAGS%%,,g' \
			  -e 's,%%BLAS%%,${BLAS},g' \
				${WRKSRC}/make.inc
	@${REINPLACE_CMD} -e 's,%%F77%%,${F77},g' \
			  -e 's,%%FFLAGS%%,${FFLAGS},g' \
			  -e 's,%%EXTRAFLAGS%%,${FFLAGS_SHARED},g' \
			  -e 's,%%BLAS%%,${BLAS},g' \
				${WRKSRC_SHARED}/make.inc
	@${REINPLACE_CMD} -e 's,%%F77%%,${F77},g' \
			  -e 's,%%FFLAGS%%,${FFLAGS},g' \
			  -e 's,%%EXTRAFLAGS%%,${FFLAGS_PROFILE},g' \
			  -e 's,%%BLAS%%,${BLAS},g' \
				${WRKSRC_PROFILE}/make.inc

do-build:
	@${ECHO_CMD} "Building static lapack library"
	cd ${WRKSRC} ; ${MAKE} ${.MAKEFLAGS} ARCH=ar
	@${ECHO_CMD} "Building shared lapack library"
	cd ${WRKSRC_SHARED} ; ${MAKE} ${.MAKEFLAGS} ARCH=ar
	@${ECHO_CMD} "Building profile lapack library"
	cd ${WRKSRC_PROFILE} ; ${MAKE} ${.MAKEFLAGS} ARCH=ar

post-build:
	${CP} ${WRKSRC}/lapack_FREEBSD.a ${WRKSRC}/liblapack.a
	${CP} ${WRKSRC}/tmglib_FREEBSD.a ${WRKSRC}/libtmglib.a
	${CP} ${WRKSRC_SHARED}/lapack_FREEBSD.a ${WRKSRC_SHARED}/liblapack.a
	${CP} ${WRKSRC_SHARED}/tmglib_FREEBSD.a ${WRKSRC_SHARED}/libtmglib.a
	${CP} ${WRKSRC_PROFILE}/lapack_FREEBSD.a ${WRKSRC_PROFILE}/liblapack_p.a
	${CP} ${WRKSRC_PROFILE}/tmglib_FREEBSD.a ${WRKSRC_PROFILE}/libtmglib_p.a
	cd ${WRKSRC_SHARED} ; ld -Bshareable -o liblapack.so.${SVERSION} -x -soname liblapack.so.${SVERSION} --whole-archive liblapack.a ; ${LN} -s liblapack.so.${SVERSION} liblapack.so
	cd ${WRKSRC_SHARED} ; ld -Bshareable -o libtmglib.so.${SVERSION} -x -soname libtmglib.so.${SVERSION} --whole-archive libtmglib.a ; ${LN} -s libtmglib.so.${SVERSION} libtmglib.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/liblapack.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libtmglib.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC_SHARED}/liblapack.so.${SVERSION} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC_SHARED}/libtmglib.so.${SVERSION} ${PREFIX}/lib
	${LN} -sf liblapack.so.${SVERSION} ${PREFIX}/lib/liblapack.so
	${LN} -sf libtmglib.so.${SVERSION} ${PREFIX}/lib/libtmglib.so
	${INSTALL_DATA} ${WRKSRC_PROFILE}/liblapack_p.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC_PROFILE}/libtmglib_p.a ${PREFIX}/lib
	${INSTALL_MAN} ${MANSRC}/manpages/man/manl/[a-c]*.l ${PREFIX}/man/manl
	${INSTALL_MAN} ${MANSRC}/manpages/man/manl/[d-l]*.l ${PREFIX}/man/manl
	${INSTALL_MAN} ${MANSRC}/manpages/man/manl/[m-s]*.l ${PREFIX}/man/manl
	${INSTALL_MAN} ${MANSRC}/manpages/man/manl/[t-z]*.l ${PREFIX}/man/manl

regression-test: build
	@${ECHO_CMD} "Testing static lapack library"
	cd ${WRKSRC}/TESTING ; ${MAKE} ${.MAKEFLAGS} ARCH=ar

.include <bsd.port.post.mk>
