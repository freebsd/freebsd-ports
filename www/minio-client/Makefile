# $FreeBSD$

PORTNAME=	minio-client
PORTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
CATEGORIES=	www

MAINTAINER=	jhixson@gmail.com
COMMENT=	Replacement for ls, cp, mkdir, diff and rsync commands for filesystems

LICENSE=	APACHE20

BUILD_DEPENDS=	go>=1.7:lang/go \
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
GH_TAGNAME=	RELEASE.2017-12-12T01-08-02Z
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
MAKE_ENV=	GOPATH=${WRKSRC} GOROOT=${LOCALBASE}/go

PLIST_FILES=	bin/${MC}

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -v -x \
		-ldflags "-X main.GitDescribe=v${PORTVERSION}" -o bin/${MC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/bin/${MC} \
		${STAGEDIR}${PREFIX}/bin/${MC}

.include <bsd.port.mk>
