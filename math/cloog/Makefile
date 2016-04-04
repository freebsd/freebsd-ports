# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloog
PORTVERSION=	0.18.4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.bastoul.net/cloog/pages/download/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Code generator in the polyhedral model

LICENSE=	LGPL21

LIB_DEPENDS=	libgmp.so:math/gmp \
		libisl.so:devel/isl

USE_LDCONFIG=	yes
USES=		libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-gmp-prefix=${LOCALBASE} --with-isl-prefix=${LOCALBASE}
CONFIGURE_ENV=	pkgconfig_libdir=${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
