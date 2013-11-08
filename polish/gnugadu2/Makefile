# Created by: smyru@heron.pl
# $FreeBSD$

PORTNAME=	gnugadu2
PORTVERSION=	2.3.0
PORTREVISION=	12
CATEGORIES=	polish net-im
MASTER_SITES=	SF/ggadu/gg2/${PORTVERSION}
DISTNAME=	gg2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gadu-Gadu IM network client

LIB_DEPENDS=	gadu.3:${PORTSDIR}/polish/libgadu \
		libaudiofile.so:${PORTSDIR}/audio/libaudiofile

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USES=		gettext gmake perl5 pkgconfig
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
USE_XORG=	x11 xaw ice xscrnsaver
WANT_GNOME=	yes
# there is a header conflict here, that breaks build
CONFLICTS=	qhacc-[0-9]*

CONFIGURE_ARGS=	--disable-esdtest \
		--with-external-libgadu \
		--with-static=no \
		--with-aaway \
		--with-external \
		--with-gghist \
		--with-gui \
		--with-ignore \
		--with-oss \
		--with-sms \
		--with-update \
		--without-arts \
		--without-gnutls \
		--without-perl \
		--without-remote

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	AUTODETECT DBUS DOCKAPP DOCKLET ESOUND \
		GTKSPELL JABBER TLEN XOSD
OPTIONS_DEFAULT=DOCKLET

AUTODETECT_DESC=Autodetect plugins
DOCKLET_DESC=	Enable fd.o docklet plugin
DOCKAPP_DESC=	Enable WindowMaker dockapp plugin
GTKSPELL_DESC=	Enable GTKSpell checker
TLEN_DESC=	Enable Tlen.pl network plugin
XOSD_DESC=	Enable On-Screen-Display messages

#.if ${${HAVE_GNOME:Mesound}!="" && empty(PORT_OPTIONS:MESOUND)

NO_STAGE=	yes
.include <bsd.port.pre.mk> # can't change this untile HAVE_GNOME has been fixed

.if ${PORT_OPTIONS:MAUTODETECT}
#detect dbus - only works with old versions
.if exists(${LOCALBASE}/lib/libdbus-1.so)  && !${PORT_OPTIONS:MDBUS}
PORT_OPTIONS+=	DBUS
.endif
#detect esound
.if ${HAVE_GNOME:Mesound}!="" && !${PORT_OPTIONS:MESOUND}
PORT_OPTIONS+=	ESOUND
.endif
#detect gtkspell
.if exists(${LOCALBASE}/lib/libgtkspell.so) && !${PORT_OPTIONS:MGTKSPELL}
PORT_OPTIONS+=	GTKSPELL
.endif
.endif

.if ${PORT_OPTIONS:MTLEN}
LIB_DEPENDS+=	tlen.1:${PORTSDIR}/polish/libtlen
CONFIGURE_ARGS+=	--with-tlen
PLIST_SUB+=	TLEN:=""
.else
CONFIGURE_ARGS+=	--without-tlen
PLIST_SUB+=	TLEN:="@comment "
.endif

.if ${PORT_OPTIONS:MJABBER}
LIB_DEPENDS+=	loudmouth-1.0:${PORTSDIR}/net-im/loudmouth
CONFIGURE_ARGS+=	--with-jabber
PLIST_SUB+=	JABBER:=""
.else
CONFIGURE_ARGS+=	--without-jabber
PLIST_SUB+=	JABBER:="@comment "
.endif

.if !${PORT_OPTIONS:MDOCKLET}
CONFIGURE_ARGS+=	--without-docklet-system-tray
PLIST_SUB+=	DOCKLET:="@comment "
.else
CONFIGURE_ARGS+=	--with-docklet-system-tray
PLIST_SUB+=	DOCKLET:=""
.endif

.if ${PORT_OPTIONS:MDOCKAPP}
CONFIGURE_ARGS+=	--with-docklet_dockapp
PLIST_SUB+=	DOCKAPP:=""
.else
CONFIGURE_ARGS+=	--without-docklet_dockapp
PLIST_SUB+=	DOCKAPP:="@comment "
.endif

.if ${PORT_OPTIONS:MGTKSPELL}
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=	--with-gtkspell
.else
CONFIGURE_ARGS+=	--without-gtkspell
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--with-dbus \
			--with-dbus-dir=${PREFIX}/share/dbus-1/services
PLIST_SUB+=	DBUS:=""
.else
CONFIGURE_ARGS+=	--without-dbus
PLIST_SUB+=	DBUS:="@comment "
.endif

.if ${PORT_OPTIONS:MESOUND}
PKGNAMESUFFIX=	-esound
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--with-esd
PLIST_SUB+=	ESOUND:=""
.else
CONFIGURE_ARGS+=	--without-esd
PLIST_SUB+=	ESOUND:="@comment "
.endif

.if ${PORT_OPTIONS:MXOSD}
LIB_DEPENDS+=	xosd.4:${PORTSDIR}/misc/xosd
CONFIGURE_ARGS+=	--with-xosd
PLIST_SUB+=	XOSD:=""
.else
CONFIGURE_ARGS+=	--without-xosd
PLIST_SUB+=	XOSD:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,=.*},=${PREFIX},' ${WRKSRC}/src/plugins/dbus/org.freedesktop.im.GG.service
	@${REINPLACE_CMD} -e 's, -ldl,, ; s,(libdir)/pkgconfig,(prefix)/libdata/pkgconfig,' ${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -e 's,(datadir)/pixmaps,(datadir)/icons/hicolor/48x48/apps,' ${WRKSRC}/pixmaps/Makefile.in
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' ${WRKSRC}/src/plugins/GUI/gtkimhtml.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/gg2.desktop ${PREFIX}/share/applications/

# vim: set ts=8 sw=8:
.include <bsd.port.post.mk>
