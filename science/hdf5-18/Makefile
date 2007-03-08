# ex:ts=8
# New ports collection makefile for:	HDF5
# Date created:			Jul 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hdf5
PORTVERSION=	1.6.5
CATEGORIES=	science archivers graphics
MASTER_SITES=	ftp://ftp.hdfgroup.org/HDF5/current/src/

MAINTAINER=	koziol@hdfgroup.org
COMMENT=	Hierarchical Data Format library (from NCSA)

USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
LIBTOOLFILES=	configure c++/configure
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-cxx --enable-production \
		--enable-threadsafe --disable-debug \
		--with-pthread
ALL_TARGET=	lib progs

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g ; \
		 s|[\$$]LDFLAGS -pthread|\$$LDFLAGS ${PTHREAD_LIBS}|g'  \
			${WRKSRC}/config/freebsd
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g ; \
		 s|[\$$]LDFLAGS -pthread|\$$LDFLAGS ${PTHREAD_LIBS}|g'  \
			${WRKSRC}/c++/config/freebsd
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/config/gnu-flags
	@${REINPLACE_CMD} -e 's|objformat=|#objformat=|g' ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e 's|objformat=|#objformat=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/version_type=freebsd-/s|=.*|=freebsd-elf|g' ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e '/version_type=freebsd-/s|=.*|=freebsd-elf|g' ${WRKSRC}/configure

post-install:
.for i in gif2h5 h52gif h5debug h5diff h5dump h5import h5ls h5repart h5jam h5unjam
	@${STRIP_CMD} ${PREFIX}/bin/${i}
.endfor

.include <bsd.port.post.mk>
