# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net-im/folks/Makefile,v 1.29 2012/08/17 19:06:45 kwm Exp $

PORTNAME=	folks
PORTVERSION=	0.7.0
CATEGORIES=	net-im
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	library to aggregates people from multiple sources

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	gee:${PORTSDIR}/devel/libgee06 \
		telepathy-glib.0:${PORTSDIR}/net-im/telepathy-glib

IGNORE=		Doesn't build currently, missing components
CONFLICTS=	folks-0.4.[0-9]*

USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehier gnomehack intlhack ltverhack evolutiondataserver3
USES=		gettext
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	LIBVER=25 VERSION=33

#OPTIONS=	SOCIALWEB "Enable social web backend" on

#.include <bsd.port.options.mk>

#.if defined(WITH_SOCIALWEB)
#LIB_DEPENDS+=	socialweb.0:${PORTSDIR}/www/libsocialweb
#CONFIGURE_ARGS+=--enable-libsocialweb-backend=yes
#.else
CONFIGURE_ARGS+=--enable-libsocialweb-backend=no
#.endif

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|^build_old_libs=yes|build_old_libs=no|g' \
		${WRKDIR}/gnome-libtool

.include <bsd.port.mk>
