PORTNAME=	seaweedfs
DISTVERSION=	3.20
CATEGORIES=	net sysutils
MASTER_SITES=	https://raw.githubusercontent.com/${PORTNAME}/${PORTNAME}/${DISTVERSIONFULL}/:gomod
DISTFILES=	go.mod:gomod

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Distributed Object Store and Filesystem

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
USE_RC_SUBR=	seaweedfs

GO_MODULE=	github.com/seaweedfs/seaweedfs
GO_TARGET=	./weed
CGO_CFLAGS=	-I.

SEAWEEDFS_DIR?=		/var/db/${PORTNAME}
SEAWEEDFS_USER?=	seaweedfs
SEAWEEDFS_GROUP?=	seaweedfs

SUB_FILES=	pkg-message
SUB_LIST=	GROUP=${SEAWEEDFS_GROUP} \
		SEAWEEDFS_DIR=${SEAWEEDFS_DIR} \
		USER=${SEAWEEDFS_USER}

USERS=		${SEAWEEDFS_USER}
GROUPS=		${SEAWEEDFS_GROUP}

post-build:
.for cfg in master filer security replication notification
	${WRKDIR}/bin/weed scaffold -config ${cfg} -output ${WRKDIR}/
.endfor

post-install:
	${MKDIR} \
		${STAGEDIR}/var/db/${PORTNAME} \
		${STAGEDIR}/var/log/${PORTNAME} \
		${STAGEDIR}${ETCDIR}
.for cfg in filer master notification replication security
	${INSTALL_DATA} ${WRKDIR}/${cfg}.toml \
	    ${STAGEDIR}${ETCDIR}/${cfg}.toml.sample
.endfor

.include <bsd.port.mk>
