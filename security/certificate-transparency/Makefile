# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	certificate-transparency
PORTVERSION=	20151025
CATEGORIES=	security

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Open framework for monitoring and auditing SSL certificates

LICENSE=	APACHE20

LIB_DEPENDS?=	libevent.so:${PORTSDIR}/devel/libevent2 \
		libevhtp.so:${PORTSDIR}/www/libevhtp \
		libgtest.so:${PORTSDIR}/devel/googletest \
		libgflags.so:${PORTSDIR}/devel/gflags \
		libglog.so:${PORTSDIR}/devel/glog \
		libgmock.so:${PORTSDIR}/devel/googlemock \
		libjson-c.so:${PORTSDIR}/devel/json-c \
		libleveldb.so:${PORTSDIR}/databases/leveldb \
		libprotobuf.so:${PORTSDIR}/devel/protobuf \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libtcmalloc.so:${PORTSDIR}/devel/google-perftools

BROKEN_FreeBSD_9=	does not build on FreeBSD < 10.x

USES=		autoreconf compiler:c++11-lib gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	"CFLAGS+=-I${LOCALBASE}/include CXXFLAGS+=-lgtest CXXFLAGS+=-lgmock"
MAKE_FLAGS+=	"V=1"
USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	certificate-transparency
GH_TAGNAME=	7e1cf3b

CPPFLAGS+=	"-I${LOCALBASE}/include"
CPPFLAGS+=	"-I${LOCALBASE}/include/evhtp"
LDFLAGS+=	"-L${LOCALBASE}/lib"

.include <bsd.port.mk>
