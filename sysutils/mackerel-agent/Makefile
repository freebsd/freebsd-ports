# $FreeBSD$

PORTNAME=	mackerel-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.69.3
CATEGORIES=	sysutils

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Agent program to post your hosts' metrics to mackerel.io

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	mackerel_agent
USE_GITHUB=	yes

GH_ACCOUNT=	mackerelio
GH_PROJECT=	mackerel-agent
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Songmu:gocredits:v0.2.0:songmu_gocredits/vendor/github.com/Songmu/gocredits \
		Songmu:goxz:v0.6.0:songmu_goxz/vendor/github.com/Songmu/goxz \
		Songmu:prompter:v0.4.0:songmu_prompter/vendor/github.com/Songmu/prompter \
		Songmu:retry:v0.1.0:songmu_retry/vendor/github.com/Songmu/retry \
		Songmu:timeout:v0.4.0:songmu_timeout/vendor/github.com/Songmu/timeout \
		Songmu:wrapcommander:v0.1.0:songmu_wrapcommander/vendor/github.com/Songmu/wrapcommander \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		golang:crypto:a0c6ece9d31a:golang_crypto/vendor/golang.org/x/crypto \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:d101bd2416d5:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:tools:742c5eb664c2:golang_tools/vendor/golang.org/x/tools \
		mackerelio:go-osstat:v0.1.0:mackerelio_go_osstat/vendor/github.com/mackerelio/go-osstat \
		mackerelio:golib:v1.0.0:mackerelio_golib/vendor/github.com/mackerelio/golib \
		mackerelio:mackerel-client-go:v0.11.0:mackerelio_mackerel_client_go/vendor/github.com/mackerelio/mackerel-client-go \
		mattn:go-encoding:v0.0.2:mattn_go_encoding/vendor/github.com/mattn/go-encoding \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:goveralls:v0.0.7:mattn_goveralls/vendor/github.com/mattn/goveralls \
		mholt:archiver:v3.1.1:mholt_archiver/vendor/github.com/mholt/archiver \
		motemen:go-cli:9961a876eb5f:motemen_go_cli/vendor/github.com/motemen/go-cli \
		nwaples:rardecode:v1.0.0:nwaples_rardecode/vendor/github.com/nwaples/rardecode \
		pierrec:lz4:v2.4.0:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		shirou:gopsutil:v2.20.9:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		ulikunitz:xz:v0.5.6:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		xi2:xz:48954b6210f8:xi2_xz/vendor/github.com/xi2/xz

post-patch:
	${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|" ${WRKSRC}/config/config_unix.go

post-stage:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/mackerel-agent.sample.conf ${STAGEDIR}${ETCDIR}
	${MV} ${STAGEDIR}${ETCDIR}/mackerel-agent.sample.conf \
		${STAGEDIR}${ETCDIR}/mackerel-agent.conf.sample

.include <bsd.port.mk>
