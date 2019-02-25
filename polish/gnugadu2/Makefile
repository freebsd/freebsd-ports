# Created by: smyru@heron.pl
# $FreeBSD$

PORTNAME=	gnugadu2
PORTVERSION=	2.3.0
PORTREVISION=	17
CATEGORIES=	polish net-im
MASTER_SITES=	SF/ggadu/gg2/${PORTVERSION}
DISTNAME=	gg2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gadu-Gadu IM network client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		libgadu.so:polish/libgadu \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USES=		gettext gmake libtool localbase pathfix perl5 pkgconfig tar:bzip2
USE_GNOME=	cairo gtk20
USE_LDCONFIG=	yes
USE_XORG=	x11 xaw ice xscrnsaver
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
		--without-remote \
		--without-esd

OPTIONS_DEFINE=	DBUS DOCKAPP DOCKLET \
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

GTKSPELL_BUILD_DEPENDS=	pl-aspell>0:polish/aspell
GTKSPELL_LIB_DEPENDS=	libgtkspell.so:textproc/gtkspell
GTKSPELL_RUN_DEPENDS=	pl-aspell>0:polish/aspell
GTKSPELL_CONFIGURE_WITH=	gtkspell

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus \
			libdbus-glib-1.so:devel/dbus-glib
DBUS_CONFIGURE_WITH=	dbus
DBUS_CONFIGURE_ON=	--with-dbus-dir=${PREFIX}/share/dbus-1/services

XOSD_LIB_DEPENDS=	libxosd.so:misc/xosd
XOSD_USE=		XORG=xext,xinerama
XOSD_CONFIGURE_WITH=	xosd

post-patch:
	@${REINPLACE_CMD} -e 's,=.*},=${PREFIX},' ${WRKSRC}/src/plugins/dbus/org.freedesktop.im.GG.service
	@${REINPLACE_CMD} -e 's, -ldl,,' ${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -e 's,(datadir)/pixmaps,(datadir)/icons/hicolor/48x48/apps,' ${WRKSRC}/pixmaps/Makefile.in
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' ${WRKSRC}/src/plugins/GUI/gtkimhtml.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/gg2.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
