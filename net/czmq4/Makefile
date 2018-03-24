# $FreeBSD$

PORTNAME=	czmq
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.1
CATEGORIES=	net
PKGNAMESUFFIX=	4

MAINTAINER=	kenji@k2r.org
COMMENT=	High-level C Binding for ZeroMQ (Version 4)

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		xmlto:textproc/xmlto
LIB_DEPENDS=	libzmq.so:net/libzmq4

USES=		autoreconf libtool pkgconfig shebangfix
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	zeromq
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

SHEBANG_FILES=	doc/mkman mkdoc \
		model/chkopts.pl \
		model/rename_class

CONFLICTS_INSTALL=	czmq-3.*

# uuid_CFLAGS and uuid_LIBS required
# to avoid conflicts with misc/e2fsprogs-libuuid
CONFIGURE_ARGS=	uuid_CFLAGS="-I/usr/include ${CFLAGS}" \
		uuid_LIBS="-lc" \
		--with-libzmq=${LOCALBASE} \
		--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig \
		--enable-drafts="yes" \
		--with-docs="yes"

MAKE_ENV=	V=1
CPPFLAGS+=	-Wno-error

.include <bsd.port.mk>
