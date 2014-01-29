# Created by: jbacon
# $FreeBSD$

############################################################################
# http://www.bic.mni.mcgill.ca/software/minc/
# is the ultimate source for MINC, and will always contain the latest
# source release.  If this port is not up to date enough for you,
# you can download the latest sources and build manually.  On FreeBSD,
# you must configure with the environment variable LDFLAGS set to
# ${LOCALBASE}/lib so that the configure script will find libnetcdf.
# Of course, the netcdf port must be installed first.

PORTNAME=	minc
PORTVERSION=	2.0.18
PORTEPOCH=	1
CATEGORIES=	science biology
MASTER_SITES=	http://packages.bic.mni.mcgill.ca/tgz/ \
		http://www.nitrc.org/frs/download.php/801/
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Medical Imaging NetCDF

LICENSE=	BSD

LIB_DEPENDS=	libnetcdf.so.4:${PORTSDIR}/science/netcdf \
		libhdf5.so.0:${PORTSDIR}/science/hdf5

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include -DH5_USE_16_API
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--enable-shared=yes --enable-static=yes

CONFLICTS=	minc-1* zh-tk-[0-9]*
LATEST_LINK=	minc2

.include <bsd.port.mk>
