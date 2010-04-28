# New ports collection makefile for:	gstreamer
# Date created:		Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer/Makefile,v 1.74 2010/03/09 10:11:45 kwm Exp $
#

PORTNAME=	gstreamer
PORTVERSION=	0.10.29
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gstreamer/ \
		GNOME

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Development framework for creating media applications

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection

CFLAGS:=	${CFLAGS} -O2 -Wno-format
USE_BISON=	build
USE_XORG=	x11 xv xext videoproto xextproto
USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack glib20 libxml2 ltverhack ltasneededhack
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--disable-tests \
		--disable-examples \
		--disable-failing-tests \
		--disable-gtk-doc
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		ac_cv_func_register_printf_function="no" \
		FLEX_PATH="${LOCALBASE}/bin/flex"
PLIST_SUB=	VERSION="${GST_VERSION}"
USE_LDCONFIG=	yes
GST_VERSION=	0.10

MAN1=	gst-feedback-${GST_VERSION}.1 gst-inspect-${GST_VERSION}.1 \
	gst-launch-${GST_VERSION}.1 \
	gst-typefind-${GST_VERSION}.1 gst-xmlinspect-${GST_VERSION}.1 \
	gst-xmllaunch-${GST_VERSION}.1

.include <bsd.port.pre.mk>

# workaround a gcc bug on 6.x
.if ${OSVERSION} < 700000
CONFIGURE_ENV+=	gst_cv_uint128_t="no"
.endif

.if (exists(${LOCALBASE}/lib/libcheck.a) || defined(WITH_CHECK))
LIB_DEPENDS+=	check.0:${PORTSDIR}/devel/libcheck
PLIST_SUB+=	CHECK=""
.else
CONFIGURE_ARGS+=--disable-check
PLIST_SUB+=	CHECK="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Wmissing-include-dirs||g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
