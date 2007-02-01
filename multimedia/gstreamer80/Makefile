# New ports collection makefile for:	gstreamer
# Date created:		Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer80/Makefile,v 1.43 2006/09/10 00:53:00 mezz Exp $
#

PORTNAME=	gstreamer
PORTVERSION=	0.8.12
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gstreamer/
PKGNAMESUFFIX=	80
DIST_SUBDIR=	gnome2

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Development framework for creating media applications

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

DEPRECATED=	Obsolete version, use gstreamer 0.10 instead
EXPIRATION_DATE=2007-05-31

USE_AUTOTOOLS=	libtool:15
USE_XLIB=	yes
USE_BISON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack \
		gnomeprefix \
		glib20 \
		libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests \
		--disable-examples \
		--disable-docs-build \
		--disable-failing-tests
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
PLIST_SUB=	\
		VERSION="${GST_VERSION}" \
		SHLIB_VERSION="${SHLIB_VERSION}" \
		PORTVERSION="${PORTVERSION}"
USE_LDCONFIG=	yes

MAN1=	gst-complete-${GST_VERSION}.1 gst-compprep-${GST_VERSION}.1 \
	gst-feedback-${GST_VERSION}.1 gst-inspect-${GST_VERSION}.1 \
	gst-launch-${GST_VERSION}.1 gst-md5sum-${GST_VERSION}.1 \
	gst-register-${GST_VERSION}.1 gst-typefind-${GST_VERSION}.1 \
	gst-xmllaunch-${GST_VERSION}.1 gst-xmlinspect-${GST_VERSION}.1

GST_VERSION=${PORTVERSION:C/...$//}

# library minor number
SHLIB_VERSION=	5

.include <bsd.port.pre.mk>

.if ( ( ${OSVERSION} < 504101 ) || ( ${OSVERSION} >= 600000 && ${OSVERSION} < 600012 ) )
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-gst::cothreads.c
.endif

post-install:
# register plugins
	-@${PREFIX}/bin/gst-register-${GST_VERSION} \
		--gst-registry=${PREFIX}/share/gnome/cache/gstreamer-${GST_VERSION}/registry.xml 2>/dev/null

.include <bsd.port.post.mk>
