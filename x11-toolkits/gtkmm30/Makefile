# New ports collection makefile for:   gtkmm2
# Date created:        30 September 2002
# Whom:                Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	gtkmm
PORTVERSION=	2.2.12
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.2 \
		gtkmm
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Gtk+, Pango, Atk, and Glib

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
LATEST_LINK=	gtkmm2

.if !defined(REFERENCE_PORT)

PORTREVISION=	6

LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack lthack gtk20
CONFIGURE_ARGS=	--enable-static=yes \
		--with-sigc-prefix=${LOCALBASE}

post-patch:
.for d in docs examples tests
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/${d}//' ${WRKSRC}/Makefile.in
.endfor

.include <bsd.port.mk>

.endif
