# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdl
PORTVERSION=	3.18.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Components intended to be shared between GNOME development tools

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limitw:1,even

USE_GNOME=	gtk30 intlhack introspection:build
USES=		gettext gmake gnome libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
