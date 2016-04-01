# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cantarell-fonts
PORTVERSION=	0.0.24
CATEGORIES=	x11-fonts gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Cantarell, a Humanist sans-serif font family

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		fonts gmake gnome pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-configdir=${PREFIX}/etc/fonts/conf.avail
FONTSDIR=	share/fonts/cantarell
PLIST_SUB=	FONTSDIR=${FONTSDIR}

.include <bsd.port.mk>
