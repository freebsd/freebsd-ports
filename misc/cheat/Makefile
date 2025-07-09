PORTNAME=	cheat
DISTVERSION=	4.4.2
PORTREVISION=	12
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Create and view interactive cheatsheets on the command-line
WWW=		https://github.com/cheat/cheat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules
USE_GITHUB=	yes
GH_TUPLE=	\
		Microsoft:go-winio:v0.6.1:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:afb1ddc0824c:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		alecthomas:chroma:v2.12.0:alecthomas_chroma_v2/vendor/github.com/alecthomas/chroma/v2 \
		cloudflare:circl:v1.3.6:cloudflare_circl/vendor/github.com/cloudflare/circl \
		cyphar:filepath-securejoin:v0.2.4:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:v1.10.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		docopt:docopt.go:ee0de3bc6815:docopt_docopt_go/vendor/github.com/docopt/docopt-go \
		emirpasic:gods:v1.18.1:emirpasic_gods/vendor/github.com/emirpasic/gods \
		go-git:gcfg:3a3c6141e376:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.5.0:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.11.0:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.16.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mod:v0.14.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.19.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.15.0:golang_sys/vendor/golang.org/x/sys \
		golang:tools:v0.16.1:golang_tools/vendor/golang.org/x/tools \
		imdario:mergo:v1.0.0:imdario_mergo/vendor/dario.cat/mergo \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		kevinburke:ssh_config:v1.2.0:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		pjbgf:sha1cd:v0.3.0:pjbgf_sha1cd/vendor/github.com/pjbgf/sha1cd \
		sergi:go-diff:v1.3.1:sergi_go_diff/vendor/github.com/sergi/go-diff \
		skeema:knownhosts:v1.2.1:skeema_knownhosts/vendor/github.com/skeema/knownhosts \
		xanzy:ssh-agent:v0.3.3:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
