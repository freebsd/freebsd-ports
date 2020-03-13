# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	certificate-transparency
PORTVERSION=	20161015
PORTREVISION=	43
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open framework for monitoring and auditing SSL certificates

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent \
		libevhtp.so:www/libevhtp \
		libgtest.so:devel/googletest \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libgmock.so:devel/googletest \
		libicuuc.so:devel/icu \
		libjson-c.so:devel/json-c \
		libleveldb.so:databases/leveldb \
		libobjecthash.so:devel/objecthash \
		libprotobuf.so:devel/protobuf \
		libsqlite3.so:databases/sqlite3 \
		libtcmalloc.so:devel/google-perftools \
		libsnappy.so:archivers/snappy

USES=		autoreconf compiler:c++11-lib gmake localbase:ldflags pkgconfig ssl

GNU_CONFIGURE=	yes
MAKE_FLAGS+=	"V=1"
USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	28478cb

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	could not find the OpenSSL libraries
BROKEN_FreeBSD_13=	could not find the OpenSSL libraries
.endif

.include <bsd.port.post.mk>
