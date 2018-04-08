# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloog
PORTVERSION=	0.19.0
CATEGORIES=	math

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Code generator in the polyhedral model

LICENSE=	LGPL21

LIB_DEPENDS=	libgmp.so:math/gmp \
		libisl.so:devel/isl

USES=		autoreconf gmake libtool

USE_GITHUB=	yes
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}
GH_ACCOUNT=	periscop

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=install-strip
CONFIGURE_ARGS+=	--with-gmp-prefix=${LOCALBASE} --with-isl-prefix=${LOCALBASE}
CONFIGURE_ENV=	pkgconfig_libdir=${PREFIX}/libdata/pkgconfig/ ac_cv_prog_TEXI2DVI=""

.include <bsd.port.mk>
