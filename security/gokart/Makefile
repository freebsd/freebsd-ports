# Created by: Gabriel M. Dutra <0xdutra@gmail.com>

PORTNAME=	gokart
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
CATEGORIES=	security

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Go Security Static Analysis

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	praetorian-inc

GH_TUPLE=	\
		Microsoft:go-winio:v0.4.16:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:04723f9f07d7:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		acomagu:bufpipe:v1.0.3:acomagu_bufpipe/vendor/github.com/acomagu/bufpipe \
		emirpasic:gods:v1.12.0:emirpasic_gods/vendor/github.com/emirpasic/gods \
		fatih:color:v1.12.0:fatih_color/vendor/github.com/fatih/color \
		go-git:gcfg:v1.5.0:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.3.1:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.4.2:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:83a5a9bb288b:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.4.2:golang_mod/vendor/golang.org/x/mod \
		golang:net:a5a99cb37ef4:golang_net/vendor/golang.org/x/net \
		golang:sys:977fb7262007:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.2:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		kevinburke:ssh_config:4977a11b4351:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		lithammer:dedent:v1.1.0:lithammer_dedent/vendor/github.com/lithammer/dedent \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		owenrumney:go-sarif:v1.0.11:owenrumney_go_sarif/vendor/github.com/owenrumney/go-sarif \
		segmentio:fasthash:v1.0.3:segmentio_fasthash/vendor/github.com/segmentio/fasthash \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		spf13:cobra:v1.2.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		xanzy:ssh-agent:v0.3.0:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		zclconf:go-cty:v1.8.4:zclconf_go_cty/vendor/github.com/zclconf/go-cty

GO_TARGET=	gokart

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
