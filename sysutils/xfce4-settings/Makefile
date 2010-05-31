# New ports collection makefile for:	xfce4-settings
# Date created:		2 October 2008
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-settings
PORTVERSION=	4.6.4
PORTREVISION=	4
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://www.xfce.org/archive/src/xfce/xfce4-settings/4.6/
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 settings application

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	wnck-1.22:${PORTSDIR}/x11-toolkits/libwnck

OPTIONS=	XKLAVIER	"Keyboard layout settings"	off

CONFIGURE_ARGS=	--disable-sound-settings
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libexo libgui libutil xfconf

.include <bsd.port.pre.mk>

.if defined(WITH_XKLAVIER)
LIB_DEPENDS+=	xklavier.12:${PORTSDIR}/x11/libxklavier
CONFIGURE_ARGS+=--enable-libxklavier
.else
CONFIGURE_ARGS+=--disable-libxklavier
.endif

post-patch:
	# until xfce4-icon-theme is back we rely on Tango
	@${REINPLACE_CMD} -e 's|Rodent|Tango|g' \
		${WRKSRC}/dialogs/appearance-settings/main.c \
		${WRKSRC}/xfsettingsd/xsettings.xml
	@${REINPLACE_CMD} -e 's|xkl_config_registry_load (settings->priv->xkl_registry)|xkl_config_registry_load (settings->priv->xkl_registry, FALSE)|g; \
		s|xkl_engine_stop_listen (settings->priv->xkl_engine)|xkl_engine_stop_listen (settings->priv->xkl_engine, FALSE)|g' \
		${WRKSRC}/dialogs/keyboard-settings/xfce-keyboard-settings.c

.include <bsd.port.post.mk>
