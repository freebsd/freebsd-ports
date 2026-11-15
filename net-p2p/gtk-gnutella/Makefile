PORTNAME=	gtk-gnutella
DISTVERSION=	1.3.2
CATEGORIES=	net-p2p
MASTER_SITES=	SF

MAINTAINER=	alven@FreeBSD.org
COMMENT=	GTK-based Gnutella client
WWW=		https://gtk-gnutella.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		gmake gnome iconv localbase:ldflags pkgconfig tar:xz
USE_GNOME=	glib20 libxml2

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-O -Dcc='${CC}' \
		-Dlocale='${PREFIX}/share/locale' \
		-Dlocincpth='${LOCALBASE}/include' \
		-Dloclibpth='${LOCALBASE}/lib' \
		-Dmansrc='${PREFIX}/share/man/man1' \
		-Doptimize='${CFLAGS} ${CPPFLAGS}' \
		-Dprefix='${PREFIX}' \
		-Dprivlib='${DATADIR}' \
		-Dyacc='byacc' \
		-Dusemymalloc='n'

MAKE_ARGS=	INSTALL_PREFIX="${STAGEDIR}"
INSTALL_TARGET=	install install.man

PLIST_SUB=	ARCH="${ARCH:C/powerpc.*/powerpc/:C/armv./arm/}" OPSYS="${OPSYS:tl}"
PORTDOCS=	*

OPTIONS_DEFINE=		DBUS DEBUG DOCS GUI IPV6 NLS PORTABILITY TLS
OPTIONS_DEFAULT=	GUI TLS
OPTIONS_SUB=		yes

PORTABILITY_DESC=	Use the PATH variable at run-time

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CONFIGURE_OFF=	-Ud_dbus
DEBUG_CONFIGURE_ON=	-Ud_official
GUI_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
GUI_USE=		gnome=gtk20,cairo
GUI_CONFIGURE_OFF=	-Dd_headless
IPV6_CONFIGURE_OFF=	-Ud_ipv6
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	-Ud_nls

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

post-install-DOCS-on:
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-GUI-on:
.for i in 16 32 128 256 512
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps
	cd ${WRKSRC}/extra_files && ${INSTALL_DATA} gtk-gnutella.${i}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/gtk-gnutella.png
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	cd ${WRKSRC}/extra_files && ${INSTALL_DATA} gtk-gnutella.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include <bsd.port.mk>
