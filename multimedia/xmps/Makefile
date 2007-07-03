# New ports collection makefile for:	XMPS
# Date created:				15 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmps
PORTVERSION=	0.2.0
PORTREVISION=	5
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://ftp.vin.bg.ac.yu/linux/mmedia/xmps/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X MPEG Player System - a media player with a very nice GUI

USE_GETTEXT=	yes
USE_SDL=	sdl
USE_GNOME=	gnomeprefix gnomehack gnomelibs gdkpixbuf
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile on !i386
.endif

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g'
# Fixes for GCC 4.2
	@${REINPLACE_CMD} -e 's|X" (mem)|m" (mem)|' \
		${WRKSRC}/codecs/video/mpeg3/mmx.h
	@${REINPLACE_CMD} -e '42,44s|^static ||' \
		${WRKSRC}/codecs/video/mpeg3/slice.c

.include <bsd.port.post.mk>
