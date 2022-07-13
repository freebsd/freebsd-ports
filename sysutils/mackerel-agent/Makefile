PORTNAME=	mackerel-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.72.14
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Agent program to post your hosts' metrics to mackerel.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	mackerel_agent
USE_GITHUB=	yes

GH_ACCOUNT=	mackerelio
GH_TUPLE=	\
		BurntSushi:toml:v1.1.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Songmu:gocredits:v0.2.0:songmu_gocredits/vendor/github.com/Songmu/gocredits \
		Songmu:goxz:v0.8.2:songmu_goxz/vendor/github.com/Songmu/goxz \
		Songmu:prompter:v0.5.1:songmu_prompter/vendor/github.com/Songmu/prompter \
		Songmu:retry:v0.1.0:songmu_retry/vendor/github.com/Songmu/retry \
		Songmu:timeout:v0.4.0:songmu_timeout/vendor/github.com/Songmu/timeout \
		Songmu:wrapcommander:v0.1.0:songmu_wrapcommander/vendor/github.com/Songmu/wrapcommander \
		StackExchange:wmi:v1.2.1:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		andybalholm:brotli:v1.0.4:andybalholm_brotli/vendor/github.com/andybalholm/brotli \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dsnet:compress:f66993602bf5:dsnet_compress/vendor/github.com/dsnet/compress \
		go-ole:go-ole:v1.2.6:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-yaml:yaml:496545a6307b:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:lint:6edffad5e616:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.5.1:golang_mod/vendor/golang.org/x/mod \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:bc2c85ada10a:golang_sys/vendor/golang.org/x/sys \
		golang:term:065cf7ba2467:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.9:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		klauspost:compress:v1.14.2:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:pgzip:v1.2.5:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		mackerelio:go-osstat:v0.2.2:mackerelio_go_osstat/vendor/github.com/mackerelio/go-osstat \
		mackerelio:golib:v1.2.1:mackerelio_golib/vendor/github.com/mackerelio/golib \
		mackerelio:mackerel-client-go:v0.21.0:mackerelio_mackerel_client_go/vendor/github.com/mackerelio/mackerel-client-go \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:goveralls:v0.0.11:mattn_goveralls/vendor/github.com/mattn/goveralls \
		mholt:archiver:v3.5.1:mholt_archiver_v3/vendor/github.com/mholt/archiver/v3 \
		motemen:go-cli:9961a876eb5f:motemen_go_cli/vendor/github.com/motemen/go-cli \
		nwaples:rardecode:v1.1.2:nwaples_rardecode/vendor/github.com/nwaples/rardecode \
		pierrec:lz4:v4.1.13:pierrec_lz4_v4/vendor/github.com/pierrec/lz4/v4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		shirou:gopsutil:v3.21.11:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tklauser:go-sysconf:v0.3.9:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.4.0:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		ulikunitz:xz:v0.5.10:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		xi2:xz:48954b6210f8:xi2_xz/vendor/github.com/xi2/xz \
		yusufpapurcu:wmi:v1.2.2:yusufpapurcu_wmi/vendor/github.com/yusufpapurcu/wmi

post-patch:
	${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|" ${WRKSRC}/config/config_unix.go

post-stage:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/mackerel-agent.sample.conf ${STAGEDIR}${ETCDIR}
	${MV} ${STAGEDIR}${ETCDIR}/mackerel-agent.sample.conf \
		${STAGEDIR}${ETCDIR}/mackerel-agent.conf.sample

.include <bsd.port.mk>
