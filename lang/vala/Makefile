# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vala
PORTVERSION=	0.28.1
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Programming language and compiler that converts Vala code into C code

LICENSE=	LGPL21

PORTSCOUT=	limitw:1,even

USES=		bison gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomeprefix libxslt
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

VALA_VER=	${PORTVERSION:R}
PLIST_SUB=	VERSION=${VALA_VER}

.include <bsd.port.mk>
