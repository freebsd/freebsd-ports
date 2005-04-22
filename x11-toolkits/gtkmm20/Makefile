# New ports collection makefile for:   gtkmm2
# Date created:        30 September 2002
# Whom:                Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gtkmm
PORTVERSION=	2.2.12
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.2 \
		gtkmm
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Gtk+, Pango, Atk, and Glib

LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_X_PREFIX=	yes
LATEST_LINK=	gtkmm2
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomehack lthack gtk20
CONFIGURE_ARGS=	--enable-static=yes \
		--with-sigc-prefix=${LOCALBASE}

.if defined(WITH_EXAMPLES)
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/tests//' \
		${WRKSRC}/Makefile.in
.if !defined(WITH_EXAMPLES)
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
