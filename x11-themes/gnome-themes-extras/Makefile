# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-themes/gnome-themes-extras/Makefile,v 1.18 2007/10/04 02:36:16 mezz Exp $

PORTNAME=	gnome-themes-extras
PORTVERSION=	2.22.0
PORTREVISION=	9
CATEGORIES=	x11-themes gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	More themes for the GNOME 2 desktop environment

BUILD_DEPENDS=	gtk-engines2>=2.11.0:x11-themes/gtk-engines2 \
		icon-naming-utils>=0.8.1:x11-themes/icon-naming-utils
RUN_DEPENDS=	gtk-engines2>=2.11.0:x11-themes/gtk-engines2

USES=		gettext gmake pkgconfig tar:bzip2
USE_GNOME=	libgnomeui intlhack
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
