# ex:ts=8
# New ports collection makefile for:	HDF5
# Date created:			Jul 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hdf5
PORTVERSION=	1.6.9
CATEGORIES=	science archivers graphics
MASTER_SITES=	ftp://ftp.hdfgroup.org/HDF5/current16/src/ \
		ftp://ftp.hdfgroup.org/HDF5/prev-releases/ \
		ftp://ftp.hdfgroup.org/HDF5/prev-releases/hdf5-${PORTVERSION}/src/ \
		LOCAL/chinsan

MAINTAINER=	koziol@hdfgroup.org
COMMENT=	Hierarchical Data Format library (from NCSA)

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
LIBTOOLFILES=	configure c++/configure
CONFIGURE_ARGS=	--disable-debug \
		--enable-cxx \
		--enable-instrument \
		--enable-production \
		--enable-strict-format-checks \
		--enable-threadsafe \
		--with-pthread=/usr \
		--with-ssl=/usr \
		--with-zlib=/usr
ALL_TARGET=	lib progs
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_FORTRAN)
LIBTOOLFILES+=		fortran/configure
USE_FORTRAN=		yes
CONFIGURE_ENV+=		F9X=${FC}
CONFIGURE_ARGS+=	--enable-fortran
PLIST_SUB+=		FORTRAN=""
.else
PLIST_SUB+=		FORTRAN="@comment "
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on ${ARCH}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g' \
		-e 's|[\$$]LDFLAGS -pthread|\$$LDFLAGS ${PTHREAD_LIBS}|g'  \
			${WRKSRC}/config/freebsd ${WRKSRC}/c++/config/freebsd
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/config/gnu-flags
	@${REINPLACE_CMD} -e 's|objformat=|#objformat=|g' \
		-e 's|\(version_type=freebsd\)-.*|\1-elf|g' \
			${WRKSRC}/aclocal.m4 ${WRKSRC}/configure
.if defined(NOPORTEXAMPLES)
.for i in . c++ hl fortran
	@${REINPLACE_CMD} \
		-e 's,\((cd examples && $$(MAKE) $$@) || exit 1;\),#\1,g' \
			${WRKSRC}/${i}/Makefile.in
.endfor
.endif

post-install:
.for i in gif2h5 h52gif h5debug h5diff h5dump h5import h5jam h5ls h5repack h5repart h5unjam
	@${STRIP_CMD} ${PREFIX}/bin/${i}
.endfor

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.post.mk>
