# $FreeBSD: head/www/minio/Makefile 437792 2017-04-05 15:12:19Z swills $

PORTNAME=	minio
PORTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
CATEGORIES=	www

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Amazon S3 compatible object storage server

LICENSE=	APACHE20

BUILD_DEPENDS=	go>=1.7:lang/go \
		bash:shells/bash

USES=		compiler

USE_GITHUB=	yes
GH_TAGNAME=	RELEASE.2017-09-29T19-16-56Z
GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}
GH_TUPLE=	minio:mc:RELEASE.2017-06-15T03-38-43Z:mc/src/github.com/minio/mc \
		hashicorp:go-version:03c5bf6:go_version/src/github.com/hashicorp/go-version
MAKE_ENV=	GOPATH=${WRKSRC} GOROOT=${LOCALBASE}/go

PLIST_FILES=	bin/minio

USE_RC_SUBR=	minio

USERS=		minio
GROUPS=		minio

SUB_LIST=	USER="${USERS}" \
		GROUP="${GROUPS}"

do-build:
	@cd ${WRKSRC}/src/github.com/minio/minio; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -v -x \
		-ldflags "-X main.GitDescribe=${DISTVERSIONFULL}" -o bin/minio

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
BUILD_ENV=  CC=clang
.endif

.include <bsd.port.post.mk>
