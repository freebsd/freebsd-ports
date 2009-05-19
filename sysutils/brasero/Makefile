# New ports collection makefile for:	bonfire
# Date created:		2006-05-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports-stable/sysutils/brasero/Makefile,v 1.1 2009/04/16 02:11:50 kwm Exp $

PORTNAME=	brasero
PORTVERSION=	2.26.2
CATEGORIES=	sysutils audio multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD/DVD mastering tool for the GNOME desktop

LIB_DEPENDS=	notify.1:${PORTSDIR}/devel/libnotify \
		totem-plparser.12:${PORTSDIR}/multimedia/totem-pl-parser
RUN_DEPENDS=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
    		cdrdao:${PORTSDIR}/sysutils/cdrdao

USE_GETTEXT=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	sm
USE_GNOME=	intlhack gnomeprefix gnomehack nautilus2
USE_GSTREAMER=	gconf core
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-inotify --with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_CAM_LIB_H=1" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		brasero.1
GCONF_SCHEMAS=	brasero.schemas

OPTIONS=	LIBBURNIA "Enable libburnia plug-ins" off

.include <bsd.port.pre.mk>

.if defined(WITH_LIBBURNIA)
LIB_DEPENDS+=	burn.4:${PORTSDIR}/devel/libburn \
    		isofs.6:${PORTSDIR}/devel/libisofs
CONFIGURE_ARGS+=--enable-libburnia
PLIST_SUB+=	LIBBURNIA=""
.else
PLIST_SUB+=	LIBBURNIA="@comment "
.endif

.include <bsd.port.post.mk>
