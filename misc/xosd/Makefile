# New ports collection makefile for:	xosd
# Date created:			2 May 2001
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	xosd
PORTVERSION=	2.2.12
PORTREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	http://www.ignavus.net/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	perky

MAINTAINER=	perky@FreeBSD.org
COMMENT=	X On-Screen-Display Library and XMMS plug-in

XMMS_CONFIG?=	${LOCALBASE}/bin/xmms-config
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11 xext xt sm ice
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ENV=	LIBS=${PTHREAD_LIBS}' -L${LOCALBASE}/lib' \
		CFLAGS='${CFLAGS}' LOCALBASE='${LOCALBASE}' \
		GTK_CONFIG='${GTK_CONFIG}' GLIB_CONFIG='${GLIB_CONFIG}' \
		XMMS_PLUGINDIR=${LOCALBASE}/lib/xmms

MAN1=		osd_cat.1 xosd-config.1
MAN3=		xosd.3 xosd_create.3 xosd_destroy.3 xosd_display.3 \
		xosd_get_number_lines.3 xosd_hide.3 xosd_is_onscreen.3 \
		xosd_set_align.3 xosd_set_bar_length.3 \
		xosd_set_horizontal_offset.3 xosd_set_pos.3 \
		xosd_set_shadow_offset.3 xosd_set_vertical_offset.3 \
		xosd_show.3 xosd_uninit.3

OPTIONS=	XMMS "Install XMMS-OSD plugin" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf
PLIST_SUB=	WITH_XMMS=""
.else
CONFIGURE_ARGS=	--disable-new-plugin
PLIST_SUB=	WITH_XMMS="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's,-lc_r,-lblahblah,g' ${WRKSRC}/ltmain.sh
	@${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},g ; s,echo aout,echo elf,' ${WRKSRC}/configure
.for f in src/libxosd/Makefile.in src/xmms_plugin/Makefile.in
	@${REINPLACE_CMD} -e 's,^\(CFLAGS =\)\(.*\)$$,\1 -I.. \2,g' ${WRKSRC}/$f
.endfor

.include <bsd.port.post.mk>
