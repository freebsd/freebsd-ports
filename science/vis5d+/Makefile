# ex:ts=8
# Ports collection Makefile for:	vis5d+
# Date created:			Jan 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vis5d+
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vis5d

MAINTAINER=	stephen@math.missouri.edu
COMMENT=	An OpenGL-based volumetric visualization program for scientific datasets

BUILD_DEPENDS=	${LOCALBASE}/lib/libmix.a:${PORTSDIR}/graphics/qslim \
		convert:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS=	netcdf.1:${PORTSDIR}/math/netcdf \
		gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_GL=		yes
USE_GNOME=	gnometarget gtk12
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-gtk --enable-threads --with-netcdf \
		--with-mixkit=${LOCALBASE}/lib/libmix.a --with-x
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_FLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

CFLAGS+=	-DMIX_ANSI_IOSTREAMS -fpermissive

.include <bsd.port.mk>
