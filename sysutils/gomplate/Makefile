# $FreeBSD$

PORTNAME=	gomplate
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
CATEGORIES=	sysutils

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Command-line tool for rendering templates before executing binaries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	hairyhenderson
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}
GH_TAG_COMMIT=	ce4b3e3

PLIST_FILES=	bin/gomplate

post-extract:
	@${CP} -RpP ${WRKSRC}/vendor/* ${WRKSRC}/src/

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} \
	${LOCALBASE}/bin/go build \
		-ldflags "-w -s -X github.com/${GH_ACCOUNT}/${PORTNAME}/version.GitCommit=${GH_TAG_COMMIT} -X github.com/${GH_ACCOUNT}/${PORTNAME}/version.Version=${DISTVERSION}" \
		-o ${PORTNAME} \
		./cmd/gomplate

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
