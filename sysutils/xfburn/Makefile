PORTNAME=	xfburn
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	XFCE/apps
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	CD/DVD burning tool for Xfce
WWW=		https://goodies.xfce.org/projects/applications/xfburn

LICENSE=	GPLv2

LIB_DEPENDS=	libburn.so:devel/libburn \
		libisofs.so:devel/libisofs \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	cdrdao:sysutils/cdrdao

USES=		compiler:c11 desktop-file-utils gettext-tools gmake gnome \
		pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 intltool
USE_XFCE=	libexo

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gudev

OPTIONS_DEFINE=			GSTREAMER NLS
OPTIONS_DEFAULT=		GSTREAMER
OPTIONS_SUB=			yes

GSTREAMER_USES=			gstreamer
GSTREAMER_CONFIGURE_ENABLE=	gstreamer
GSTREAMER_USE=			gstreamer=faac,flac,lame,vorbis,wavpack

NLS_CONFIGURE_ENABLE=		nls
NLS_USES=			gettext-runtime

.include <bsd.port.mk>
