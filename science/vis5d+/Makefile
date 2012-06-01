# ex:ts=8
# Ports collection Makefile for:	vis5d+
# Date created:			Jan 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vis5d+
PORTVERSION=	1.2.1
PORTREVISION=	16
CATEGORIES=	science
MASTER_SITES=	SF/vis5d/vis5d/${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	OpenGL-based volumetric visualization program for scientific datasets

BUILD_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS=	netcdf.4:${PORTSDIR}/science/netcdf \
		mix.0:${PORTSDIR}/graphics/qslim \
		gfx.0:${PORTSDIR}/graphics/libgfx \
		gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

# The following scope of brokenness for vis5d+ is approximate.  If you find
# the following scope is inappropriate for you, please report to maintainer.
.if OSVERSION<801000
BROKEN=	Does not build on some FreeBSD versions (libtool error).
.endif

USE_FORTRAN=	yes
USE_AUTOTOOLS=	libtool
USE_GL=		yes
USE_GNOME=	gtk12
USE_ICONV=	yes
GNU_CONFIGURE=	yes
FFLAGS+=	-fno-range-check
CONFIGURE_ENV+=	LIBS="-lgfx"
CONFIGURE_ARGS=	--enable-gtk --enable-threads --with-netcdf \
		--with-mixkit=${LOCALBASE}/lib/libmix.a --with-x
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

CFLAGS+=	-DMIX_ANSI_IOSTREAMS -fPIC -fpermissive

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
