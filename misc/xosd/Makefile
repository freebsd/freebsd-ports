# New ports collection makefile for:	xosd
# Date created:			2 May 2001
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	xosd
PORTVERSION=	2.2.5
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.ignavus.net/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	perky

MAINTAINER=	perky@FreeBSD.org
COMMENT=	X On-Screen-Display Library and XMMS plug-in

LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
.if !defined(WITHOUT_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
.endif

XMMS_CONFIG?=	${X11BASE}/bin/xmms-config
USE_GETOPT_LONG=yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	LIBS=${PTHREAD_LIBS}' -L${LOCALBASE}/lib' \
		CFLAGS='${CFLAGS}' X11BASE='${X11BASE}' \
		GTK_CONFIG='${GTK_CONFIG}' GLIB_CONFIG='${GLIB_CONFIG}' \
		XMMS_PLUGINDIR=${X11BASE}/lib/xmms
.if defined(WITHOUT_XMMS)
CONFIGURE_ARGS=	--disable-new-plugin
PLIST_SUB=	WITH_XMMS="@comment "
PKGNAMESUFFIX=	-without-xmms
.else
PLIST_SUB=	WITH_XMMS=""
.endif

MAN1=		osd_cat.1 xosd-config.1
MAN3=		xosd_destroy.3 xosd_is_onscreen.3 xosd_set_shadow_offset.3 \
		xosd_display.3 xosd_set_align.3 xosd_set_vertical_offset.3 \
		xosd.3 xosd_get_number_lines.3 xosd_set_horizontal_offset.3 \
		xosd_show.3 xosd_create.3 xosd_hide.3 xosd_set_pos.3 \
		xosd_uninit.3 xosd_set_bar_length.3

pre-patch:
	${REINPLACE_CMD} -e 's,-lc_r,-lblahblah,g' ${WRKSRC}/ltmain.sh
	${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},g' ${WRKSRC}/configure
.for f in src/libxosd/Makefile.in src/xmms_plugin/Makefile.in
	${REINPLACE_CMD} -e 's,^\(CFLAGS =\)\(.*\)$$,\1 -I.. \2,g' ${WRKSRC}/$f
.endfor

.include <bsd.port.mk>
