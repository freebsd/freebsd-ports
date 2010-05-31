# New ports collection makefile for: science/meep
# Date created:		26 Dec 2009
# Whom:			Stas Timokhin <devel@stasyan.com>
#
# $FreeBSD$
#

PORTNAME=	meep
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://ab-initio.mit.edu/meep/

MAINTAINER=	devel@stasyan.com
COMMENT=	FDTD simulation software to model electromagnetic systems

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_FORTRAN=	yes
USE_GCC=	4.4+
USE_ICONV=	yes
USE_GETTEXT=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LD_LIBRARY_PATH=	-L${LOCALBASE}/lib -L/usr/lib
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LD_LIBRARY_PATH="${LD_LIBRARY_PATH}" LDFLAGS="${LDFLAGS}"

BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash \
		harminv:${PORTSDIR}/science/harminv
LIB_DEPENDS+=	guile.20:${PORTSDIR}/lang/guile \
		blas.2:${PORTSDIR}/math/blas \
		ctl.4:${PORTSDIR}/science/libctl \
		hdf5.0:${PORTSDIR}/science/hdf5 \
		ltdl.7:${PORTSDIR}/devel/libltdl22
RUN_DEPENDS+=	harminv:${PORTSDIR}/science/harminv

.include <bsd.port.mk>
