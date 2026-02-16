PORTNAME=	cheat
DISTVERSION=	5.0.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Create and view interactive cheatsheets on the command-line
WWW=		https://github.com/cheat/cheat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:1.26,modules
USE_GITHUB=	yes
GH_TUPLE=	\
		Microsoft:go-winio:v0.6.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:v1.3.0:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		alecthomas:chroma:v2.23.1:alecthomas_chroma_v2/vendor/github.com/alecthomas/chroma/v2 \
		cloudflare:circl:v1.6.3:cloudflare_circl/vendor/github.com/cloudflare/circl \
		cyphar:filepath-securejoin:v0.6.1:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:v1.11.5:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		emirpasic:gods:v1.18.1:emirpasic_gods/vendor/github.com/emirpasic/gods \
		go-git:gcfg:3a3c6141e376:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.7.0:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.16.5:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.48.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:2c02b8208cf8:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:v0.50.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.41.0:golang_sys/vendor/golang.org/x/sys \
		imdario:mergo:v1.0.2:imdario_mergo/vendor/dario.cat/mergo \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		kevinburke:ssh_config:v1.5.0:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		klauspost:cpuid:v2.3.0:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		pjbgf:sha1cd:v0.5.0:pjbgf_sha1cd/vendor/github.com/pjbgf/sha1cd \
		sergi:go-diff:v1.4.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		skeema:knownhosts:v1.3.2:skeema_knownhosts/vendor/github.com/skeema/knownhosts \
		spf13:cobra:v1.10.2:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.9:spf13_pflag/vendor/github.com/spf13/pflag \
		xanzy:ssh-agent:v0.3.3:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

# the upstream refused to use a proper Golang module name, see https://github.com/cheat/cheat/issues/652#issuecomment-3905496176

.include <bsd.port.mk>
