PORTNAME=	libsemigroups
PORTVERSION=	3.6.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C++ library for semigroups and monoids
WWW=		https://libsemigroups.readthedocs.io/en/latest/

LICENSE=	GPLv3

BUILD_DEPENDS=	eigen5>0:math/eigen5
LIB_DEPENDS=	libfmt.so:devel/libfmt
RUN_DEPENDS=	eigen5>0:math/eigen5
TEST_DEPENDS=	eigen5>0:math/eigen5

USE_GITHUB=	yes

USES=		autoreconf compiler:c++17-lang libtool pathfix pkgconfig

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
PLIST_SUB+=	HPCOMBI="@comment "
.else
BUILD_DEPENDS+=	HPCombi>0:math/hpcombi
CONFIGURE_ARGS+=	--enable-hpcombi
PLIST_SUB+=	HPCOMBI=""
.endif

# The GitHub tarball has neither .VERSION nor git metadata, so configure would
# call the library 3.dev and the pkg-config file would fail version checks.
post-extract:
	${ECHO_CMD} v${PORTVERSION} > ${WRKSRC}/.VERSION

.include <bsd.port.post.mk>
