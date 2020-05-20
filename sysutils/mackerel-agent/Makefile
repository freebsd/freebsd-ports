# $FreeBSD$

PORTNAME=	mackerel-agent
DISTVERSIONPREFIX=	v
DISTVERSION=	0.68.0
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
		Songmu:prompter:v0.3.0:songmu_prompter/vendor/github.com/Songmu/prompter \
		Songmu:retry:v0.1.0:songmu_retry/vendor/github.com/Songmu/retry \
		Songmu:timeout:v0.4.0:songmu_timeout/vendor/github.com/Songmu/timeout \
		Songmu:wrapcommander:v0.1.0:songmu_wrapcommander/vendor/github.com/Songmu/wrapcommander \
		StackExchange:wmi:cbe66965904d:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		golang:crypto:a0c6ece9d31a:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:d101bd2416d5:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		mackerelio:go-osstat:v0.1.0:mackerelio_go_osstat/vendor/github.com/mackerelio/go-osstat \
		mackerelio:golib:v1.0.0:mackerelio_golib/vendor/github.com/mackerelio/golib \
		mackerelio:mackerel-client-go:v0.9.1:mackerelio_mackerel_client_go/vendor/github.com/mackerelio/mackerel-client-go \
		mattn:go-encoding:v0.0.2:mattn_go_encoding/vendor/github.com/mattn/go-encoding \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		motemen:go-cli:9961a876eb5f:motemen_go_cli/vendor/github.com/motemen/go-cli \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		shirou:gopsutil:v2.20.4:shirou_gopsutil/vendor/github.com/shirou/gopsutil

post-patch:
	${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|" ${WRKSRC}/config/config_unix.go

post-stage:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/mackerel-agent.sample.conf ${STAGEDIR}${ETCDIR}
	${MV} ${STAGEDIR}${ETCDIR}/mackerel-agent.sample.conf \
		${STAGEDIR}${ETCDIR}/mackerel-agent.conf.sample

.include <bsd.port.mk>
