# Created by: Gabriel M. Dutra <0xdutra@gmail.com>

PORTNAME=	ipinfo
DISTVERSIONPREFIX=	ipinfo-
DISTVERSION=	2.7.0
CATEGORIES=	net

MAINTAINER=	0xdutra@gmail.com
COMMENT=	Official Command Line Interface for the IPinfo API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	go:modules

USE_GITHUB=	yes
GH_PROJECT=	cli
GH_TUPLE=	\
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		etcd-io:bbolt:v1.3.6:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:496545a6307b:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:sync:09787c993a3a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:2c5d950f24ef:golang_sys/vendor/golang.org/x/sys \
		golang:term:2321bbc49cbf:golang_term/vendor/golang.org/x/term \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		ipinfo:go:v2.6.0:ipinfo_go_v2/vendor/github.com/ipinfo/go/v2 \
		jszwec:csvutil:v1.4.0:jszwec_csvutil/vendor/github.com/jszwec/csvutil \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pkg:browser:ce105d075bb4:pkg_browser/vendor/github.com/pkg/browser \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		posener:script:v1.1.5:posener_script/vendor/github.com/posener/script \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify

GO_TARGET=	./ipinfo

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
