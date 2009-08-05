# New ports collection makefile for:	gstreamer
# Date created:		Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer/Makefile,v 1.59 2008/03/21 03:53:00 ahze Exp $
#

PORTNAME=	gstreamer
PORTVERSION=	0.10.24
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gstreamer/ \
		GNOME

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Development framework for creating media applications

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

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

.if (exists(${LOCALBASE}/lib/libcheck.a) || defined(WITH_CHECK))
LIB_DEPENDS+=	check.0:${PORTSDIR}/devel/libcheck
PLIST_SUB+=	CHECK=""
.else
CONFIGURE_ARGS+=--without-check
PLIST_SUB+=	CHECK="@comment "
.endif

.include <bsd.port.post.mk>
