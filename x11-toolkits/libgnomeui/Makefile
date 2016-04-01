# Created by: Joe Marcus Clarke <marcus@FreBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/libgnomeui/Makefile,v 1.129 2010/09/27 20:16:41 kwm Exp $

PORTNAME=	libgnomeui
PORTVERSION=	2.24.4
PORTREVISION?=	5
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libraries for the GNOME GUI, a GNU desktop environment

USES=		tar:bzip2

.if !defined(REFERENCE_PORT)

LIB_DEPENDS+=	libgnome-keyring.so:security/libgnome-keyring \
		libstartup-notification-1.so:x11/startup-notification
RUN_DEPENDS=	${LOCALBASE}/share/icons/gnome/index.theme:misc/gnome-icon-theme

USES+=		bison gettext gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	gnomeprefix intltool libbonoboui referencehack gvfs
USE_XORG=	sm
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

.endif
