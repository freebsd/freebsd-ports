# $FreeBSD$

PORTNAME=	honeybadger
PORTVERSION=	0.0.0.2016022301
CATEGORIES=	security

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Quantum Insert detector and 0-day catcher

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_TUPLE=	david415:HoneyBadger:11dc0ca:DEFAULT/src/github.com/david415/HoneyBadger \
		google:gopacket:f361903:gp/src/github.com/google/gopacket \
		fatih:color:7a5857d:co/src/github.com/fatih/color \
		mattn:go-colorable:9fdad7c:gc/src/github.com/mattn/go-colorable \
		mattn:go-isatty:56b76bd:gi/src/github.com/mattn/go-isatty \
		golang:sys:50c6bc5:xs/src/golang.org/x/sys \
		golang:net:b6d7b13:xn/src/golang.org/x/net

BIN_FILES=	handshakeHijacker honeyBadger \
		honeybadgerReportTool honeybadgerReportToolColor sprayInjector

PLIST_FILES=	${BIN_FILES:S/^/bin\//}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.rst LICENSE LICENSE_BSD

LICENSE=	GPLv3

do-build:
.for bin in ${BIN_FILES}
	cd ${WRKSRC}/src/github.com/david415/HoneyBadger/cmd/${bin}; ${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build
.endfor

do-install:
.for bin in ${BIN_FILES}
	cd ${WRKSRC}/src/github.com/david415/HoneyBadger/cmd/${bin}; ${CP} ${bin} ${STAGEDIR}${PREFIX}/bin/${src}
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${CP} ${WRKSRC}/src/github.com/david415/HoneyBadger/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
