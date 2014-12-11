# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	xfburn
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	CD/DVD burning tool for Xfce

LICENSE=	GPLv2

LIB_DEPENDS=	libburn.so:${PORTSDIR}/devel/libburn \
		libisofs.so:${PORTSDIR}/devel/libisofs
RUN_DEPENDS=	cdrdao:${PORTSDIR}/sysutils/cdrdao

GNU_CONFIGURE=	yes
USE_GNOME=	intltool intlhack glib20 gtk20
USE_XFCE=	configenv libexo libmenu
USES=		pkgconfig gmake desktop-file-utils tar:bzip2
INSTALLS_ICONS=	yes

CONFIGURE_ARGS=--disable-gudev

OPTIONS_DEFINE=	GSTREAMER NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER=	yes
CONFIGURE_ARGS+=--enable-gstreamer
.else
CONFIGURE_ARGS+=--disable-gstreamer
.endif

.include <bsd.port.mk>
