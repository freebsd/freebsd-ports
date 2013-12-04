# $FreeBSD$

PORTNAME=	sabbu
PORTVERSION=	0.3.0
PORTREVISION=	14
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Sabbu%20${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Program used to time subtitles

LIB_DEPENDS=	libavcodec0.so:${PORTSDIR}/multimedia/ffmpeg0 \
		libsndfile.so:${PORTSDIR}/audio/libsndfile

USES=		pkgconfig iconv gmake
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

USE_GNOME=	gtk20
CFLAGS+=	-I${LOCALBASE}/include/ffmpeg0 ${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib/ffmpeg0 -L${LOCALBASE}/lib ${PTHREAD_LIBS} -lswscale0

OPTIONS_DEFINE=	GTKSPELL
OPTIONS_DEFAULT=GTKSPELL

GTKSPELL_LIB_DEPENDS=	libgtkspell.so:${PORTSDIR}/textproc/gtkspell

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	WITH_NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	WITH_NLS="@comment "
.endif

.if ${ARCH} == "powerpc"
BROKEN=		Does not configure on powerpc
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's,ffmpeg/avformat,libavformat/avformat,g' \
		-e 's,lavcodec,lavcodec0,g' \
		-e 's,lavformat,lavformat0,g' \
		-e 's,lavswscale,lavswscale0,g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
