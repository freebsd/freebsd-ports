# New ports collection makefile for:	gstreamer
# Date created:		Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.6
DIST_SUBDIR=	gnome2

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Development framework for creating media applications

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

USE_X_PREFIX=	yes
USE_BISON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GNOME=	gnomehack \
		gnomeprefix \
		glib20 \
		pkgconfig \
		libxml2
USE_SIZE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --disable-tests \
		--disable-failing-tests
CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG} \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
CONFIGURE_TARGET=
PLIST_SUB=	\
		VERSION="${PORTVERSION:C/..$//}" \
		SHLIB_VERSION="${SHLIB_VERSION}"
INSTALLS_SHLIB=	yes

MAN1=	gst-complete.1 gst-compprep.1 gst-inspect.1 gst-launch.1 \
	gst-feedback.1 gst-md5sum.1 \
	gst-typefind.1 \
	gst-register.1 gst-xmllaunch.1

PKG_CONFIG?="${LOCALBASE}/bin/pkg-config"

# library minor number
SHLIB_VERSION=	1

post-install:
# register plugins
	@${PREFIX}/bin/gst-register 2>/dev/null

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=	libgnomeui
.endif

.include <bsd.port.post.mk>
