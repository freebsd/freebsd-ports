# ex:ts=8
# New ports collection makefile for:	HDF5
# Date created:			Jul 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	hdf5
PORTVERSION=	1.6.1
CATEGORIES=	graphics
MASTER_SITES=	http://fresh.t-systems-sfr.com/unix/src/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hierarchical Data Format library (from NCSA)

USE_REINPLACE=	yes
USE_PERL5=	yes
USE_OPENSSL=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure c++/configure
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS}"
CONFIGURE_ARGS=	--enable-cxx --enable-production \
		--enable-threadsafe --disable-debug \
		--with-ssl --with-pthread
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|[\$$]CFLAGS -pthread|\$$CFLAGS|g ; \
		 s|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|g ; \
		 s|[\$$]LDFLAGS -pthread|\$$LDFLAGS ${PTHREAD_LIBS}|g ; \
		 s|-lcipher||g' \
			${WRKSRC}/config/freebsd
	@${REINPLACE_CMD} -e 's|-O3||g' ${WRKSRC}/config/gnu-flags

post-install:
.for i in gif2h5 h52gif h5createU8 h5debug h5diff h5dump h5import h5ls h5repart
	@${STRIP_CMD} ${PREFIX}/bin/${i}
.endfor

.include <bsd.port.mk>
