# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11-toolkits/gdl3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gdl
PORTVERSION=	3.6.2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Components intended to be shared between GNOME development tools

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XZ=		yes
USE_GNOME=	gnomeprefix gtk30 intltool
USES=		gettext gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdl-3.so.5

.include <bsd.port.mk>
