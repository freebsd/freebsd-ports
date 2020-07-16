# $FreeBSD$

PORTNAME=	cheat
DISTVERSION=	4.0.2
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Create and view interactive cheatsheets on the command-line

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules
USE_GITHUB=	yes
GH_TUPLE=	\
		alecthomas:chroma:v0.7.3:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		docopt:docopt.go:ee0de3bc6815:docopt_docopt_go/vendor/github.com/docopt/docopt.go \
		go-check:check:8fa46927fb4f:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:9f9df34309c0:go_yaml_yaml/vendor/gopkg.in/yaml.v1 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml_1/vendor/gopkg.in/yaml.v2 \
		golang:sys:669c56c373c4:golang_sys/vendor/golang.org/x/sys \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		niemeyer:pretty:a10e7caefd8e:niemeyer_pretty/vendor/github.com/niemeyer/pretty \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
