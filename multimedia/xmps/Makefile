# New ports collection makefile for:	xmps
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

USE_SDL=	sdl
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gdkpixbuf
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
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

.include <bsd.port.post.mk>
