# Ports collection makefile for: gnugadu2
# Date created:		12 january 2004
# Whom: 		smyru@heron.pl
#
# $FreeBSD$
#

PORTNAME=	gnugadu2
PORTVERSION=	2.0.3
CATEGORIES=	polish net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggadu
DISTNAME=	gg2-${PORTVERSION}

MAINTAINER=	smyru@heron.pl
COMMENT=	GTK2 based Gadu-Gadu client for X11

LIB_DEPENDS=	gadu.3:${PORTSDIR}/polish/ekg

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_INC_LIBTOOL_VER=13
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
WANT_GNOME=	yes
CONFLICTS=	qhacc-*

CONFIGURE_ARGS=	--with-gui \
		--with-gadu \
		--with-sms \
		--with-external \
		--with-external-libgadu \
		--with-update

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if (${HAVE_GNOME:Mesound}!="")
WITH_ESOUND=	yes
.endif

.if defined(WITH_GTKSPELL)
CONFIGURE_ARGS+=	--with-gtkspell
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2
.endif

.if defined(WITH_DOCKLET)
CONFIGURE_ARGS+=	--with-docklet_system_tray
PLIST_SUB+=	DOCKLET:=""
.else
CONFIGURE_ARGS+=	--without-docklet_system_tray
PLIST_SUB+=	DOCKLET:="@comment "
.endif

.if defined(WITH_DOCKAPP)
CONFIGURE_ARGS+=	--with-docklet_dockapp
PLIST_SUB+=	DOCKAPP:=""
.else
CONFIGURE_ARGS+=	--without-docklet_dockapp
PLIST_SUB+=	DOCKAPP:="@comment "
.endif

.if defined(WITH_TLEN)
CONFIGURE_ARGS+=	--with-tlen
LIB_DEPENDS+=	tlen.1:${PORTSDIR}/polish/libtlen
PLIST_SUB+=	TLEN:=""
.else
CONFIGURE_ARGS+=	--without-tlen
PLIST_SUB+=	TLEN:="@comment "
.endif

.if defined(WITH_JABBER)
CONFIGURE_ARGS+=	--with-jabber
LIB_DEPENDS+=	loudmouth-1.0:${PORTSDIR}/net/loudmouth
PLIST_SUB+=	JABBER:=""
.else
CONFIGURE_ARGS+=	--without-jabber
PLIST_SUB+=	JABBER:="@comment "
.endif

.if defined(WITH_ESOUND)
CONFIGURE_ARGS+=	--with-esd
PKGNAMESUFFIX=	-esound
USE_GNOME+=	esound
PLIST_SUB+=	ESOUND:=""
.else
CONFIGURE_ARGS+=	--without-esd
PLIST_SUB+=	ESOUND:="@comment "
.endif

.if defined(WITH_ARTS)
CONFIGURE_ARGS+=	--with-arts
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
PLIST_SUB+=	ARTS:=""
.else
CONFIGURE_ARGS+=	--without-arts
PLIST_SUB+=	ARTS:="@comment "
.endif

.if defined(WITH_OSS)
CONFIGURE_ARGS+=	--with-oss
PLIST_SUB+=	OSS:=""
.else
PLIST_SUB+=	OSS:="@comment "
.endif

.if defined(WITH_XOSD)
CONFIGURE_ARGS+=	--with-xosd
LIB_DEPENDS+=	xosd.4:${PORTSDIR}/misc/xosd
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

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "  You can define following build options:"
	@${ECHO_MSG}
	@${ECHO_MSG} "	WITH_TLEN      to enable Tlen.pl network plugin"
	@${ECHO_MSG} "	WITH_JABBER    to enable Jabber loudmouth plugin"
	@${ECHO_MSG} "	WITH_XOSD      to enable On-Screen-Display messages"
	@${ECHO_MSG} "	WITH_DOCKLET   to enable freedesktop.org docklet plugin"
	@${ECHO_MSG} "	WITH_DOCKAPP   to enable WindowMaker dockapp plugin"
	@${ECHO_MSG} "	WITH_OSS       to build with sound via OSS"
	@${ECHO_MSG} "	WITH_ARTS      to build with aRts sound server"
	@${ECHO_MSG} "	WITH_ESOUND    to build with esound sound server"
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
