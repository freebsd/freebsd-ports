# New ports collection makefile for:	openfetion
# Date created:				11 December 2010
# Whom:					Yanhui Shen <shen.elf@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	openfetion
PORTVERSION=	2.0.7
CATEGORIES=	net-im
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	shen.elf@gmail.com
COMMENT=	An open source client for China Mobile's Fetion IM

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3

OPTIONS=	XSCREENSAVER	"Enable X screensaver extension"	on \
		NOTIFY		"Enable libnotify support"		on \
		GSTREAMER	"Enable gstreamer support"		on

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack glib20 gtk20 libxml2 desktopfileutils
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=--disable-nm
CONFIGURE_ENV=	LIBSSL_CFLAGS=-Wl,-rpath,${OPENSSLRPATH} \
		LIBSSL_LIBS=-rpath=${OPENSSLRPATH}

PROJECTHOST=	ofetion
LICENSE=	GPLv2

.include <bsd.port.options.mk>

.if !defined(WITHOUT_XSCREENSAVER)
USE_XORG=	xscrnsaver
CONFIGURE_ARGS+=--enable-screensaver
.else
CONFIGURE_ARGS+=--disable-screensaver
.endif

.if !defined(WITHOUT_GSTREAMER)
USE_GSTREAMER=	yes
CONFIGURE_ARGS+=--enable-gst
.else
CONFIGURE_ARGS+=--disable-gst
.endif

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-libnotify
.else
CONFIGURE_ARGS+=--disable-libnotify
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(DESTDIR)$$(itlocaledir)|$${datarootdir}/locale|g' \
		${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/resource/Makefile.in

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
