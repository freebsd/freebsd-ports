# $FreeBSD$

PORTNAME=	git-chglog
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	textproc

MAINTAINER=	vulcan@wired.sh
COMMENT=	CHANGELOG generator implemented in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_TUPLE=	AlecAivazis:survey:v1.8.8:alecaivazis_survey/vendor/gopkg.in/AlecAivazis/survey.v1 \
		cpuguy83:go-md2man:f79a8a8ca69d:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:sys:d5e6a3e2c0ae:golang_sys/vendor/golang.org/x/sys \
		imdario:mergo:v0.3.11:imdario_mergo/vendor/github.com/imdario/mergo \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		kyokomi:emoji:v1.5.1:kyokomi_emoji/vendor/gopkg.in/kyokomi/emoji.v1 \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tsuyoshiwada:go-gitcmd:5f1f5f9475df:tsuyoshiwada_go_gitcmd/vendor/github.com/tsuyoshiwada/go-gitcmd \
		urfave:cli:v1.22.5:urfave_cli/vendor/github.com/urfave/cli

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md CONTRIBUTING.md README.md
_EXAMPLES=	.chglog/CHANGELOG.tpl.md .chglog/config.yml
PORTEXAMPLES=	${_EXAMPLES:T}

OPTIONS_DEFINE=	DOCS EXAMPLES
EXAMPLES_DESC=	Install example template format and configuration

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${_EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
