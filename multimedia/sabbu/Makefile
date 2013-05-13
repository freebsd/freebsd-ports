# $FreeBSD$

PORTNAME=	sabbu
PORTVERSION=	0.3.0
PORTREVISION=	13
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Sabbu%20${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Program used to time subtitles

LIB_DEPENDS=	avcodec:${PORTSDIR}/multimedia/ffmpeg \
		sndfile:${PORTSDIR}/audio/libsndfile

USES=		pkgconfig iconv
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

USE_GNOME=	gtk20
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lswscale

OPTIONS_DEFINE=	GTKSPELL
OPTIONS_DEFAULT=GTKSPELL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	WITH_NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	WITH_NLS="@comment "
.endif

.if ${PORT_OPTIONS:MGTKSPELL}
LIB_DEPENDS+=	gtkspell:${PORTSDIR}/textproc/gtkspell
.else
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not configure on powerpc
.endif

.include <bsd.port.post.mk>
