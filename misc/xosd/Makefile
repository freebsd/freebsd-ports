# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	xosd
PORTVERSION=	2.2.14
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SF/libxosd/libxosd/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 on-screen-display program and library

LICENSE=	GPLv2

USES=		gmake pkgconfig
USE_AUTOTOOLS=	libtool
USE_CSTD=	gnu89
USE_XORG=	x11 xext xt sm ice
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LIBS=${PTHREAD_LIBS}' -L${LOCALBASE}/lib' \
		LOCALBASE='${LOCALBASE}' \
		GTK_CONFIG='${GTK_CONFIG}' GLIB_CONFIG='${GLIB_CONFIG}' \
		XMMS_PLUGINDIR=${LOCALBASE}/lib/xmms
CONFIGURE_ARGS=	--disable-beep_media_player_plugin
PATCH_STRIP=	-p1

MAN1=		osd_cat.1 xosd-config.1
MAN3=		xosd.3 xosd_create.3 xosd_destroy.3 xosd_display.3 \
		xosd_get_number_lines.3 xosd_hide.3 xosd_is_onscreen.3 \
		xosd_set_align.3 xosd_set_bar_length.3 \
		xosd_set_horizontal_offset.3 xosd_set_pos.3 \
		xosd_set_shadow_offset.3 xosd_set_vertical_offset.3 \
		xosd_show.3 xosd_uninit.3
PORTDOCS=	AUTHORS ChangeLog TODO

OPTIONS_DEFINE=	XMMS MSEC XFT DOCS
OPTIONS_DEFAULT=	XMMS
XMMS_DESC=	Build and install XMMS-OSD plugin
MSEC_DESC=	Use milliseconds timeout (breaks compatibility!)
XFT_DESC=	Unofficial Xft support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXMMS}
COMMENT+=	(with XMMS plugin)
LIB_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
# shlib version is needed for libgdk_pixbuf, otherwise it could be bogusly
# satisfied by installed `graphics/gdk-pixbuf2'
PLIST_SUB=	XMMS=""
.else
CONFIGURE_ARGS+=	--disable-new-plugin
PLIST_SUB=	XMMS="@comment "
.endif

.if ${PORT_OPTIONS:MMSEC}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-msec-timeout
DELAY_UNITS=	milliseconds
.else
DELAY_UNITS=	seconds
.endif

.if ${PORT_OPTIONS:MXFT}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-xft
USE_GNOME=	pango
USE_XORG+=	xft
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS}, ; \
		s,echo aout,echo elf,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,^\(CFLAGS =\)\(.*\)$$,\1 -I..\2,' \
		${WRKSRC}/src/libxosd/Makefile.in \
		${WRKSRC}/src/xmms_plugin/Makefile.in
	@${REINPLACE_CMD} -e 's,specified time,& (${DELAY_UNITS}),' \
		${WRKSRC}/src/osd_cat.c
.if ${PORT_OPTIONS:MXFT}	# unbreak against Clang
	@${REINPLACE_CMD} -e '52s,^,void xosd_xypos(xosd *osd);,' \
		${WRKSRC}/src/libxosd/xosd.c
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
