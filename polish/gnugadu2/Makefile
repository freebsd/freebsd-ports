# Ports collection makefile for: gnugadu2
# Date created:		12 january 2004
# Whom: 		smyru@heron.pl
#
# $FreeBSD$
#

PORTNAME=	gnugadu2
PORTVERSION=	2.2.5
CATEGORIES=	polish net
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
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
WANT_GNOME=	yes
CONFLICTS=	qhacc-[0-9]*

CONFIGURE_ARGS=	\
		--with-external-libgadu \
		--with-static=no \
		--without-dbus \
		--without-remote

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if (${HAVE_GNOME:Mesound}!="")
WITH_ESOUND=	yes
.endif

.if !defined(WITH_GTKSPELL)
CONFIGURE_ARGS+=	--without-gtkspell
.else
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2
.endif

.if !defined(WITH_DOCKLET)
CONFIGURE_ARGS+=	--without-docklet-system-tray
PLIST_SUB+=	DOCKLET:="@comment "
.else
PLIST_SUB+=	DOCKLET:=""
.endif

.if !defined(WITH_DOCKAPP)
CONFIGURE_ARGS+=	--without-docklet_dockapp
PLIST_SUB+=	DOCKAPP:="@comment "
.else
PLIST_SUB+=	DOCKAPP:=""
.endif

.if !defined(WITH_TLEN)
CONFIGURE_ARGS+=	--without-tlen
PLIST_SUB+=	TLEN:="@comment "
.else
LIB_DEPENDS+=	tlen.1:${PORTSDIR}/polish/libtlen
PLIST_SUB+=	TLEN:=""
.endif

.if !defined(WITH_JABBER)
CONFIGURE_ARGS+=	--without-jabber
PLIST_SUB+=	JABBER:="@comment "
.else
LIB_DEPENDS+=	loudmouth-1.0:${PORTSDIR}/net/loudmouth
PLIST_SUB+=	JABBER:=""
.endif

.if !defined(WITH_ESOUND)
CONFIGURE_ARGS+=	--without-esd
PLIST_SUB+=	ESOUND:="@comment "
.else
PKGNAMESUFFIX=	-esound
USE_GNOME+=	esound
PLIST_SUB+=	ESOUND:=""
.endif

.if !defined(WITH_ARTS)
CONFIGURE_ARGS+=	--without-arts
PLIST_SUB+=	ARTS:="@comment "
.else
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
PLIST_SUB+=	ARTS:=""
.endif

.if !defined(WITH_XOSD)
CONFIGURE_ARGS+=	--without-xosd
PLIST_SUB+=	XOSD:="@comment "
.else
LIB_DEPENDS+=	xosd.4:${PORTSDIR}/misc/xosd
PLIST_SUB+=	XOSD:=""
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

pre-everything::
.if defined(WITH_TLEN) || defined(WITH_JABBER) || defined(WITH_XOSD) || \
	defined(WITH_DOCKLET) || defined(WITH_DOCKAPP) || defined(WITH_GTKSPELL) || \
	defined(WITH_ARTS) || defined(WITH_ESOUND)
	@${ECHO_MSG}
	@${ECHO_MSG} "  You can define following build options:"
	@${ECHO_MSG}
.endif
.if !defined(WITH_TLEN)
	@${ECHO_MSG} "	WITH_TLEN      to enable Tlen.pl network plugin"
.endif
.if !defined(WITH_JABBER)
	@${ECHO_MSG} "	WITH_JABBER    to enable Jabber loudmouth plugin"
.endif
.if !defined(WITH_XOSD)
	@${ECHO_MSG} "	WITH_XOSD      to enable On-Screen-Display messages"
.endif
.if !defined(WITH_DOCKLET)
	@${ECHO_MSG} "	WITH_DOCKLET   to enable freedesktop.org docklet plugin"
.endif
.if !defined(WITH_DOCKAPP)
	@${ECHO_MSG} "	WITH_DOCKAPP   to enable WindowMaker dockapp plugin"
.endif
.if !defined(WITH_ARTS)
	@${ECHO_MSG} "	WITH_ARTS      to build with aRts sound server"
.endif
.if !defined(WITH_ESOUND)
	@${ECHO_MSG} "	WITH_ESOUND    to build with esound sound server"
.endif
.if !defined(WITH_GTKSPELL)
	@${ECHO_MSG} "	WITH_GTKSPELL  to enable GTKSpell checker"
.endif
	@${ECHO_MSG}

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
