# New ports collection makefile for:	gnomecontrolcenter2
# Date created:				04 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-control-center/Makefile,v 1.189 2009/03/18 00:23:38 kwm Exp $
#

PORTNAME=	gnome-control-center
PORTVERSION=	2.26.0
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for GNOME 2 project

LIB_DEPENDS=	canberra-gtk.0:${PORTSDIR}/audio/libcanberra
BUILD_DEPENDS=	${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon
RUN_DEPENDS=	gnome-eject:${PORTSDIR}/sysutils/gnome-mount \
		${LOCALBASE}/libexec/gnome-settings-daemon:${PORTSDIR}/sysutils/gnome-settings-daemon

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNOME_DESKTOP_VERSION=2
USE_GSTREAMER=	good
WANT_GNOME=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack metacity nautilus2 \
		gnomemenus desktopfileutils libgnomekbd gnomepanel
USE_XORG=	xscrnsaver
GNU_CONFIGURE=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-gstreamer=0.10
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	control-center.schemas fontilus.schemas

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mevolutiondataserver}!=""
USE_GNOME+=	evolutiondataserver
CONFIGURE_ARGS+=--enable-aboutme
PLIST_SUB+=	ABOUTME=""
.else
CONFIGURE_ARGS+=--disable-aboutme
PLIST_SUB+=	ABOUTME="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    	${WRKSRC}/capplets/common/gnome-theme-info.c

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
