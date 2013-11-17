# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	xfburn
PORTVERSION=	0.4.3
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CD/DVD burning tool for Xfce

LIB_DEPENDS=	libburn.so:${PORTSDIR}/devel/libburn \
		libisofs.so:${PORTSDIR}/devel/libisofs
RUN_DEPENDS=	cdrdao:${PORTSDIR}/sysutils/cdrdao \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GMSGFMT=${PREFIX}/bin/msgfmt DATADIRNAME=share

USE_BZIP2=	yes
USE_GNOME=	intltool
USE_XFCE=	configenv libexo libgui
USES=		pkgconfig gmake
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DBUS HAL GSTREAMER NLS
OPTIONS_DEFAULT=	DBUS HAL
NLS_USE=	USES=gettext
MLS_CONFIGURE_ENABLE=	nls
DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
DBUS_ENABLE=	dbus
HAL_LIB_DEPENDS=	libhal.so:${PORTSDIR}/sysutils/hal
HAL_ENABLE=	hal

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER=	core
CONFIGURE_ARGS+=	"LDFLAGS=-lgstpbutils-0.10"
.else
CONFIGURE_ARGS+=	--disable-gstreamer
.endif

.include <bsd.port.mk>
