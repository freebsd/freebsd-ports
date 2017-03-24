# $FreeBSD$

PORTNAME=	minio
PORTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Amazon S3 compatible object storage server

LICENSE=	APACHE20

BUILD_DEPENDS=	go>=1.7:lang/go \
		bash:shells/bash

USES=		compiler gmake

USE_GITHUB=	yes
GH_TAGNAME=	RELEASE.2017-02-16T01-47-30Z
GH_SUBDIR=	src/github.com/${PORTNAME}/${PORTNAME}
GH_TUPLE=	\
		minio:mc:RELEASE.2017-02-06T20-16-19Z:mc/src/github.com/minio/mc \
		hashicorp:go-version:03c5bf6:go_version/src/github.com/hashicorp/go-version
MAKE_ENV=	GOPATH=${WRKSRC} GOROOT=${LOCALBASE}/go

PLIST_FILES=	bin/minio

USE_RC_SUBR=	minio

USERS=		minio
GROUPS=		minio

SUB_LIST=	USER="${USERS}" \
		GROUP="${GROUPS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
BUILD_ENV=  CC=clang
.endif

.include <bsd.port.post.mk>
