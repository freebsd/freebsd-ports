# Created by: Rod Taylor <rbt@zort.on.ca>

PORTNAME=	gtk-gnutella
PORTVERSION=	1.2.2
CATEGORIES=	net-p2p
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK based Gnutella client

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		gmake gnome iconv localbase:ldflags pkgconfig tar:xz
USE_GNOME=	glib20 libxml2
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-O -Dyacc='byacc' \
		-Dprefix='${PREFIX}' \
		-Dprivlib='${DATADIR}' \
		-Dmansrc='${MANPREFIX}/man/man1' \
		-Dlocale='${PREFIX}/share/locale' \
		-Dcc='${CC}' -Doptimize='${CFLAGS}' \
		-Dccflags='${CPPFLAGS}' -Dldflags='${LDFLAGS}' \
		-Dusemymalloc='n'
MAKE_ARGS=	INSTALL_PREFIX="${STAGEDIR}"
INSTALL_TARGET=	install install.man

PLIST_SUB=	ARCH="${ARCH:C/powerpc.*/powerpc/:C/armv./arm/}" OPSYS="${OPSYS:tl}"

OPTIONS_DEFINE=		DBUS DEBUG GUI IPV6 NLS PORTABILITY TLS
OPTIONS_DEFAULT=	GUI TLS
OPTIONS_SUB=		yes

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_OFF=	-Ud_dbus
DEBUG_CONFIGURE_ON=	-Ud_official
GUI_USE=		gnome=gtk20,cairo
GUI_CONFIGURE_OFF=	-Dd_headless
GUI_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
IPV6_CONFIGURE_OFF=	-Ud_ipv6
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	-Ud_nls
PORTABILITY_DESC=	Use the PATH variable at run-time
PORTABILITY_CONFIGURE_ON=	-Dd_portable
TLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
TLS_CONFIGURE_OFF=	-Ud_gnutls

.if !defined(INTERACTIVE_CONFIGURE)
CONFIGURE_ARGS+=	-ders
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.SH" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@exit 0|@echo done|'
# Use memory alignment constraints as in version 1.1.15 to unbreak the
# build on 32-bit architectures
	@${REINPLACE_CMD} -e 's,^#ifdef XMALLOC_IS_MALLOC,#if __SIZE_WIDTH__\
		== 32,' ${WRKSRC}/src/lib/xmalloc.h

post-patch-DEBUG-off:
	@${REINPLACE_CMD} 's/(INSTALL) -c -m 555/(INSTALL) -c -s -m 555/g' \
		${WRKSRC}/src/Makefile.SH

post-install-GUI-on:
.for i in 16 32 128 256 512
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	(cd ${WRKSRC}/extra_files && ${INSTALL_DATA} gtk-gnutella.${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/gtk-gnutella.png)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	(cd ${WRKSRC}/extra_files && ${INSTALL_DATA} gtk-gnutella.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/gtk-gnutella.svg)

.include <bsd.port.mk>
