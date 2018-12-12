# $FreeBSD$

PORTNAME=	lidia
DISTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	https://www.math.ucdavis.edu/~latte/software/packages/lidia/current/
DISTNAME=	${PORTNAME}-${DISTVERSION}+latte-patches-2014-10-04

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for computational number theory

LICENSE=	LiDIA
LICENSE_NAME=	LiDIA License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake localbase:ldflags tar:bz2 libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --enable-shared --with-extra-libs=${LOCALBASE}/lib
USE_GCC=	any # doesn't build with clang, no active developers to fix this: https://github.com/mkoeppe/LiDIA/issues/6
USE_LDCONFIG=	yes

.include <bsd.port.mk>
