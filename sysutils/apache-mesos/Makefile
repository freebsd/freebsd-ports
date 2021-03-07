# $FreeBSD$

PORTNAME=	mesos
PORTVERSION=	1.10.0
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	APACHE/mesos/${PORTVERSION}:mesos
PKGNAMEPREFIX=	apache-
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:mesos
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

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

OPTIONS_DEFINE=	DEPLOY JAVA
OPTIONS_SUB=	yes

DEPLOY_DESC=	Install deploy scripts
JAVA_DESC=	Enable Java bindings

JAVA_CONFIGURE_ENABLE=	java
JAVA_USE=		java=yes
JAVA_BUILD_DEPENDS=	mvn:devel/maven
JAVA_FETCH_DEPENDS=	mvn:devel/maven
JAVA_CONFIGURE_ENV=	PROTOBUF_JAR="${MAVEN_REPO}/com/google/protobuf/protobuf-java/${PROTOBUF_VERSION}/protobuf-java-${PROTOBUF_VERSION}.jar"
JAVA_MAKE_ENV=		MAVEN_OPTS="${MAVEN_OPTS}"
JAVA_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src_java_mesos.pom.in

# REVIEW: Can we figure out the current Protobuf version in ports instead of hardcoding???
PROTOBUF_VERSION=	3.12.2

MAVEN_CMD=		mvn
MAVEN_REPO=		${WRKDIR}/mesos-maven-deps-${PORTVERSION}
MAVEN_OPTS=		-Dmaven.repo.local=${MAVEN_REPO}
MAVEN_ENV=		PROTOBUF_VERSION="${PROTOBUF_VERSION}" MAVEN_OPTS="${MAVEN_OPTS}"
MAVEN_POM=		${FILESDIR}/maven-deps.pom

DEV_BUILD_MODE=		no

.if (${DEV_BUILD_MODE} == "yes")
# Fetch Maven build dependencies upfront into local Maven Repo
# Needs to be after extract (as WRKDIR gets wiped) but before Configure
post-extract-JAVA-on:
	@${SETENV} ${MAVEN_ENV} \
	${MAVEN_CMD} -f ${MAVEN_POM} dependency:go-offline
.else
MASTER_SITES+=	https://github.com/Digital-Chaos/mesos-maven-deps/archive/${DISTVERSION}/:maven
DISTFILES+=	mesos-maven-deps-${DISTVERSION}${EXTRACT_SUFX}:maven
.endif

# Replace Protobuf version in src/java/mesos.pom.in
do-patch-JAVA-on:
	@${REINPLACE_CMD} -e 's|@PROTOBUF_VERSION@|${PROTOBUF_VERSION}|g' ${WRKSRC}/src/java/mesos.pom.in

.include <bsd.port.mk>
