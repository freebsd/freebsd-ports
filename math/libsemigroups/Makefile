PORTNAME=	libsemigroups
PORTVERSION=	3.0.3
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C++ library for semigroups and monoids
WWW=		https://libsemigroups.readthedocs.io/en/latest/

LICENSE=	GPLv3

BUILD_DEPENDS=	HPCombi>0:math/hpcombi
LIB_DEPENDS=	libfmt.so:devel/libfmt

USE_GITHUB=	yes

USES=		autoreconf compiler:c++11-lang eigen:3,build \
		libtool pathfix pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-external-fmt=yes	\
		--with-external-eigen	\
		--enable-hpcombi
LIBS=		-lm
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64
CONFIGURE_ARGS+=	--disable-hpcombi
.else
CONFIGURE_ARGS+=	--enable-hpcombi
.endif

.include <bsd.port.post.mk>
