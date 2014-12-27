# Created by: olgeni@FreeBSD.org
# $FreeBSD$

PORTNAME=	gtk-xfce-engine
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	x11-themes xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Xfce gtk theme engine

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	glib20 gtk20
USE_XFCE=	configenv	# to get MASTER_SITE_SUBDIR something has to be defined

CONFIGURE_ARGS+=--disable-glibtest \
	--enable-gtk2 \
	--disable-gtk3

.include <bsd.port.mk>
