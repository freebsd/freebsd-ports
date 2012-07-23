# New ports collection makefile for:	xfburn
# Date created:		2008 November 06
# Whom:			J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	xfburn
PORTVERSION=	0.4.3
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CD/DVD burning tool for Xfce

BUILD_DEPENDS=	pkg-config>0:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	burn.4:${PORTSDIR}/devel/libburn \
		isofs.6:${PORTSDIR}/devel/libisofs
RUN_DEPENDS=	cdrdao:${PORTSDIR}/sysutils/cdrdao

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GMSGFMT=${PREFIX}/bin/msgfmt DATADIRNAME=share

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool
USE_XFCE=	configenv libexo libgui
USE_CDRTOOLS=	yes
INSTALLS_ICONS=	yes

MAN1=		xfburn.1

OPTIONS_DEFINE=	DBUS HAL GSTREAMER NLS
OPTIONS_DEFAULT=	DBUS HAL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if ${PORT_OPTIONS:MHAL}
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.else
CONFIGURE_ARGS+=	--disable-hal
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER=	core
CONFIGURE_ARGS+=	"LDFLAGS=-lgstpbutils-0.10"
.else
CONFIGURE_ARGS+=	--disable-gstreamer
.endif

.include <bsd.port.mk>
