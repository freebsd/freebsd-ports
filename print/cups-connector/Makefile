# $FreeBSD$

PORTNAME=	cups-connector
PORTVERSION=	0.0.0.2016.03.09
CATEGORIES=	print

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Share CUPS printers via Google Cloud Print

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go \
		cups>=0:print/cups \
		avahi-app>=0:net/avahi-app

USES=		compiler pkgconfig
USE_GITHUB=	yes
GH_TUPLE=	google:cups-connector:1fdc26d:DEFAULT/src/github.com/google/cups-connector \
		codegangsta:cli:a294348:cli/src/github.com/codegangsta/cli \
		coreos:go-systemd:7b2428f:gosystemd/src/github.com/coreos/go-systemd \
		golang:oauth2:2cd4472:oauth2/src/golang.org/x/oauth2 \
		golang:net:6acef71:net/src/golang.org/x/net \
		mildred:go-xdg:875014b:xdg/src/launchpad.net/go-xdg/v0

BIN_FILES=	gcp-connector-util gcp-cups-connector
PLIST_FILES=	${BIN_FILES:S/^/bin\//}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CONTRIBUTING.md README.md

post-patch:
	@${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@g" \
		${WRKSRC}/cups/core.go ${WRKSRC}/privet/avahi.go

do-build:
.for bin in ${BIN_FILES}
	@cd ${WRKSRC}/src/github.com/google/cups-connector; ${SETENV} \
		${BUILD_ENV} GOPATH=${WRKSRC} go build -o \
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
