# New ports collection makefile for:	gstreamer
# Date created:		Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.6.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	glib-2.0.200:${PORTSDIR}/devel/glib20 \
		popt.0:${PORTSDIR}/devel/popt \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_X_PREFIX=	yes
USE_BISON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack \
		gnomeprefix
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
	gst-register.1 gst-xmllaunch.1

PKG_CONFIG?="${LOCALBASE}/bin/pkg-config"

# library minor number
SHLIB_VERSION=	0

post-install:
# register plugins
	@${PREFIX}/bin/gst-register 2>/dev/null

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/libdata/pkgconfig/libgnomeui-2.0.pc)
LIB_DEPENDS+=	gnomeui-2.200:${PORTSDIR}/x11-toolkits/libgnomeui
.endif

.include <bsd.port.post.mk>
