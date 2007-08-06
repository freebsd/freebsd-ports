# Ports collection makefile for:	libquicktime
# Date Created:			Jul 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libquicktime
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A library for reading and writing quicktime files

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		dv.4:${PORTSDIR}/multimedia/libdv \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		faad.0:${PORTSDIR}/audio/faad

USE_LDCONFIG=	yes
USE_GETTEXT=	yes
USE_GL=		yes
USE_GNOME=	gnometarget gnomehack pkgconfig
WANT_GNOME=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:259
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS} -lintl"
CONFIGURE_ARGS=	--disable-firewire --with-x --enable-gpl
CFLAGS+=	-fPIC
MAN1=		lqtplay.1

OPTIONS=	LAME "Enable Lame mp3 encoding support" Off \
		GTK2 "Enable Gtk+2 Frontend" Off \
		OPTIMIZED_CFLAGS "Enable Optimized CFLAGS" Off

PORTDOCS=	api_usage.html codecs.html qt4l_building.html \
		qt4l_codecs.html qt4l_index.html \
		qt4l_license.html qt4l_opening.html qt4l_positioning.html \
		qt4l_reading.html qt4l_util.html qt4l_writing.html

.include <bsd.port.pre.mk>

.if !defined(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=--without-cpuflags
.endif

.if ${HAVE_GNOME:Mgtk20}!="" || defined(WITH_GTK2)
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
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' \
		${WRKSRC}/plugins/audiocodec/* \
		${WRKSRC}/plugins/videocodec/*
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
