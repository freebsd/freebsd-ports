# Created by: ijliao
# $FreeBSD$

PORTNAME=	xtheater
PORTVERSION=	1.0.0.p1
PORTREVISION=	11
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/Xtheater/1.0.0-pre1
DISTNAME=	Xtheater-${PORTVERSION:S/.p/-pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MPEG-1 player in GTK+ capable of playing MPEG-1 format streams

LIB_DEPENDS=	libsmpeg.so:${PORTSDIR}/multimedia/smpeg

USE_SDL=	sdl
USE_GNOME=	gtk12
USE_GL=		yes
USES=		gmake libtool tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gl

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]prefix[)]/Xtheater|(libdir)/Xtheater|g ; \
		 s|-release.*$$|-module -avoid-version|g'
	@${REINPLACE_CMD} -e 's|PREFIX/Xtheater|PREFIX/lib/Xtheater|g' \
		${WRKSRC}/Xtheater.conf
.for file in plugins/player/smpeg/glscreen.c plugins/player/wm/glscreen.c
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
