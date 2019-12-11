# $FreeBSD$

PORTNAME=	mesos
PORTVERSION=	1.9.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	APACHE/mesos/${PORTVERSION}
PKGNAMEPREFIX=	apache-

MAINTAINER=	james.wright@digital-chaos.com
COMMENT=	Cluster manager providing resource isolation and sharing

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

IGNORE_FreeBSD_11=	does not build

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		elfio>0:devel/elfio \
		http-parser>0:www/http-parser \
		leveldb>0:databases/leveldb \
		picojson>0:devel/picojson \
		protobuf>0:devel/protobuf \
		rapidjson>0:devel/rapidjson \
		libzookeeper>0:devel/libzookeeper
LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libcurl.so:ftp/curl \
		libgpr.so:devel/grpc \
		libglog.so:devel/glog \
		libhttp_parser.so:www/http-parser \
		libev.so:devel/libev \
		libleveldb.so:databases/leveldb \
		libprotobuf.so:devel/protobuf \
		libsasl2.so:security/cyrus-sasl2 \
		libsvn_delta-1.so:devel/subversion \
		libsvn_subr-1.so:devel/subversion \
		libzookeeper_mt.so:devel/libzookeeper

USES=		gmake libarchive libtool python:run shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	src/cli/mesos-cat \
		src/cli/mesos-ps \
		src/cli/mesos-scp \
		src/cli/mesos-tail

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-java \
		--disable-python \
		--disable-werror \
		--with-apr=${LOCALBASE} \
		--with-boost=${LOCALBASE} \
		--with-elfio=${LOCALBASE} \
		--with-glog=${LOCALBASE} \
		--with-grpc=${LOCALBASE} \
		--with-http_parser=${LOCALBASE} \
		--with-leveldb=${LOCALBASE} \
		--with-libarchive=${LOCALBASE} \
		--with-libev=${LOCALBASE} \
		--with-protobuf=${LOCALBASE} \
		--with-picojson=${LOCALBASE} \
		--with-rapidjson=${LOCALBASE} \
		--with-sasl=${LOCALBASE} \
		--with-svn=${LOCALBASE} \
		--with-zookeeper=${LOCALBASE}

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DEPLOY
OPTIONS_SUB=	yes

DEPLOY_DESC=	Install deploy scripts

.include <bsd.port.mk>
