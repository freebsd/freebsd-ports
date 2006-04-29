# New ports collection makefile for:	gstreamer
# Date created:		Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer80/Makefile,v 1.40 2006/04/23 22:58:42 mezz Exp $
#

PORTNAME=	gstreamer
PORTVERSION=	0.8.12
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME} \
		http://gstreamer.freedesktop.org/src/gstreamer/
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${GST_VERSION}
PKGNAMESUFFIX=	80
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Development framework for creating media applications

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
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
INSTALLS_SHLIB=	yes

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
