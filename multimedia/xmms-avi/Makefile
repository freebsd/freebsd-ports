# Ports collection makefile for:  xmms-avi
# Date created:			  Feb 6 2000
# Whom:				  Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-avi
PORTVERSION=	1.2.2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.xmms.org/files/plugins/avi-xmms/ \
		ftp://ftp.sunet.se/pub/multimedia/xmms/plugins/avi-xmms/ \
		ftp://ftp.fu-berlin.de/unix/sound/xmms/plugins/avi-xmms/
DISTNAME=	avi-xmms-${PORTVERSION}

MAINTAINER=	roman@xpert.com

BROKEN=		Maintainer is working on a fix

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/audio/xmms
LIB_DEPENDS=	aviplay-0.7.0:${PORTSDIR}/graphics/avifile
RUN_DEPENDS=	xmms:${PORTSDIR}/audio/xmms

SDL_CONFIG?=    ${LOCALBASE}/bin/sdl11-config

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

pre-patch:
	@${PERL} -pi.orig -e "s|SDL/SDL.h|SDL11/SDL.h|g" ${WRKSRC}/src/ctrackbar.cpp
	@${PERL} -pi.orig -e "s|lc_r|pthread|g" ${WRKSRC}/configure

# This is to avoid libtool running ldconfig -m ${X11BASE}/lib/xmms/Input
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/libavixmms.so ${PREFIX}/lib/xmms/Input

.include <bsd.port.mk>
