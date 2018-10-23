# $FreeBSD$

PORTNAME=	minio-client
PORTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
CATEGORIES=	www

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Replacement for ls, cp, mkdir, diff and rsync commands for filesystems

LICENSE=	APACHE20

BUILD_DEPENDS=	go>=1.9.4:lang/go \
		bash:shells/bash

OPTIONS_DEFINE=	MC

MC_DESC=	Install as mc

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMC}
MC=	mc
.else
MC=	${PORTNAME}
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	minio
GH_PROJECT=	mc
GH_TAGNAME=	RELEASE.2018-10-18T00-40-05Z
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
MAKE_ENV=	GOPATH=${WRKSRC} GOROOT=${LOCALBASE}/go
COMMIT_ID=	0dd32c1b26f05e7f94f76f2ceb62b5229836b009

PLIST_FILES=	bin/${MC}

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}; \
	${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} CGO_ENABLED=0 go build -v -x \
		--ldflags '-X github.com/minio/mc/cmd.Version=${GH_TAGNAME:C/RELEASE\.//:C|(..)-(..)-(..)Z|\1:\2:\3Z|} -X github.com/minio/mc/cmd.ReleaseTag=${GH_TAGNAME} -X github.com/minio/mc/cmd.CommitID=${COMMIT_ID} -X github.com/minio/mc/cmd.GOPATH=${WRKSRC} -s -w' -o ${WRKSRC}/bin/${MC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/bin/${MC} \
		${STAGEDIR}${PREFIX}/bin/${MC}

.include <bsd.port.mk>
