PORTNAME=	minio
DISTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
CATEGORIES=	www
DIST_SUBDIR=	minio

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Amazon S3 compatible object storage server
WWW=		https://minio.io/

LICENSE=	AGPLv3

USES=		compiler cpe go:1.21,modules
GH_TAGNAME=	RELEASE.2024-04-18T19-09-19Z
CPE_VERSION=	${GH_TAGNAME}
USE_RC_SUBR=	${PORTNAME}

COMMIT_ID=	98f7821eb3f60a6ece3125348a121a1238d02159

GO_MODULE=	github.com/minio/minio@v0.0.0-${DISTVERSION:S/.//g}-${COMMIT_ID:C/^(.{12}).*/\1/}
GO_BUILDFLAGS=	-ldflags=' \
		-X github.com/minio/minio/cmd.Version=${GH_TAGNAME:C/RELEASE\.//:C|(..)-(..)-(..)Z|\1:\2:\3Z|} \
		-X github.com/minio/minio/cmd.ReleaseTag=${GH_TAGNAME} \
		-X github.com/minio/minio/cmd.CommitID=${COMMIT_ID} \
		-X github.com/minio/minio/cmd.ShortCommitID=${COMMIT_ID:C|(............).*|\1|} \
		-X github.com/minio/minio/cmd.GOPATH=${WRKSRC} ${STRIP} -w'

SUB_LIST=	DBDIR=${MINIO_DBDIR} \
		GROUP="${GROUPS}" \
		USER="${USERS}"

USERS=		${MINIO_USER}
GROUPS=		${MINIO_GROUP}

PLIST_FILES=	bin/${PORTNAME}

MINIO_USER?=	${PORTNAME}
MINIO_GROUP?=	${PORTNAME}
MINIO_DBDIR?=	/var/db/${PORTNAME}

.include <bsd.port.mk>
