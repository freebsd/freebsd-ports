# New ports collection makefile for:	vlc
# Date created:		3rd August 2001
# Whom:			Brian Somers <brian@Awfulhak.org>
#
# $FreeBSD$
#

PORTNAME=	vlc
PORTVERSION=	0.2.82
CATEGORIES=	graphics
MASTER_SITES=	http://www.videolan.org/pub/videolan/vlc/0.2.81/ \
		ftp://ftp.Awfulhak.org/pub/vlc/ \
		http://people.FreeBSD.org/~brian/vlc/

MAINTAINER=	brian@Awfulhak.org

LIB_DEPENDS=	SDL-1.1:${PORTSDIR}/devel/sdl12

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	PATH_GTKCONFIG="${PREFIX}/bin/gtk12-config" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		SDL_CONFIG="${LOCALBASE}/bin/sdl11-config"
USE_GTK=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

.include <bsd.port.mk>
