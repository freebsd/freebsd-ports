# ex:ts=8
# Ports collection makefile for:	libquicktime
# Date Created:			Jul 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libquicktime
PORTVERSION=	0.9.7
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	A library for reading and writing quicktime files

LIB_DEPENDS=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		dv.4:${PORTSDIR}/multimedia/libdv

INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
USE_GL=		yes
USE_GNOME=	gnometarget gnomehack pkgconfig
WANT_GNOME=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--disable-firewire
CFLAGS+=	-fPIC

OPTIONS=	LAME "Enable Lame mp3 encoding support" Off \
		GTK "Enable Gtk+2 Frontend" Off

MAN1=	lqtplay.1

PORTDOCS=	api_usage.html codecs.html qt4l_building.html \
		qt4l_codecs.html qt4l_firewire.html qt4l_index.html \
		qt4l_license.html qt4l_opening.html qt4l_positioning.html \
		qt4l_reading.html qt4l_util.html qt4l_writing.html

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk20}!="" || defined(WITH_GTK)
USE_GNOME+=	gtk20
PLIST_SUB+=	GTK=""
.else
PLIST_SUB+=	GTK="@comment "
.endif

.if defined(WITH_LAME) || exists(${LOCALBASE}/lib/libmp3lame.a)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
PLIST_SUB+=	LAME=""
.else
PLIST_SUB+=	LAME="@comment "
.endif

.if ${MACHINE_CPU:Mmmx}
CONFIGURE_ARGS+=	--enable-mmx
.if ${ARCH}=="i386"
LIB_DEPENDS+=	jpeg-mmx.62:${PORTSDIR}/graphics/jpeg-mmx
.endif
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
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
