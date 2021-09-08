# Created by: Gabriel M. Dutra <0xdutra@gmail.com>

PORTNAME=	gokart
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	security

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Go Security Static Analysis

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	praetorian-inc

GH_TUPLE=	\
		fatih:color:v1.12.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:496545a6307b:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:mod:v0.4.2:golang_mod/vendor/golang.org/x/mod \
		golang:sys:977fb7262007:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.2:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		lithammer:dedent:v1.1.0:lithammer_dedent/vendor/github.com/lithammer/dedent \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		owenrumney:go-sarif:v1.0.11:owenrumney_go_sarif/vendor/github.com/owenrumney/go-sarif \
		segmentio:fasthash:v1.0.3:segmentio_fasthash/vendor/github.com/segmentio/fasthash \
		spf13:cobra:v1.2.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		zclconf:go-cty:v1.8.4:zclconf_go_cty/vendor/github.com/zclconf/go-cty

GO_TARGET=	gokart

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
