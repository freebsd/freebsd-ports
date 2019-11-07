# Created by: ade, archie
# $FreeBSD$

PORTNAME=	caja
PORTVERSION=	1.22.1
PORTREVISION=	1
CATEGORIES=	x11-fm mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	File manager for the MATE desktop

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libexempi.so:textproc/exempi \
		libstartup-notification-1.so:x11/startup-notification \
		libnotify.so:devel/libnotify

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gmake gnome libtool \
		localbase mate pathfix pkgconfig shared-mime-info tar:xz xorg
USE_MATE=	desktop icontheme:run
USE_XORG=	ice sm x11
USE_GNOME=	cairo gtk30 gnomeprefix intltool introspection:build libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-packagekit
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.caja.gschema.xml \
		org.mate.media-handling.gschema.xml

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/caja/extensions-2.0

.include <bsd.port.mk>
