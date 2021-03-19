# $FreeBSD$

PORTNAME=	3mux
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Terminal multiplexer inspired by i3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	aaronjanse
GH_TUPLE=	BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		BurntSushi:xdg:e80d3446fea1:burntsushi_xdg/vendor/github.com/BurntSushi/xdg \
		aaronjanse:pty:v1.1.14:aaronjanse_pty/vendor/github.com/aaronjanse/pty \
		golang:crypto:06a226fb4e37:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:059865788121:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		kardianos:osext:2bc1f35cddc0:kardianos_osext/vendor/github.com/kardianos/osext \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		npat-efault:poller:v2.0.0:npat_efault_poller/vendor/github.com/npat-efault/poller \
		nu7hatch:gouuid:179d4d0c4d8d:nu7hatch_gouuid/vendor/github.com/nu7hatch/gouuid \
		sevlyar:go-daemon:v0.1.5:sevlyar_go_daemon/vendor/github.com/sevlyar/go-daemon

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
