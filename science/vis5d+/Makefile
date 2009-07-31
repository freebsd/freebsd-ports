# ex:ts=8
# Ports collection Makefile for:	vis5d+
# Date created:			Jan 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vis5d+
PORTVERSION=	1.2.1
PORTREVISION=	12
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vis5d

MAINTAINER=	stephen@missouri.edu
COMMENT=	OpenGL-based volumetric visualization program for scientific datasets

BUILD_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS=	netcdf.4:${PORTSDIR}/science/netcdf \
		mix.0:${PORTSDIR}/graphics/qslim \
		gfx.0:${PORTSDIR}/graphics/libgfx \
		gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_FORTRAN=	yes
USE_AUTOTOOLS=	libtool:15
USE_GL=		yes
USE_GNOME=	gnometarget gtk12
USE_ICONV=	yes
GNU_CONFIGURE=	yes
FFLAGS+=	-fno-range-check
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" LIBS="-lgfx"
CONFIGURE_ARGS=	--enable-gtk --enable-threads --with-netcdf \
		--with-mixkit=${LOCALBASE}/lib/libmix.a --with-x
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

CFLAGS+=	-DMIX_ANSI_IOSTREAMS -fPIC -fpermissive

.include <bsd.port.mk>
