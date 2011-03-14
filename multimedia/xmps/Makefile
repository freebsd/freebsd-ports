# New ports collection makefile for:	XMPS
# Date created:				15 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmps
PORTVERSION=	0.2.0
PORTREVISION=	12
CATEGORIES=	multimedia gnome
MASTER_SITES=	http://ftp.vin.bg.ac.yu/linux/mmedia/xmps/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X MPEG Player System - a media player with a very nice GUI

DEPRECATED=     Upstream has disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GETTEXT=	yes
USE_SDL=	sdl
USE_GNOME=	gnomeprefix gnomehack gnomelibs gdkpixbuf
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

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
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
