# New ports collection makefile for:	gstreamer
# Date created:		Tue Jul 9 20:24:02 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.4.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	glib-2.0.0:${PORTSDIR}/devel/glib20 \
		popt.0:${PORTSDIR}/devel/popt \
		xml2.5:${PORTSDIR}/textproc/libxml2

IGNORE=		Needs help fixing scheduling code under FreeBSD

USE_BISON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --disable-tests \
		--disable-failing-tests
CONFIGURE_ENV=	PKG_CONFIG=${PKG_CONFIG} \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
CONFIGURE_TARGET=
INSTALLS_SHLIB=	yes

MAN1=	gst-complete.1 gst-compprep.1 gst-inspect.1 gst-launch.1 \
	gst-feedback.1 gst-md5sum.1 \
	gst-register.1 gst-xmllaunch.1

PKG_CONFIG?="${LOCALBASE}/bin/pkg-config"

post-patch:
# use proper dir
	@${REINPLACE_CMD} -E -e \
		's|^(pkgconfigdir).*$$|\1=${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
# remove version number from include dir name
	@${FIND} ${WRKSRC} -type f -name Makefile.in | \
		${XARGS} -n 10 ${REINPLACE_CMD} -E \
		's|^(lib[[:alpha:]]+includedir.+)-@VERSION@|\1|'
# remove version number from include dir name AND
# help dependent ports find popt.h
	@${REINPLACE_CMD} -E -e \
		's|-@VERSION@||; \
		s|(-I\$${includedir})|\1 -I${LOCALBASE}/include|' \
		${WRKSRC}/gstreamer.pc.in
# XXX - remove in release 0.4.1 since this is fixed in CVS
	@${REINPLACE_CMD} -e 's|MAP_ANONYMOUS|MAP_ANON|' \
		${WRKSRC}/gst/cothreads.c

post-configure:
# remove version number postfix from library names
	@${REINPLACE_CMD} -E -e 's|-release ${PORTVERSION}||' \
		${WRKSRC}/gst/Makefile

post-install:
# register plugins
	@${PREFIX}/bin/gst-register 2>/dev/null

.include <bsd.port.mk>
