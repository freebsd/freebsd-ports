# ex:ts=8
# Ports collection makefile for:	libquicktime
# Date Created:			Jul 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libquicktime
PORTVERSION=	0.9.3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ahze@ahze.net
COMMENT=	A library for reading and writing quicktime files

LIB_DEPENDS=	avcodec.0:${PORTSDIR}/multimedia/ffmpeg \
		mp3lame.0:${PORTSDIR}/audio/lame \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		dv.4:${PORTSDIR}/multimedia/libdv

INSTALLS_SHLIB=	yes
USE_GL=		yes
USE_GNOME=	gnometarget gtk12
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-firewire
CFLAGS+=	-fPIC

MAN1=	lqtplay.1

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS+=	--enable-mmx
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

.include <bsd.port.post.mk>
