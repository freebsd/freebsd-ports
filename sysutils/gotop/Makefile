# $FreeBSD$

PORTNAME=	gotop
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.0
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal based graphical activity monitor inspired by gtop and vtop

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	xxxserxxx # forked from cjbassi/gotop that was discontinued
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		VictoriaMetrics:metrics:v1.11.2:victoriametrics_metrics/vendor/github.com/VictoriaMetrics/metrics \
		VividCortex:ewma:v1.1.1:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		cloudfoundry-attic:jibber_jabber:bcc4c8345a21:cloudfoundry_attic_jibber_jabber/vendor/github.com/cloudfoundry-attic/jibber_jabber \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		distatus:battery:v0.9.0:distatus_battery/vendor/github.com/distatus/battery \
		gizak:termui:v3.1.0:gizak_termui_v3/vendor/github.com/gizak/termui \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:sys:a7d97aace0b0:golang_sys/vendor/golang.org/x/sys \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-wordwrap:ad45545899c7:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		nsf:termbox-go:38ba6e5628f1:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		shibukawa:configdir:e180dbdc8da0:shibukawa_configdir/vendor/github.com/shibukawa/configdir \
		shirou:gopsutil:v2.20.3:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shurcooL:httpfs:8d4bc4ba7749:shurcool_httpfs/vendor/github.com/shurcooL/httpfs \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
 		valyala:fastrand:v1.0.0:valyala_fastrand/vendor/github.com/valyala/fastrand \
 		valyala:histogram:v1.0.1:valyala_histogram/vendor/github.com/valyala/histogram \
		xxxserxxx:lingo:5858cf2e409d:xxxserxxx_lingo/vendor/github.com/jdkeke142/lingo-toml \
 		xxxserxxx:opflag:v1.0.5:xxxserxxx_opflag/vendor/github.com/xxxserxxx/opflag
GL_TUPLE=	https://gitlab.howett.net:go:plist:3b63eb3a43b59c776909681ed1fcb412b47d3c9a:go_plist/vendor/howett.net/plist

GO_TARGET=	./cmd/gotop/

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
