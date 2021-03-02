# $FreeBSD$

PORTNAME=	oneshot
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.1
CATEGORIES=	www

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	First-come-first-serve single-fire HTTP server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	raphaelreyna
GH_TUPLE=	cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:87dc89f01550:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:627f9648deb9:golang_net/vendor/golang.org/x/net \
		golang:sys:85ca7c5b95cd:golang_sys/vendor/golang.org/x/sys \
		gorilla:mux:v1.7.4:gorilla_mux/vendor/github.com/gorilla/mux \
		grandcat:zeroconf:v1.0.0:grandcat_zeroconf/vendor/github.com/grandcat/zeroconf \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jf-tech:iohelper:v1.0.2:jf_tech_iohelper/vendor/github.com/jf-tech/iohelper \
		miekg:dns:v1.1.27:miekg_dns/vendor/github.com/miekg/dns \
		raphaelreyna:ez-cgi:v0.7.3:raphaelreyna_ez_cgi/vendor/github.com/raphaelreyna/ez-cgi \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		spf13:cobra:v1.0.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag

_BUILD_VERSION=	${DISTVERSIONFULL}
_BUILD_DATE=	$$(date +%d-%B-%Y)

GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/cmd.version=${_BUILD_VERSION} \
		-X github.com/${GH_ACCOUNT}/${GH_PROJECT}/cmd.date=${_BUILD_DATE}"

PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_DESC=	Build and install auto-generated manpages

do-build-MANPAGES-on:
	cd ${GO_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} run ${GO_BUILDFLAGS} ./doc/man/main.go > ${PORTNAME}.1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${GO_WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${GO_WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
