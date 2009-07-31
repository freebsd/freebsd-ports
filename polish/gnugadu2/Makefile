# Ports collection makefile for: gnugadu2
# Date created:		12 january 2004
# Whom: 		smyru@heron.pl
#
# $FreeBSD$
#

PORTNAME=	gnugadu2
PORTVERSION=	2.3.0
PORTREVISION=	7
CATEGORIES=	polish net-im
MASTER_SITES=	SF/ggadu
DISTNAME=	gg2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gadu-Gadu IM network client

LIB_DEPENDS=	gadu.3:${PORTSDIR}/polish/libgadu \
		audiofile.0:${PORTSDIR}/audio/libaudiofile

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
USE_PERL5=	yes
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
		--without-gnutls \
		--without-perl \
		--without-remote

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	TLEN	"Enable Tlen.pl network plugin"		off \
		JABBER	"Enable Jabber loudmouth plugin"	off \
		DBUS	"Enable D-Bus plugin"			off \
		DOCKLET	"Enable fd.o docklet plugin"		on \
		DOCKAPP	"Enable WindowMaker dockapp plugin"	off \
		GTKSPELL	"Enable GTKSpell checker"	off \
		XOSD	"Enable On-Screen-Display messages"	off \
		ARTS	"Build with aRts sound server"		off \
		ESOUND	"Build with esound sound server"	off

.include <bsd.port.pre.mk>

.if (${HAVE_GNOME:Mesound}!="") && !defined(WITHOUT_ESOUND)
WITH_ESOUND=	yes
.endif

# does not work with newer dbus versions
.if exists(${LOCALBASE}/lib/libdbus-1.so) && !defined(WITHOUT_DBUS)
WITH_DBUS=	yes
.endif

.if exists(${LOCALBASE}/lib/libgtkspell.so) && !defined(WITHOUT_GTKSPELL)
WITH_GTKSPELL=	yes
.endif

.if defined(WITH_TLEN)
LIB_DEPENDS+=	tlen.1:${PORTSDIR}/polish/libtlen
CONFIGURE_ARGS+=	--with-tlen
PLIST_SUB+=	TLEN:=""
.else
CONFIGURE_ARGS+=	--without-tlen
PLIST_SUB+=	TLEN:="@comment "
.endif

.if defined(WITH_JABBER)
LIB_DEPENDS+=	loudmouth-1.0:${PORTSDIR}/net-im/loudmouth
CONFIGURE_ARGS+=	--with-jabber
PLIST_SUB+=	JABBER:=""
.else
CONFIGURE_ARGS+=	--without-jabber
PLIST_SUB+=	JABBER:="@comment "
.endif

.if defined(WITHOUT_DOCKLET)
CONFIGURE_ARGS+=	--without-docklet-system-tray
PLIST_SUB+=	DOCKLET:="@comment "
.else
CONFIGURE_ARGS+=	--with-docklet-system-tray
PLIST_SUB+=	DOCKLET:=""
.endif

.if defined(WITH_DOCKAPP)
CONFIGURE_ARGS+=	--with-docklet_dockapp
PLIST_SUB+=	DOCKAPP:=""
.else
CONFIGURE_ARGS+=	--without-docklet_dockapp
PLIST_SUB+=	DOCKAPP:="@comment "
.endif

.if defined(WITH_GTKSPELL)
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=	--with-gtkspell
.else
CONFIGURE_ARGS+=	--without-gtkspell
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=	--with-dbus \
			--with-dbus-dir=${PREFIX}/share/dbus-1/services
PLIST_SUB+=	DBUS:=""
.else
CONFIGURE_ARGS+=	--without-dbus
PLIST_SUB+=	DBUS:="@comment "
.endif

.if defined(WITH_ESOUND)
PKGNAMESUFFIX=	-esound
USE_GNOME+=	esound
CONFIGURE_ARGS+=	--with-esd
PLIST_SUB+=	ESOUND:=""
.else
CONFIGURE_ARGS+=	--without-esd
PLIST_SUB+=	ESOUND:="@comment "
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
CONFIGURE_ARGS+=	--with-arts
PLIST_SUB+=	ARTS:=""
.else
CONFIGURE_ARGS+=	--without-arts
PLIST_SUB+=	ARTS:="@comment "
.endif

.if defined(WITH_XOSD)
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

post-install:
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gg2.desktop ${PREFIX}/share/applications/

# vim: set ts=8 sw=8:
.include <bsd.port.post.mk>
