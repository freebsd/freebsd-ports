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
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
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
USE_REINPLACE=	yes
USE_GL=		yes
USE_GNOME=	gnometarget gtk12
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-firewire
CFLAGS+=	-fPIC

MAN1=	lqtplay.1
PORTDOCS=	codecs.html \
		qt4l_building.html \
		qt4l_codecs.html \
		qt4l_firewire.html \
		qt4l_index.html \
		qt4l_license.html \
		qt4l_opening.html \
		qt4l_positioning.html \
		qt4l_reading.html \
		qt4l_util.html \
		qt4l_writing.html

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS+=	--enable-mmx
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' \
		${WRKSRC}/plugins/audiocodec/* \
		${WRKSRC}/plugins/videocodec/*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
