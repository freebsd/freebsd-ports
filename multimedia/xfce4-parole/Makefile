# New ports collection makefile for:	Xfce4-parole
# Date created:		26 December 2009
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	parole
PORTVERSION=	0.3.0
CATEGORIES=	multimedia xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}/
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Lightweight media player for Xfce4 based on gstreamer

LICENSE=	GPLv2

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib \
		notify.4:${PORTSDIR}/devel/libnotify \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GSTREAMER=	core faad flac wavpack
USE_GMAKE=	yes
CONFIGURE_ARGS=	--disable-power-manager-plugin \
		--enable-libnotify \
		--enable-taglib \
		--without-html-dir
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GNOME=	gnomehack gtk20 glib20 intltool intlhack desktopfileutils
USE_XFCE=	configenv libmenu libutil
USE_XORG=	x11 sm
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build

OPTIONS_DEFINE=	CDDA HTTP NLS
OPTIONS_DEFAULT=	CDDA HTTP NLS
CDDA_DESC=	CD audio support (cdparanoia)
HTTP_DESC=	HTTP streaming support (libsoup)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCDDA}
USE_GSTREAMER+=	cdparanoia
.endif

.if ${PORT_OPTIONS:MHTTP}
USE_GSTREAMER+=	soup
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
# Fix installation directory plugins
	${FIND} ${WRKSRC}/src -name 'Makefile.in' -type f \
		| ${XARGS} ${REINPLACE_CMD} -e \
		's|(datadir)/src/misc|(datadir)/${PORTNAME}|'
# Fix .rc file path
	${REINPLACE_CMD} -e 's|src/misc|${PORTNAME}|g' \
		${WRKSRC}/src/common/parole-rc-utils.h

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
