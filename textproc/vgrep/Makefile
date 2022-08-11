PORTNAME=	vgrep
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.0
PORTREVISION=	4
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	User-friendly pager for grep

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	vrothberg
GH_TUPLE=	golang:sys:dee7805ff2e1:golang_sys/vendor/golang.org/x/sys \
		golang:term:6886f2dfbf5b:golang_term/vendor/golang.org/x/term \
		jessevdk:go-flags:v1.5.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-shellwords:v1.0.12:mattn_go_shellwords/vendor/github.com/mattn/go-shellwords \
		modern-go:concurrent:e0a39a4cb421:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		nightlyone:lockfile:v1.0.0:nightlyone_lockfile/vendor/github.com/nightlyone/lockfile \
		peterh:liner:v1.2.2:peterh_liner/vendor/github.com/peterh/liner \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus

_BUILD_VERSION=	${DISTVERSION}-6fb7acc

GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.version=${_BUILD_VERSION}"

PORTSCOUT=	skipv:16.09,16.09.1
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
