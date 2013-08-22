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
PORTVERSION=	2.2.00
PORTREVISION=	1
CATEGORIES=	science biology
MASTER_SITES=	http://packages.bic.mni.mcgill.ca/tgz/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Medical Imaging NetCDF

LICENSE=	BSD

LIB_DEPENDS=	netcdf.4:${PORTSDIR}/science/netcdf \
		hdf5:${PORTSDIR}/science/hdf5

USE_LDCONFIG=	yes
USES=		cmake:outsource bison:build
CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include -DH5_USE_16_API
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CMAKE_ARGS=	-DMINC2_BUILD_SHARED_LIBS:BOOL=YES

CONFLICTS=	minc-1* zh-tk-[0-9]*
LATEST_LINK=	minc2

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
