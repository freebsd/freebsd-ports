# New ports collection makefile for:	smpeg
# Date created:		2 Feb 2000
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smpeg
PORTVERSION=	0.4.4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.lokigames.com/pub/open-source/smpeg/ \
		ftp://sunsite.auc.dk/pub/os/linux/loki/open-source/smpeg/ \
		ftp://boudicca.tux.org/misc/lokigames/open-source/smpeg/ \
		ftp://snuffleupagus.animearchive.org/loki/open-source/smpeg/ \
		http://ftp.gameaholic.com/mirrors/ftp.lokigames.com/open-source/smpeg/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=  	SDL-1.1.5:${PORTSDIR}/devel/sdl12

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		GLBASE="${X11BASE}" \
		CPPFLAGS="-I${X11BASE}/include" \
		CC="${CXX}" REAL_CC="${CC}"

#If you want to try the opengl player (which doesn't seem to work)
#comment out the following line.
CONFIGURE_ARGS=	--disable-opengl-player \
		--enable-mmx

MAN1=		gtv.1 plaympeg.1

post-configure:
	@${PERL} -pi -e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

.include <bsd.port.mk>
