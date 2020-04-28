# $FreeBSD$

PORTNAME=	gotop
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.2
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal based graphical activity monitor inspired by gtop and vtop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	xxxserxxx # forked from cjbassi/gotop that was discontinued
GH_TUPLE=	\
		StackExchange:wmi:5d049714c4a6:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cjbassi:drawille-go:27dc511fe6fd:cjbassi_drawille_go/vendor/github.com/cjbassi/drawille-go \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		distatus:battery:v0.9.0:distatus_battery/vendor/github.com/distatus/battery \
		docopt:docopt.go:ee0de3bc6815:docopt_docopt_go/vendor/github.com/docopt/docopt.go \
		gizak:termui:v3.0.0:gizak_termui_v3/vendor/github.com/gizak/termui/v3 \
		go-ole:go-ole:v1.2.1:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-yaml:yaml:v2.2.5:go_yaml_yaml/vendor/gopkg.in/yaml \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:e047566fdf82:golang_sys/vendor/golang.org/x/sys \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		nsf:termbox-go:02980233997d:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.4.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.9.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.8:prometheus_procfs/vendor/github.com/prometheus/procfs \
		shirou:gopsutil:v2.18.11:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shirou:w32:bb4de0191aa4:shirou_w32/vendor/github.com/shirou/w32 \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify
GL_TUPLE=	https://gitlab.howett.net:go:plist:591f970eefbbeb04d7b37f334a0c4c3256e32876:go_plist/vendor/howett.net/plist

GO_TARGET=	./cmd/gotop/

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
