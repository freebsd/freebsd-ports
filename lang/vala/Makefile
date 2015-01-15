# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vala
PORTVERSION=	0.26.2
CATEGORIES=	lang gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Programming language and compiler that converts Vala code into C code

LICENSE=	LGPL21

USES=		bison gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomeprefix libxslt
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

VALA_VER=	${PORTVERSION:R}

PLIST_SUB=	VERSION=${VALA_VER}

post-install:
	${LN} -fs ${PREFIX}/libdata/pkgconfig/libvala-${VALA_VER}.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/vala-1.0.pc

.include <bsd.port.mk>
