# New ports collection makefile for:	gstreamer player
# Date created:		Fri Jul 12 06:02:42 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.4.0
CATEGORIES=	multimedia audio gnome
MASTER_SITES=	http://gstreamer.net/releases/0.4.0/src/
PKGNAMESUFFIX=	-player
DISTNAME=	gst-player-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	glib-2.0.0:${PORTSDIR}/devel/glib20 \
		gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui \
		gstreamer.0:${PORTSDIR}/multimedia/gstreamer \
		gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20 \
		popt.0:${PORTSDIR}/devel/popt \
		xml2.5:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	gst-visualise:${PORTSDIR}/multimedia/gstreamer-plugins

IGNORE=		Incompatible with latest gstreamer libraries

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME} \
		--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG}
INSTALLS_SHLIB=	yes

PKG_CONFIG?="${LOCALBASE}/bin/pkg-config"

post-patch:
# remove version number from include dir name
	@${FIND} ${WRKSRC} -type f -name Makefile.in | \
		${XARGS} -n 10 ${REINPLACE_CMD} -E \
		's|^(lib[[:alpha:]]+includedir.+)-@VERSION@|\1|'

.include <bsd.port.mk>
