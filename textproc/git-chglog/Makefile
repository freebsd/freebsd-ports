# $FreeBSD$

PORTNAME=	git-chglog
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.2
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	CHANGELOG generator implemented in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}
GH_TUPLE=	AlecAivazis:survey:v2.2.9:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		andygrunwald:go-jira:v1.13.0:andygrunwald_go_jira/vendor/github.com/andygrunwald/go-jira \
		cpuguy83:go-md2man:f79a8a8ca69d:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structs:v1.0.0:fatih_structs/vendor/github.com/fatih/structs \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:20be4c3c3ed5:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:d5e6a3e2c0ae:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		google:go-querystring:53e6ce116135:google_go_querystring/vendor/github.com/google/go-querystring \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		kyokomi:emoji:v2.2.8:kyokomi_emoji_v2/vendor/github.com/kyokomi/emoji/v2 \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		pkg:errors:v0.8.0:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		trivago:tgo:v1.0.1:trivago_tgo/vendor/github.com/trivago/tgo \
		tsuyoshiwada:go-gitcmd:5f1f5f9475df:tsuyoshiwada_go_gitcmd/vendor/github.com/tsuyoshiwada/go-gitcmd \
		urfave:cli:v2.3.0:urfave_cli_v2/vendor/github.com/urfave/cli/v2

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
