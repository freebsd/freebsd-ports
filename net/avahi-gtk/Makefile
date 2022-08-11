PORTREVISION=	0
CATEGORIES=	net
PKGNAMESUFFIX=	-gtk

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gtk+ tools and bindings to the Avahi mDNS system

LIB_DEPENDS=	libavahi-common.so:net/avahi-app \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgdbm.so:databases/gdbm \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	avahi-header>=0.6:net/avahi-header

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-ui
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	gtk
AVAHI_PKGCONFIG=avahi-ui.pc

USE_GNOME+=	atk cairo gdkpixbuf2 gtk20 pango

do-build:
	@${DO_MAKE_BUILD} -C ${WRKSRC}/avahi-common
	@${DO_MAKE_BUILD} -C ${WRKSRC}/avahi-client
	@${DO_MAKE_BUILD} -C ${WRKSRC}/avahi-glib
	@${DO_MAKE_BUILD} -C ${WRKSRC}/avahi-ui libavahi-ui.la

do-install:
	@(cd ${WRKSRC}/avahi-ui; ${MAKE_CMD} ${MAKE_ARGS} install-libLTLIBRARIES)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libavahi-ui.so.0

.include "${MASTERDIR}/Makefile"
