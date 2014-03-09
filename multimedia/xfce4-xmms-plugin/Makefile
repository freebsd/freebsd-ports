# Created by: Zahemszky, Gábor <Gabor@Zahemszky.HU>
# $FreeBSD$

PORTNAME=	xfce4-xmms-plugin
PORTVERSION=	0.5.3
PORTREVISION=	4
CATEGORIES=	multimedia audio xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce4 XMMS control plugin for xfce4-panel

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	gtk20 intltool intlhack pango
USE_XFCE=	configenv libgui libutil panel

OPTIONS_DEFINE=	XMMS AUDACIOUS
OPTIONS_DEFAULT=	XMMS
XMMS_DESC=	xmms support
AUDACIOUS_DESC=	audacious support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXMMS}
RUN_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
.endif

.if ${PORT_OPTIONS:MAUDACIOUS}
RUN_DEPENDS+=	audacious2:${PORTSDIR}/multimedia/audacious
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|== x|= x|g' ${WRKSRC}/configure

.include <bsd.port.mk>
