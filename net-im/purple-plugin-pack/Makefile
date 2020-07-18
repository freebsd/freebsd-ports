# $FreeBSD$

PORTNAME=	purple-plugin-pack
PORTVERSION=	g2020071701
CATEGORIES=	net-im
MASTER_SITES=	https://keep.imfreedom.org/pidgin/purple-plugin-pack/archive/
DISTNAME=	default
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Collection of libpurple plugins

BUILD_DEPENDS=	pidgin>0:net-im/pidgin
RUN_DEPENDS=	pidgin>0:net-im/pidgin
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib \
		libpurple.so:net-im/libpurple

USES=		gettext meson pkgconfig

WRKSRC=		${WRKDIR}/${PORTNAME}-default

.include <bsd.port.mk>
