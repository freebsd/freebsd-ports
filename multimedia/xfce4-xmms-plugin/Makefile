# New ports collection makefile for:	xfce4-xmms-plugin
# Date created:				2004/05/10
# Whom:					Zahemszky, Gábor <Gabor@Zahemszky.HU>
#
# $FreeBSD$
#

PORTNAME=	xfce4-xmms-plugin
PORTVERSION=	0.4.2
CATEGORIES=	multimedia audio xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	jfb@minet.net
COMMENT=	XFce 4 xmms control plugin for xfce4-panel

BROKEN=		Does not build

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pango pkgconfig
USE_XFCE=	configenv libgui libutil panel
USE_XLIB=	yes

OPTIONS=	BEEP	"Use Beep media player instead of xmms" 	off

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11-wm/xfce4/bsd.xfce.mk"

.if defined(WITH_BEEP)
LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player
CONFIGURE_ARGS+=--with-player=beep
.else
LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
CONFIGURE_ARGS+=--with-player=xmms
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|== x|= x|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
