# $FreeBSD$

PORTNAME=	honeybadger
PORTVERSION=	0.0.0.2016022301
CATEGORIES=	security

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Quantum Insert detector and 0-day catcher

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	david415:DEFAULT google:gp fatih:co mattn:gc,gi \
		golang:xs,xn
GH_PROJECT=	HoneyBadger:DEFAULT gopacket:gp color:co go-colorable:gc \
		go-isatty:gi net:xn sys:xs
GH_TAGNAME=	11dc0ca:DEFAULT f361903:gp 7a5857d:co 9fdad7c:gc 56b76bd:gi \
		b6d7b13:xn 50c6bc5:xs

BIN_FILES=	handshakeHijacker honeyBadger \
		honeybadgerReportTool honeybadgerReportToolColor sprayInjector

PLIST_FILES=	${BIN_FILES:S/^/bin\//}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.rst LICENSE LICENSE_BSD

LICENSE=	GPLv3

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/david415/HoneyBadger
.for src in .travis.yml LICENSE LICENSE_BSD README.rst attack blocks cmd \
	connection.go connection_test.go dispatcher.go dispatcher_test.go \
	drivers logging ordered_coalesce.go ordered_coalesce_test.go \
	pcap_integration_test.go retrospective.go retrospective_test.go \
	sniffer.go supervisor.go types
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/david415/HoneyBadger
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/google
	@${MKDIR} ${WRKSRC}/src/github.com/fatih
	@${MKDIR} ${WRKSRC}/src/github.com/mattn
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MV} ${WRKSRC_gp} \
		${WRKSRC}/src/github.com/google/gopacket
	@${MV} ${WRKSRC_co} \
		${WRKSRC}/src/github.com/fatih/color
	@${MV} ${WRKSRC_gc} \
		${WRKSRC}/src/github.com/mattn/go-colorable
	@${MV} ${WRKSRC_gi} \
		${WRKSRC}/src/github.com/mattn/go-isatty
	@${MV} ${WRKSRC_xn} \
		${WRKSRC}/src/golang.org/x/net
	@${MV} ${WRKSRC_xs} \
		${WRKSRC}/src/golang.org/x/sys

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
