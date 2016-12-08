# $FreeBSD$

PORTNAME=	sabbu
PORTVERSION=	0.3.0
PORTREVISION=	15
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Sabbu%20${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Program used to time subtitles

LICENSE=	GPLv2

LIB_DEPENDS=	libavcodec0.so:multimedia/ffmpeg0 \
		libsndfile.so:audio/libsndfile

USES=		tar:bzip2 gmake pkgconfig iconv
GNU_CONFIGURE=	yes

USE_SDL=	sdl
USE_GNOME=	gtk20
CFLAGS+=	-I${LOCALBASE}/include/ffmpeg0 -I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib/ffmpeg0 -L${LOCALBASE}/lib
LDFLAGS+=	-lswscale0 -lgmodule-2.0

OPTIONS_DEFINE=	GTKSPELL
OPTIONS_DEFAULT=GTKSPELL

GTKSPELL_LIB_DEPENDS=	libgtkspell.so:textproc/gtkspell

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	WITH_NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	WITH_NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's,ffmpeg/avformat,libavformat/avformat,g' \
		-e 's,lavcodec,lavcodec0,g' \
		-e 's,lavformat,lavformat0,g' \
		-e '/FFMPEG_LIBS=/s/"$$/ -lavutil0"/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
