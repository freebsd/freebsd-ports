# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	xfburn
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	CD/DVD burning tool for Xfce

LICENSE=	GPLv2

LIB_DEPENDS=	libburn.so:${PORTSDIR}/devel/libburn \
		libisofs.so:${PORTSDIR}/devel/libisofs
RUN_DEPENDS=	cdrdao:${PORTSDIR}/sysutils/cdrdao

GNU_CONFIGURE=	yes
USE_GNOME=	intltool intlhack glib20 gtk20
USE_XFCE=	libexo
USES=		pkgconfig gmake desktop-file-utils gettext-tools xfce tar:bzip2
INSTALLS_ICONS=	yes

CONFIGURE_ARGS=--disable-gudev

OPTIONS_DEFINE=	GSTREAMER NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
GSTREAMER_USE=	gstreamer=yes
GSTREAMER_CONFIGURE_ENABLE=	gstreamer

.include <bsd.port.mk>
