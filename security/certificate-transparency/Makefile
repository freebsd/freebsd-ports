# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	certificate-transparency
PORTVERSION=	20161015
PORTREVISION=	13
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open framework for monitoring and auditing SSL certificates

LICENSE=	APACHE20

LIB_DEPENDS?=	libevent.so:devel/libevent \
		libevhtp.so:www/libevhtp \
		libgtest.so:devel/googletest \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libgmock.so:devel/googlemock \
		libicuuc.so:devel/icu \
		libjson-c.so:devel/json-c \
		libleveldb.so:databases/leveldb \
		libobjecthash.so:devel/objecthash \
		libprotobuf.so:devel/protobuf \
		libsqlite3.so:databases/sqlite3 \
		libtcmalloc.so:devel/google-perftools

USES=		autoreconf compiler:c++11-lib gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	"CFLAGS+=-I${LOCALBASE}/include CXXFLAGS+=-lgtest CXXFLAGS+=-lgmock"
MAKE_FLAGS+=	"V=1"
USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	28478cb

CPPFLAGS+=	"-I${LOCALBASE}/include"
CPPFLAGS+=	"-I${LOCALBASE}/include/evhtp"
LDFLAGS+=	"-L${LOCALBASE}/lib"

.include <bsd.port.mk>
