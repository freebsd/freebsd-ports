# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/x11-toolkits/gdl/Makefile 19335 2014-03-25 19:25:32Z kwm $

PORTNAME=	gdl
PORTVERSION=	3.12.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Components intended to be shared between GNOME development tools

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	gnomeprefix gtk30 intltool
USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdl-3.so.*

post-patch:
	@${REINPLACE_CMD} '/^test_dock_LDADD =/s/$$/ $$(GDL_DEPENDENCIES_LIBS)/' \
		${WRKSRC}/gdl/Makefile.in

.include <bsd.port.mk>
