# Ports collection makefile for:  xmms-avi
# Date created:			  Feb 6 2000
# Whom:				  Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-avi
PORTVERSION=	1.2.3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.xmms.org/files/plugins/avi-xmms/ \
		ftp://ftp.sunet.se/pub/multimedia/xmms/plugins/avi-xmms/ \
		ftp://ftp.fu-berlin.de/unix/sound/xmms/plugins/avi-xmms/
DISTNAME=	avi-xmms-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An avifile based .avi and .asf file playback plugin for XMMS

LIB_DEPENDS=	xmms.3:${PORTSDIR}/multimedia/xmms

ONLY_FOR_ARCHS=	i386
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes
USE_SDL=	yes
CONFIGURE_ARGS=	--with-win32-path=${LOCALBASE}/lib/win32
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

.include <bsd.port.pre.mk>

pre-patch:
	@${REINPLACE_CMD} -e "s|SDL/SDL.h|SDL11/SDL.h|g" ${WRKSRC}/src/ctrackbar.cpp
	@${REINPLACE_CMD} -e "s|-lc_r|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

# This is to avoid libtool running ldconfig -m ${X11BASE}/lib/xmms/Input
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/libavixmms.so ${PREFIX}/lib/xmms/Input

.include <bsd.port.post.mk>
