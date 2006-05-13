# Ports collection makefile for: gnugadu2
# Date created:		12 january 2004
# Whom: 		smyru@heron.pl
#
# $FreeBSD$
#

PORTNAME=	gnugadu2
PORTVERSION=	2.2.8
PORTREVISION=	2
CATEGORIES=	polish net-im
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggadu
DISTNAME=	gg2-${PORTVERSION}

MAINTAINER=	smyru@heron.pl
COMMENT=	GTK2 based Gadu-Gadu client for X11

LIB_DEPENDS=	gadu.3:${PORTSDIR}/polish/ekg \
		audiofile.0:${PORTSDIR}/audio/libaudiofile

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
WANT_GNOME=	yes
CONFLICTS=	qhacc-[0-9]*

CONFIGURE_ARGS=	\
		--disable-esdtest \
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
		--without-dbus \
		--without-gnutls \
		--without-perl \
		--without-remote

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	TLEN	"Enable Tlen.pl network plugin"	off \
		JABBER	"Enable Jabber loudmouth plugin"	off \
		DOCKLET	"Enable fd.o docklet plugin"	on \
		DOCKAPP	"Enable WindowMaker dockapp plugin"	off \
		GTKSPELL	"Enable GTKSpell checker"	off \
		XOSD	"Enable On-Screen-Display messages"	off \
		ARTS	"Build with aRts sound server"	off \
		ESOUND	"Build with esound sound server"	off

.include <bsd.port.pre.mk>

.if (${HAVE_GNOME:Mesound}!="")
WITH_ESOUND=	yes
.endif

# does not work with newer dbus versions
#.if exists(${LOCALBASE}/lib/libdbus-1.so)
#WITH_DBUS=	yes
#.endif

.if exists(${X11BASE}/lib/libgtkspell.so)
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
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2
CONFIGURE_ARGS+=	--with-gtkspell
.else
CONFIGURE_ARGS+=	--without-gtkspell
.endif

#.if defined(WITH_DBUS)
#LIB_DEPENDS+=	dbus-1.2:${PORTSDIR}/devel/dbus
#CONFIGURE_ARGS+=	--with-dbus \
#			--with-dbus-dir=${LOCALBASE}/share/dbus-1/services
#PLIST_SUB+=	DBUS:=""
#.else
#CONFIGURE_ARGS+=	--without-dbus
#PLIST_SUB+=	DBUS:="@comment "
#.endif

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

.if (${HAVE_GNOME:Mgnomehier}!="")
PLIST_SUB+=	GNOME:=""
.else
PLIST_SUB+=	GNOME:="@comment "
.endif
.if exists(${LOCALBASE}/lib/libkdecore.so)
PLIST_SUB+=	KDE:=""
.else
PLIST_SUB+=	KDE:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' ${WRKSRC}/gg2.desktop
	@${REINPLACE_CMD} -e 's| -ldl|| ; s|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/lib/Makefile.in
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' ${WRKSRC}/src/plugins/gadu_gadu/libgadu/lib/libgadu-config.h.in
.endif

post-install:
.if (${HAVE_GNOME:Mgnomehier}!="")
	${INSTALL_DATA} ${WRKSRC}/gg2.desktop ${X11BASE}/share/gnome/apps/Internet
	${LN} -sf ${PREFIX}/share/pixmaps/gg2.png ${X11BASE}/share/gnome/pixmaps
.endif
.if exists(${LOCALBASE}/lib/libkdecore.so)
	${INSTALL_DATA} ${WRKSRC}/gg2.desktop ${LOCALBASE}/share/applnk/Internet
.endif

.include <bsd.port.post.mk>
