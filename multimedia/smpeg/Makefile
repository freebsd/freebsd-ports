# New ports collection makefile for:	smpeg
# Date created:		2 Feb 2000
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smpeg
PORTVERSION=	0.4.4
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.lokigames.com/pub/open-source/smpeg/ \
		ftp://sunsite.auc.dk/pub/os/linux/loki/open-source/smpeg/ \
		ftp://boudicca.tux.org/misc/lokigames/open-source/smpeg/ \
		ftp://snuffleupagus.animearchive.org/loki/open-source/smpeg/ \
		http://ftp.gameaholic.com/mirrors/ftp.lokigames.com/open-source/smpeg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free MPEG1 video player library with sound support

WANT_GNOME=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_SDL=	sdl
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	GLBASE="${X11BASE}" \
		CPPFLAGS="-I${X11BASE}/include" \
		CC="${CXX}" REAL_CC="${CC}"

#If you want to try the opengl player (which doesn't seem to work)
#comment out the following line.
CONFIGURE_ARGS=	--disable-opengl-player \
		--enable-mmx

MAN1=		gtv.1 plaympeg.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
.else
CONFIGURE_ARGS+=	--disable-gtk-player
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

.include <bsd.port.post.mk>
