# New ports collection makefile for:	xosd
# Date created:			2 May 2001
# Whom:				Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	xosd
PORTVERSION=	1.1.1
CATEGORIES=	misc
MASTER_SITES=	http://www.ignavus.net/

MAINTAINER=	perky@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		xmms.3:${PORTSDIR}/audio/xmms

XMMS_CONFIG?=	${X11BASE}/bin/xmms-config
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes
USE_AUTOMAKE_VER=	15
AUTOMAKE_ARGS=	--add-missing
USE_AUTOCONF=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	LIBS=${PTHREAD_LIBS}' -L${LOCALBASE}/lib -lgnugetopt' \
		CFLAGS='${CFLAGS}' X11BASE='${X11BASE}' \
		GTK_CONFIG='${GTK_CONFIG}' GLIB_CONFIG='${GLIB_CONFIG}' \
		XMMS_PLUGINDIR=${X11BASE}/lib/xmms

MAN1=		osd_cat.1
MAN3=		xosd.3 xosd_display.3 xosd_get_number_lines.3 xosd_hide.3 \
		xosd_init.3 xosd_is_onscreen.3 xosd_set_align.3 \
		xosd_set_offset.3 xosd_set_pos.3 xosd_set_shadow_offset.3 \
		xosd_show.3 xosd_uninit.3

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --force && ${ACLOCAL}

.include <bsd.port.mk>
