# New ports collection makefile for:	gstreamer
# Date created:		Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer/Makefile,v 1.45 2006/04/28 11:44:33 ahze Exp $

PORTNAME=	gstreamer
PORTVERSION=	0.10.5
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME} \
		http://gstreamer.freedesktop.org/src/gstreamer/
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.10
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Development framework for creating media applications

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
USE_BISON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack gnomeprefix glib20 libxml2 ltverhack
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--disable-tests \
		--disable-examples \
		--disable-docs-build \
		--disable-failing-tests
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		ac_cv_func_register_printf_function="no"
PLIST_SUB=	VERSION="${GST_VERSION}"
INSTALLS_SHLIB=	yes
GST_VERSION=	0.10

MAN1=	gst-feedback-${GST_VERSION}.1 gst-inspect-${GST_VERSION}.1 \
	gst-launch-${GST_VERSION}.1 \
	gst-typefind-${GST_VERSION}.1 gst-xmlinspect-${GST_VERSION}.1 \
	gst-xmllaunch-${GST_VERSION}.1

.include <bsd.port.mk>
