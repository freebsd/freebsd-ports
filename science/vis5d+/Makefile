# ex:ts=8
# Ports collection Makefile for:	vis5d+
# Date created:			Jan 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vis5d+
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	vis5d

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libmix.a:${PORTSDIR}/graphics/qslim \
		convert:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		netcdf.1:${PORTSDIR}/math/netcdf \
		gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_BISON=	yes
USE_MESA=	yes
USE_XLIB=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} ${PTHREAD_FLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
	LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -liconv -lintl -L${X11BASE}/lib"
CONFIGURE_ARGS=	--enable-gtk --enable-threads --with-mesa --with-netcdf \
		--with-mixkit=${LOCALBASE}/lib/libmix.a --with-x
INSTALLS_SHLIB=	yes

pre-build:
	@${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}

.include <bsd.port.mk>
