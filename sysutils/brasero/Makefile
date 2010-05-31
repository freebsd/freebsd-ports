# New ports collection makefile for:	bonfire
# Date created:		2006-05-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/brasero/Makefile,v 1.71 2010/04/27 20:38:56 kwm Exp $

PORTNAME=	brasero
PORTVERSION=	2.30.1
PORTREVISION=	1
CATEGORIES=	sysutils audio multimedia gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CD/DVD mastering tool for the GNOME desktop

LIB_DEPENDS=	notify.1:${PORTSDIR}/devel/libnotify \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique \
		totem-plparser.17:${PORTSDIR}/multimedia/totem-pl-parser \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra
RUN_DEPENDS=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		cdrdao:${PORTSDIR}/sysutils/cdrdao

USE_GETTEXT=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	sm
USE_GNOME=	intlhack gnomeprefix gnomehack
USE_LDCONFIG=	yes
USE_GSTREAMER=	gconf core
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-inotify --with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_CAM_LIB_H=1" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		brasero.1
GCONF_SCHEMAS=	brasero.schemas

OPTIONS=	NAUTILUS "Enable Nautilus extension" on \
		LIBBURNIA "Enable libburnia plug-ins" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NAUTILUS)
USE_GNOME+=	nautilus2
CONFIGURE_ARGS+=--enable-nautilus
PLIST_SUB+=	NAUTILUS=""
.else
PLIST_SUB+=	NAUTILUS="@comment "
CONFIGURE_ARGS+=--enable-nautilus=no
.endif

.if defined(WITH_LIBBURNIA)
LIB_DEPENDS+=	burn.4:${PORTSDIR}/devel/libburn \
    		isofs.6:${PORTSDIR}/devel/libisofs
CONFIGURE_ARGS+=--enable-libburnia
PLIST_SUB+=	LIBBURNIA=""
.else
PLIST_SUB+=	LIBBURNIA="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    	${WRKSRC}/libbrasero-burn/burn-process.c

.include <bsd.port.post.mk>
