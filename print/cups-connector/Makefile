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
GH_ACCOUNT=	google:DEFAULT codegangsta:cli coreos:gosystemd \
		golang:oauth2,net mildred:xdg
GH_PROJECT=	cli:cli go-systemd:gosystemd oauth2:oauth2 net:net \
		go-xdg:xdg
GH_TAGNAME=	1fdc26d:DEFAULT a294348:cli 7b2428f:gosystemd \
		2cd4472:oauth2 6acef71:net 875014b:xdg

BIN_FILES=	gcp-connector-util gcp-cups-connector
PLIST_FILES=	${BIN_FILES:S/^/bin\//}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	CONTRIBUTING.md README.md

post-patch:
	@${REINPLACE_CMD} -e "s@%%PREFIX%%@${PREFIX}@g" \
		${WRKSRC}/cups/core.go ${WRKSRC}/privet/avahi.go
	@${MKDIR} ${WRKSRC}/src/github.com/google/cups-connector
.for src in cdd cups gcp gcp-connector-util gcp-cups-connector \
	gcp-windows-connector lib log manager monitor privet winspool xmpp
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/google/cups-connector
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/codegangsta
	@${MKDIR} ${WRKSRC}/src/github.com/coreos
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MKDIR} ${WRKSRC}/src/launchpad.net/go-xdg
	@${MV} ${WRKSRC_cli} ${WRKSRC}/src/github.com/codegangsta/cli
	@${MV} ${WRKSRC_gosystemd} ${WRKSRC}/src/github.com/coreos/go-systemd
	@${MV} ${WRKSRC_oauth2} ${WRKSRC}/src/golang.org/x/oauth2
	@${MV} ${WRKSRC_net} ${WRKSRC}/src/golang.org/x/net
	@${MV} ${WRKSRC_xdg} ${WRKSRC}/src/launchpad.net/go-xdg/v0

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
