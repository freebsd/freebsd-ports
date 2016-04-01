# Created by: smyru@heron.pl
# $FreeBSD$

PORTNAME=	gnugadu2
PORTVERSION=	2.3.0
PORTREVISION=	15
CATEGORIES=	polish net-im
MASTER_SITES=	SF/ggadu/gg2/${PORTVERSION}
DISTNAME=	gg2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gadu-Gadu IM network client

LIB_DEPENDS=	libgadu.so:polish/libgadu \
		libaudiofile.so:audio/libaudiofile

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		gettext gmake perl5 pkgconfig tar:bzip2 libtool
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
USE_XORG=	x11 xaw ice xscrnsaver
WANT_GNOME=	yes
INSTALL_TARGET=	install-strip
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

OPTIONS_DEFINE=	DBUS DOCKAPP DOCKLET ESOUND \
		GTKSPELL JABBER TLEN XOSD
OPTIONS_DEFAULT=DOCKLET
OPTIONS_SUB=	yes

DOCKLET_DESC=	Enable fd.o docklet plugin
DOCKAPP_DESC=	Enable WindowMaker dockapp plugin
GTKSPELL_DESC=	Enable GTKSpell checker
TLEN_DESC=	Enable Tlen.pl network plugin
XOSD_DESC=	Enable On-Screen-Display messages

TLEN_LIB_DEPENDS=	libtlen.so:polish/libtlen
TLEN_CONFIGURE_WITH=	tlen

JABBER_LIB_DEPENDS=	libloudmouth-1.so:net-im/loudmouth
JABBER_CONFIGURE_WITH=	jabber

DOCKLET_CONFIGURE_WITH=	docklet-system-tray

DOCKAPP_CONFIGURE_WITH=	docklet_dockapp

GTKSPELL_LIB_DEPENDS=	libgtkspell.so:textproc/gtkspell
GTKSPELL_CONFIGURE_WITH=	gtkspell

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_WITH=	dbus
DBUS_CONFIGURE_ON=	--with-dbus-dir=${PREFIX}/share/dbus-1/services

ESOUND_USE=	GNOME=esound
ESOUND_CONFIGURE_WITH=	esd

XOSD_LIB_DEPENDS=	libxosd.so:misc/xosd
XOSD_CONFIGURE_WITH=	xosd

post-patch:
	@${REINPLACE_CMD} -e 's,=.*},=${PREFIX},' ${WRKSRC}/src/plugins/dbus/org.freedesktop.im.GG.service
	@${REINPLACE_CMD} -e 's, -ldl,, ; s,(libdir)/pkgconfig,(prefix)/libdata/pkgconfig,' ${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -e 's,(datadir)/pixmaps,(datadir)/icons/hicolor/48x48/apps,' ${WRKSRC}/pixmaps/Makefile.in
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' ${WRKSRC}/src/plugins/GUI/gtkimhtml.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/gg2.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
