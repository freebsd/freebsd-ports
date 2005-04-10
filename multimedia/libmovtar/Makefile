# New ports collection makefile for:	libmovtar
# Date created:		Mon Oct 15 23:35:04 BRST 2001
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmovtar
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mjpeg

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Supports reading/writing of MJPEG video in YUV 4:2:2 JPEG

USE_SDL=	sdl
USE_GNOME=	glib12
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-m4data-prefix=${PREFIX}/share
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS=${PTHREAD_LIBS}

.if exists(${LOCALBASE}/lib/libjpeg-mmx.a)
OPTIONS+=	JPEGMMX "Enable Jpeg-mmx support by defining" OFF
.else
OPTIONS+=	JPEGMMX "Enable Jpeg-mmx support by defining" ON
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_JPEGMMX) && (${ARCH} == "i386")
LIB_DEPENDS+=	jpeg-mmx.62:${PORTSDIR}/graphics/jpeg-mmx

CONFIGURE_ARGS+=	--with-jpeg-mmx=${LOCALBASE}
.else
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg

CONFIGURE_ARGS+=	--without-jpeg-mmx
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|' \
		${WRKSRC}/rtjpeg/rtjshow.c \
		${WRKSRC}/movtar_play.c
# Add library patch when using -ljpeg
# Use proper locations when using -ljpeg-mmx
	@${REINPLACE_CMD} -E \
		-e 's|^(LIBS="-ljpeg )|\1 -L${LOCALBASE}/lib|' \
		-e 's|(LIBS -ljpeg)"|\1 -L${LOCALBASE}/lib"|' \
		-e 's|^(LIBS="-L) (\$$JPEGDIR) \$$DEFAULT_JPEGDIR_L|\1\2/lib|' \
		-e 's|-I (\$$JPEGDIR) \$$DEFAULT_JPEGDIR_I|-I\1/include|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.if ${ARCH} != "i386"
# emms opcode should be noop in non-i386 non-MMX ARCH
		@${REINPLACE_CMD} -E \
		-e 's|^.*"emms".*$$||' \
		${WRKSRC}/movtar_play.c
.endif

.include <bsd.port.post.mk>
