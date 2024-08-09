PORTNAME=	minio
PORTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
PORTREVISION=	1
CATEGORIES=	www
DIST_SUBDIR=	minio

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Amazon S3 compatible object storage server
WWW=		https://minio.io/

LICENSE=	AGPLv3

USES=		compiler cpe go:modules
GH_TAGNAME=	RELEASE.2024-01-01T16-36-33Z
USE_RC_SUBR=	${PORTNAME}

COMMIT_ID=	8f13c8c3bfee304e11a56076039f13e343937124

GO_MODULE=	github.com/minio/minio@v0.0.0-20231220010002-7a311a3b666a
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
