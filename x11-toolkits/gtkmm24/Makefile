# New ports collection makefile for:   gtkmm2
# Date created:        30 September 2002
# Whom:                Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/gtkmm24/Makefile,v 1.8 2005/10/20 16:16:50 marcus Exp $
#

PORTNAME=	gtkmm
PORTVERSION=	2.8.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for Gtk+, Pango, Atk

USE_BZIP2=	yes
PREFIX?=	${X11BASE}
LATEST_LINK=	gtkmm24

.if !defined(REFERENCE_PORT)

PORTREVISION=	1

LIB_DEPENDS=	glibmm-2.4.1:${PORTSDIR}/devel/glibmm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_XLIB=	yes
USE_GMAKE=	yes
USE_GCC=	3.4
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack gtk20
CONFIGURE_ARGS=	--disable-demos \
		--disable-docs \
		--disable-examples \
		--enable-static=yes \
		--with-sigc-prefix=${LOCALBASE}

PLIST_SUB=	VERSION="2.4" API_VERSION="2.4"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/tests//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
