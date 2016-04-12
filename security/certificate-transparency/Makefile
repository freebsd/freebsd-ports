# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	certificate-transparency
PORTVERSION=	20160102
CATEGORIES=	security

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Open framework for monitoring and auditing SSL certificates

LICENSE=	APACHE20

LIB_DEPENDS?=	libevent.so:devel/libevent2 \
		libevhtp.so:www/libevhtp \
		libgtest.so:devel/googletest \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libgmock.so:devel/googlemock \
		libjson-c.so:devel/json-c \
		libleveldb.so:databases/leveldb \
		libobjecthash.so:devel/objecthash \
		libprotobuf.so:devel/protobuf \
		libsqlite3.so:databases/sqlite3 \
		libtcmalloc.so:devel/google-perftools

BROKEN_FreeBSD_9=	does not build on FreeBSD < 10.x

USES=		autoreconf compiler:c++11-lib gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	"CFLAGS+=-I${LOCALBASE}/include CXXFLAGS+=-lgtest CXXFLAGS+=-lgmock"
MAKE_FLAGS+=	"V=1"
USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	certificate-transparency
GH_TAGNAME=	1cdd6b5

CPPFLAGS+=	"-I${LOCALBASE}/include"
CPPFLAGS+=	"-I${LOCALBASE}/include/evhtp"
LDFLAGS+=	"-L${LOCALBASE}/lib"

.include <bsd.port.mk>
