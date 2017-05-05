# $FreeBSD$

PORTNAME=	minio
PORTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
CATEGORIES=	www

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Amazon S3 compatible object storage server

LICENSE=	APACHE20

BUILD_DEPENDS=	go>=1.7:lang/go

USES=		compiler

USE_GITHUB=	yes
GH_TAGNAME=	RELEASE.2017-05-05T01-14-51Z
GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}
COMMIT_ID=	40985cc4e3eec06b7ea82dc34c8d907fd2e7aa12

PLIST_FILES=	bin/minio

USE_RC_SUBR=	minio

USERS=		minio
GROUPS=		minio

SUB_LIST=	USER="${USERS}" \
		GROUP="${GROUPS}"

do-build:
	cd ${WRKSRC}/${GH_SUBDIR} ; GOPATH=${WRKSRC} go build --ldflags '-X github.com/minio/minio/cmd.Version=${GH_TAGNAME:C/RELEASE\.//:C|(..)-(..)-(..)Z|\1:\2:\3Z|} -X github.com/minio/minio/cmd.ReleaseTag=${GH_TAGNAME} -X github.com/minio/minio/cmd.CommitID=${COMMIT_ID} -X github.com/minio/minio/cmd.GOPATH=${WRKSRC} -s -w' -o ${WRKSRC}/bin/minio

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
BUILD_ENV=  CC=clang
.endif

.include <bsd.port.post.mk>
