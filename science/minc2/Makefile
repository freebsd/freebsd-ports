############################################################################
# New ports collection Makefile for:   minc 1.x (Medical Imaging NetCDF)
# Date created:        21 Dec 2005
# Whom:                jbacon
#
# $FreeBSD$
#

############################################################################
# http://www.bic.mni.mcgill.ca/software/minc/
# is the ultimate source for MINC, and will always contain the latest
# source release.  If this port is not up to date enough for you,
# you can download the latest sources and build manually.  On FreeBSD,
# you must configure with the environment variable LDFLAGS set to
# ${LOCALBASE}/lib so that the configure script will find libnetcdf.
# Of course, the netcdf port must be installed first.

PORTNAME=	minc
PORTVERSION=	2.0.09
CATEGORIES=	science biology
MASTER_SITES=	http://www.bic.mni.mcgill.ca/users/bert/ \
		http://www.neuro.mcw.edu/~bacon/Ports/distfiles/

MAINTAINER=	bacon@smithers.neuro.mcw.edu
COMMENT=	Medical Imaging NetCDF

LIB_DEPENDS=	netcdf.1:${PORTSDIR}/science/netcdf \
		hdf5.0:${PORTSDIR}/science/hdf5

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GCC=	3.2+
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--enable-shared=yes --enable-static=yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CONFLICTS=	minc-1*
LATEST_LINK=	minc2

MAN1=	dcm2mnc.1 \
	ecattominc.1 \
	invert_raw_image.1 \
	minc_modify_header.1 \
	mincaverage.1 \
	minccalc.1 \
	mincconcat.1 \
	mincconvert.1 \
	minccopy.1 \
	mincdiff.1 \
	mincedit.1 \
	mincexpand.1 \
	mincextract.1 \
	mincgen.1 \
	mincheader.1 \
	minchistory.1 \
	mincinfo.1 \
	minclookup.1 \
	mincmakescalar.1 \
	mincmakevector.1 \
	mincmath.1 \
	mincpik.1 \
	mincresample.1 \
	mincreshape.1 \
	mincstats.1 \
	minctoecat.1 \
	minctoraw.1 \
	mincview.1 \
	mincwindow.1 \
	mnc2nii.1 \
	nii2mnc.1 \
	rawtominc.1 \
	transformtags.1 \
	upet2mnc.1 \
	voxeltoworld.1 \
	xfmconcat.1 \
	xfminvert.1
MAN3=	ParseArgv.3

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
