# $FreeBSD$

PORTNAME=	cloud-print-connector
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	print

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Share CUPS printers via Google Cloud Print

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go

LIB_DEPENDS=	libcups.so:print/cups \
		libavahi-client.so:net/avahi-app \
		libavahi-common.so:net/avahi-app

USES=		compiler pkgconfig
USE_GITHUB=	yes
USE_RC_SUBR=	gcp-cups-connectord
GH_TUPLE=	google:cloud-print-connector:7d5f127:DEFAULT/src/github.com/google/cloud-print-connector \
		urfave:cli:8e01ec4:cli/src/github.com/urfave/cli \
		satori:go.uuid:36e9d2e:gouuid/src/github.com/satori/go.uuid \
		coreos:go-systemd:88bfeed:gosystemd/src/github.com/coreos/go-systemd \
		golang:oauth2:ef14785:oauth2/src/golang.org/x/oauth2 \
		golang:net:039a425:net/src/golang.org/x/net \
		mildred:go-xdg:96b70c9:xdg/src/launchpad.net/go-xdg/v0

BIN_FILES=	gcp-connector-util gcp-cups-connector
PLIST_FILES=	${BIN_FILES:S/^/bin\//}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CONTRIBUTING.md README.md

do-build:
.for bin in ${BIN_FILES}
	@cd ${WRKSRC}/src/github.com/google/cloud-print-connector; ${SETENV} \
		${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -o \
		${WRKSRC}/bin/${bin} ./${bin}
.endfor

do-install:
.for bin in ${BIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${bin} \
		${STAGEDIR}${PREFIX}/bin/${bin}
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${CP} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.pre.mk>

# golang assumes that if clang is in use, it is called "clang" and not "cc". If
# it's called "cc", go may fail
.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
