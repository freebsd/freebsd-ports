# ex:ts=8
# New ports collection makefile for:	CDO
# Date created:			29 May 2006
# Whom:				Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	cdo
PORTVERSION=	1.0.7
CATEGORIES=	science
MASTER_SITES=	http://www.mpimet.mpg.de/fileadmin/software/cdo/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Climate Data Operators

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--program-transform-name=""
CONFIGURE_ENV=	CC="${CC}" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

PLIST_FILES=	bin/cdo bin/cdotest

OPTIONS=	HDF5	"HDF5 support" off \
		NETCDF	"NETCDF support" off

.include <bsd.port.pre.mk>

.if (${OSVERSION} > 700000) || (${ARCH} != "sparc64" && ${OSVERSION} > 600000)
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -DPTHREAD_MUTEXATTR_CONDATTR"
.endif

.if defined(WITH_HDF5)
CONFIGURE_ARGS+=	--with-hdf5=${LOCALBASE}
LIB_DEPENDS+=		hdf5.0:${PORTSDIR}/science/hdf5
.endif

.if defined(WITH_NETCDF)
CONFIGURE_ARGS+=	--with-netcdf=${LOCALBASE}
LIB_DEPENDS+=		netcdf.4:${PORTSDIR}/science/netcdf
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
