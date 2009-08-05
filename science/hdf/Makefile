# New ports collection makefile for:	HDF_lib
# Date created:		17 November 1996
# Whom:			mi
#
# $FreeBSD$
#

PORTNAME=	hdf
PORTVERSION=	4.2r3
PORTREVISION=	4
CATEGORIES=	science archivers graphics
MASTER_SITES=	ftp://ftp.hdfgroup.org/HDF/HDF_Current/src/:src \
		ftp://ftp.hdfgroup.org/HDF/Documentation/${PORTVERSION}/:doc \
		ftp://ftp.hdfgroup.org/HDF/Documentation/HDF4.2r3/:doc \
		http://hdf.ncsa.uiuc.edu/doc_resource/SZIP/:doc_szip
DISTNAME=	HDF${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		${SZIP_DOCFILE}:doc_szip \
		${DOCFILES:C/$/:doc/g}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA)

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		sz.2:${PORTSDIR}/science/szip

CONFLICTS=	netcdf-*

USE_FORTRAN=	yes
MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-jpeg="${LOCALBASE}" \
		--with-szlib="${LOCALBASE}"\
		--mandir=${MANPREFIX}/man
DOCFILES=	RM-print42r3.pdf \
		UG_print42r3.pdf
SZIP_DOCFILE=	SZIP_HDF4_2r1.pdf

MAN1=		hdf.1 hdfunpac.1 ncdump.1 ncgen.1
MANCOMPRESSED=	no

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "alpha" && ${ARCH} != "amd64"
BROKEN=		Does not compile on !i386, !amd64 and !alpha
.endif

.if ${ARCH} == "sparc64"
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

SHLIBVER_LIBMFHDF=	3
SHLIBVER_MDF=	2

post-extract:
	${MKDIR} ${WRKSRC}_SHARED ; ${CP} -r ${WRKSRC}/* ${WRKSRC}_SHARED

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ./configure \
		${MAKE_ENV} ${CONFIGURE_ENV} ${CONFIGURE_ARGS})
	@(cd ${WRKSRC}_SHARED && ${SETENV} ./configure \
		${MAKE_ENV} ${CONFIGURE_ENV} ${CONFIGURE_ARGS} CFLAGS="${PICFLAG}" FFLAGS="${PICFLAG}")

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE})
	@(cd ${WRKSRC}_SHARED; ${SETENV} ${MAKE_ENV} ${MAKE})
	@(cd ${WRKSRC}_SHARED/mfhdf/libsrc; ld -Bshareable -o libmfhdf.so.${SHLIBVER_LIBMFHDF} -x -soname libmfhdf.so.${SHLIBVER_LIBMFHDF} --whole-archive libmfhdf.a )
	@(cd ${WRKSRC}_SHARED/hdf/src; ld -Bshareable -o libdf.so.${SHLIBVER_MDF} -x -soname libdf.so.${SHLIBVER_MDF} --whole-archive libdf.a )

post-install:
	${INSTALL_DATA} ${WRKSRC}_SHARED/mfhdf/libsrc/libmfhdf.so.${SHLIBVER_LIBMFHDF} ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}_SHARED/hdf/src/libdf.so.${SHLIBVER_MDF} ${PREFIX}/lib
	${LN} -sf libmfhdf.so.${SHLIBVER_LIBMFHDF} ${PREFIX}/lib/libmfhdf.so
	${LN} -sf libdf.so.${SHLIBVER_MDF} ${PREFIX}/lib/libdf.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES} ${SZIP_DOCFILE}
	@${INSTALL_DATA} ${DISTDIR}/${file} ${DOCSDIR}
.endfor
	@cd ${WRKSRC}/release_notes && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

test: build
	cd ${WRKSRC}/hdf/test && ${MAKE} check

.include <bsd.port.post.mk>
