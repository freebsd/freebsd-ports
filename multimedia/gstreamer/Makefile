# New ports collection makefile for:	gstreamer
# Date created:		Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.8.4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME} \
		http://gstreamer.freedesktop.org/src/gstreamer/pre/
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.8
DIST_SUBDIR=	gnome2

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Development framework for creating media applications

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
USE_BISON=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack \
		gnomeprefix \
		glib20 \
		pkgconfig \
		libxml2
USE_LIBTOOL_VER=15
CONFIGURE_ARGS= --disable-tests \
		--disable-failing-tests
CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG} \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
PLIST_SUB=	\
		VERSION="${GST_VERSION}" \
		SHLIB_VERSION="${SHLIB_VERSION}" \
		PORTVERSION="${PORTVERSION}"
INSTALLS_SHLIB=	yes

MAN1=	gst-complete-${GST_VERSION}.1 gst-compprep-${GST_VERSION}.1 \
	gst-feedback-${GST_VERSION}.1 gst-inspect-${GST_VERSION}.1 \
	gst-launch-${GST_VERSION}.1 gst-md5sum-${GST_VERSION}.1 \
	gst-register-${GST_VERSION}.1 gst-typefind-${GST_VERSION}.1 \
	gst-xmllaunch-${GST_VERSION}.1 gst-xmlinspect-${GST_VERSION}.1

PKG_CONFIG?="${LOCALBASE}/bin/pkg-config"
GST_VERSION=${PORTVERSION:C/..$//}

# library minor number
SHLIB_VERSION=	4

post-install:
# register plugins
	-@${PREFIX}/bin/gst-register-${GST_VERSION} \
		--gst-registry=${PREFIX}/share/gnome/cache/gstreamer-${GST_VERSION}/registry.xml 2>/dev/null

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=	libgnomeui
.endif

.include <bsd.port.post.mk>
