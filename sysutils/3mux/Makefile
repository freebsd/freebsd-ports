# $FreeBSD$

PORTNAME=	3mux
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
CATEGORIES=	sysutils

MAINTAINER=	vulcan@wired.sh
COMMENT=	Terminal multiplexer inspired by i3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	aaronjanse
GH_TUPLE=	creack:pty:v1.1.7:creack_pty/vendor/github.com/creack/pty \
		golang:crypto:056763e48d71:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:97732733099d:golang_sys/vendor/golang.org/x/sys \
		kr:pty:v1.1.8:kr_pty/vendor/github.com/kr/pty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		nsf:termbox-go:4d2b513ad8be:nsf_termbox_go/vendor/github.com/nsf/termbox-go

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
