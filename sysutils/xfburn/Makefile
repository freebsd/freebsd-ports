# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	xfburn
PORTVERSION=	0.5.5
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	CD/DVD burning tool for Xfce

LICENSE=	GPLv2

LIB_DEPENDS=	libburn.so:devel/libburn \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libisofs.so:devel/libisofs
RUN_DEPENDS=	cdrdao:sysutils/cdrdao \
		${LOCALBASE}/include/libburn/libburn.h:devel/libburn \
		${LOCALBASE}/include/libisofs/libisofs.h:devel/libisofs

USES=		compiler:c11 desktop-file-utils gettext-tools gmake gnome \
		pkgconfig tar:bzip2 xfce:gtk2
USE_GNOME=	cairo glib20 gtk20 intltool
USE_XFCE=	libexo

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-gudev

OPTIONS_DEFINE=			GSTREAMER NLS
OPTIONS_DEFAULT=		GSTREAMER
OPTIONS_SUB=			yes

GSTREAMER_CONFIGURE_ENABLE=	gstreamer
GSTREAMER_USE=			gstreamer1=yes,faac,flac,lame,vorbis,wavpack

NLS_CONFIGURE_ENABLE=		nls
NLS_USES=			gettext-runtime

post-patch:
	${REINPLACE_CMD} -e 's|media-cdrom|media-optical|g' \
		${WRKSRC}/desktop-integration/thunar-sendto-xfburn.desktop.in \
		${WRKSRC}/xfburn.desktop.in

.include <bsd.port.mk>
