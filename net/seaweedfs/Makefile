PORTNAME=	seaweedfs
DISTVERSION=	3.59
CATEGORIES=	net sysutils

MAINTAINER=	drtr0jan@yandex.ru
COMMENT=	Distributed Object Store and Filesystem
WWW=		https://github.com/seaweedfs/seaweedfs/wiki

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_RC_SUBR=	seaweedfs

GO_MODULE=	github.com/seaweedfs/seaweedfs@v0.0.0-20231113061208-27b34f37935f
GO_TARGET=	./weed
CGO_CFLAGS=	-I.

SEAWEEDFS_DIR?=		/var/db/${PORTNAME}
SEAWEEDFS_USER?=	seaweedfs
SEAWEEDFS_GROUP?=	seaweedfs

SUB_FILES=	pkg-message
SUB_LIST=	SEAWEEDFS_DIR=${SEAWEEDFS_DIR} \
		USER=${SEAWEEDFS_USER} \
		GROUP=${SEAWEEDFS_GROUP}

USERS=		${SEAWEEDFS_USER}
GROUPS=		${SEAWEEDFS_GROUP}

OPTIONS_DEFINE=		GOCDK RCLONE
OPTIONS_DEFAULT=	ELASTIC GOCDK RCLONE SQLITE
OPTIONS_GROUP=		FILERS
OPTIONS_GROUP_FILERS=	ELASTIC SQLITE TIKV YDB

ELASTIC_DESC=	Elasticsearch support
FILERS_DESC=	Filer store engines
GOCDK_DESC=	Go CDK PubSub API support
RCLONE_DESC=	rsync for cloud storage backend
TIKV_DESC=	TiKV database support
YDB_DESC=	YDB support

ELASTIC_VARS=	GO_TAGS+=elastic
GOCDK_VARS=	GO_TAGS+=gocdk
RCLONE_VARS=	GO_TAGS+=rclone
SQLITE_VARS=	GO_TAGS+=sqlite
TIKV_VARS=	GO_TAGS+=tikv
YDB_VARS=	GO_TAGS+=ydb

.include <bsd.port.pre.mk>
.if !empty (GO_TAGS)
GO_BUILDFLAGS+=	-tags "${GO_TAGS}"
.endif

post-build:
.for cfg in master filer security replication notification
	${WRKDIR}/bin/weed scaffold -config ${cfg} -output ${WRKDIR}/
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for cfg in filer master notification replication security
	${INSTALL_DATA} ${WRKDIR}/${cfg}.toml \
		${STAGEDIR}${ETCDIR}/${cfg}.toml.sample
.endfor

.include <bsd.port.post.mk>
