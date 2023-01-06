PORTNAME=	hcloud
DISTVERSIONPREFIX=	v
DISTVERSION=	1.31.1
CATEGORIES=	sysutils

MAINTAINER=	uzsolt@uzsolt.hu
COMMENT=	Official Hetzner Cloud command-line interface
WWW=		https://github.com/hetznercloud/cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	hetznercloud
GH_PROJECT=	cli

GH_TUPLE=	\
		VividCortex:ewma:v1.1.1:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		boumenot:gocover-cobertura:v1.2.0:boumenot_gocover_cobertura/vendor/github.com/boumenot/gocover-cobertura \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheggaaa:pb:v3.1.0:cheggaaa_pb_v3/vendor/github.com/cheggaaa/pb \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:630584e8d5aa:golang_crypto/vendor/golang.org/x/crypto \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.7.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.2.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.2.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.2.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.4.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.3.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:04be3eba64a2:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.7:google_go_cmp/vendor/github.com/google/go-cmp \
		guptarohit:asciigraph:v0.5.5:guptarohit_asciigraph/vendor/github.com/guptarohit/asciigraph \
		hetznercloud:hcloud-go:v1.37.0:hetznercloud_hcloud_go/vendor/github.com/hetznercloud/hcloud-go \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.12:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		pelletier:go-toml:v2.0.6:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.26.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0-rc.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rjeczalik:interfaces:v0.3.0:rjeczalik_interfaces/vendor/github.com/rjeczalik/interfaces \
		spf13:cobra:v1.5.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.8.1:stretchr_testify/vendor/github.com/stretchr/testify

GO_TARGET=	./cmd/hcloud

PLIST_FILES=	bin/hcloud

.include <bsd.port.mk>
