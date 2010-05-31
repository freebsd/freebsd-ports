# New ports collection makefile for:	xfce4-xmms-plugin
# Date created:				2004/05/10
# Whom:					Zahemszky, Gábor <Gabor@Zahemszky.HU>
#
# $FreeBSD$
#

PORTNAME=	xfce4-xmms-plugin
PORTVERSION=	0.5.2
PORTREVISION=	10
CATEGORIES=	multimedia audio xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	XFce 4 xmms control plugin for xfce4-panel

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pango pkgconfig
USE_XFCE=	configenv libgui libutil panel

OPTIONS=	XMMS		"Enable xmms support"			on \
		BEEP		"Enable beep-media-player support" 	off \
		AUDACIOUS	"Enable audacious support"		off

.include <bsd.port.pre.mk>

.if defined(WITH_BEEP)
RUN_DEPENDS+=	beep-media-player:${PORTSDIR}/multimedia/beep-media-player
.endif

.if defined(WITH_XMMS)
RUN_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
.endif

.if defined(WITH_AUDACIOUS)
RUN_DEPENDS+=	audacious2:${PORTSDIR}/multimedia/audacious
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|== x|= x|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
