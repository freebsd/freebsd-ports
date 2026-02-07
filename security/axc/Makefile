PORTNAME=	axc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.7
CATEGORIES=	security net

PATCH_SITES=	https://github.com/gkdr/axc/commit/
PATCHFILES=	c287e25143fc54486c8a8a86f9abb64ce1753372.patch:-p1 \
		ba53eb408f793652495d7d73775c33487e6cc8d0.patch:-p1

MAINTAINER=	michael.a.oshin@panafricanssi.org
COMMENT=	Crypto interfaces for libsignal-protocol-c
WWW=		https://github.com/gkdr/axc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libsignal-protocol-c.so:net/libsignal-protocol-c

USES=		cmake gnome localbase:ldflags pathfix pkgconfig sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	gkdr
USE_GNOME=	glib20
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	TEST

TEST_BUILD_DEPENDS=	cmocka>=1.1.5:sysutils/cmocka
TEST_CMAKE_BOOL=	AXC_WITH_TESTS
TEST_TEST_TARGET=	test

.include <bsd.port.mk>
