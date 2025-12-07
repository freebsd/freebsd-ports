PORTNAME=	minio
DISTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
PORTREVISION=	3
CATEGORIES=	www
DIST_SUBDIR=	minio

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Amazon S3 compatible object storage server
WWW=		https://minio.io/

LICENSE=	AGPLv3

DEPRECATED=	Upstream unmaintained
EXPIRATION_DATE=	2026-12-31

USES=		compiler cpe go:modules
GH_TAGNAME=	RELEASE.2025-10-15T17-29-55Z
CPE_VERSION=	${GH_TAGNAME}
USE_RC_SUBR=	${PORTNAME}

COMMIT_ID=	9e49d5e7a648f00e26f2246f4dc28e6b07f8c84a

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
