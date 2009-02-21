# New ports collection makefile for:	gxine
# Date created:	Sa 19 Apr 2003 01:34:06 CEST
# Whom: 	Grigori Goronzy <greg@chown.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	gxine
PORTVERSION=	0.5.903
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	xine

MAINTAINER=	makc@FreeBSD.org
COMMENT=	An alternative GUI for the Xine media player

LIB_DEPENDS=	xine.1:${PORTSDIR}/multimedia/libxine

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gtk20 gnomehier
USE_GMAKE=	yes
USE_GCC=	4.2+
USE_XORG=	x11 xaw ice
MAKE_ARGS+=	LDFLAGS=-shared-libgcc
CNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--without-hal
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_ICONS=	yes

MANLANG=	"" de es
MAN1=		gxine.1 gxine_client.1
MANCOMPRESSED=	no

OPTIONS=	MOZILLA_PLUGIN "Install Mozilla plugin" on \
		GNOME "Enable Gnome integration" off \
		DBUS "Enable dbus support" on \
		LIRC "Enable lirc support" off \
		XCB "Enable XCB support" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
CFLAGS+=	-O2
.endif

.if defined(WITH_GNOME)
USE_GNOME+=	gnomevfs2 libgnomeui
.else
CONFIGURE_ARGS+=--disable-integration-wizard
.endif

.if !defined(WITHOUT_DBUS)
CONFIGURE_ARGS+=--with-dbus
LIB_DEPENDS+=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
.else
CONFIGURE_ARGS+=--without-dbus
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_LIRC)
LIB_DEPENDS+=	lirc_client.1:${PORTSDIR}/comms/lirc
CONFIGURE_ARGS+=	--enable-lirc
.else
CONFIGURE_ARGS+=	--disable-lirc
.endif

.if defined(WITHOUT_MOZILLA_PLUGIN)
LIB_DEPENDS+=	js.1:${PORTSDIR}/lang/spidermonkey
CONFIGURE_ARGS+=--without-browser-plugin
PLIST_SUB+=	MOZILLA_PLUGIN="@comment "
.else
USE_GECKO=	firefox mozilla seamonkey xulrunner
USE_WEBPLUGINS=	native
WEBPLUGINS_DIR=	${PREFIX}/lib/gxine
WEBPLUGINS_FILES=gxineplugin.so
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
LIB_DEPENDS+=	nspr4.1:${PORTSDIR}/devel/nspr
CONFIGURE_ENV+=	NSPR_CFLAGS="-I${LOCALBASE}/include/nspr" \
		NSPR_LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--disable-libjs
PLIST_SUB+=	MOZILLA_PLUGIN=""
.endif

.if defined(WITH_XCB)
LIB_DEPENDS+=	xcb.2:${PORTSDIR}/x11/libxcb
.else
CONFIGURE_ARGS+=--without-xcb
.endif

pre-configure:
	@${REINPLACE_CMD} -e "/^mkdir_p/s:@mkdir_p@:${MKDIR}:" \
		${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e "/^mkdir_p/s:@mkdir_p@:${MKDIR}:" \
		${WRKSRC}/misc/po/Makefile.in.in
	@${REINPLACE_CMD} -e "s:@MAKE_PNG_TRUE@:#:g" \
		${WRKSRC}/pixmaps/Makefile.in

.include <bsd.port.post.mk>
