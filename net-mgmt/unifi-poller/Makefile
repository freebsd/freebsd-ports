# Created by: Anthony Brown <anthony@found-it.net>

PORTNAME=	unifi-poller
DISTVERSIONPREFIX=v
DISTVERSION=	2.1.3
CATEGORIES=	net-mgmt

MAINTAINER=	anthony@found-it.net
COMMENT=	Collect unifi controller data

LICENSE=	MIT

USES=		go:modules

USERS=	unifi-poller
GROUPS=	unifi-poller

USE_GITHUB=	yes
GH_ACCOUNT=	unifi-poller
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davidnewhall:md2roff:aeae646f49d23457ca0f701a381cfa5f1eefc4e7:davidnewhall_md2roff/vendor/github.com/davidnewhall/md2roff \
		russross:blackfriday:v2.1.0:russross_blackfriday/vendor/gopkg.in/russross/blackfriday.v2 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:4f45737414dc:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:e915ea6b2b7d:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:66c3f260301c:golang_sys/vendor/golang.org/x/sys \
		golang:term:72f3dc4e9b72:golang_term/vendor/golang.org/x/term \
		golift:cnfg:v0.0.7:golift_cnfg/vendor/golift.io/cnfg \
		golift:version:v0.0.2:golift_version/vendor/golift.io/version \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		influxdata:influxdb1-client:b269163b24ab:influxdata_influxdb1_client/vendor/github.com/influxdata/influxdb1-client \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		prometheus:client_golang:v1.10.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.20.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		spf13:pflag:85dd5c8bc61c:spf13_pflag/vendor/github.com/spf13/pflag \
		unifi-poller:influxunifi:d2de22bd896d:unifi_poller_influxunifi/vendor/github.com/unifi-poller/influxunifi \
		unifi-poller:inputunifi:7fd4a2cdb411:unifi_poller_inputunifi/vendor/github.com/unifi-poller/inputunifi \
		unifi-poller:lokiunifi:9e27b9fcffc5:unifi_poller_lokiunifi/vendor/github.com/unifi-poller/lokiunifi \
		unifi-poller:poller:efda34dd8222:unifi_poller_poller/vendor/github.com/unifi-poller/poller \
		unifi-poller:promunifi:f15144f260be:unifi_poller_promunifi/vendor/github.com/unifi-poller/promunifi \
		unifi-poller:unifi:v0.0.8:unifi_poller_unifi/vendor/github.com/unifi-poller/unifi \
		unifi-poller:webserver:b4db5feaea83:unifi_poller_webserver/vendor/github.com/unifi-poller/webserver

OPTIONS_DEFINE=	DOCS
.include <bsd.port.options.mk>

post-build:
	(cd ${GO_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} run github.com/davidnewhall/md2roff --manual="unifi-poller" --version="${DISTVERSION}" examples/MANUAL.md)
	@${REINPLACE_CMD} -e "s/{{BINARY}}/unifi-poller/g" -e "s/{{BINARYU}}/unifi_poller/g" -e "s/{{CONFIG_FILE}}/up.conf/g" \
			${GO_WRKSRC}/init/bsd/freebsd.rc.d

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/unifi-poller \
	${STAGEDIR}${PREFIX}/share/doc/unifi-poller \
	${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKDIR}/bin/unifi-poller ${STAGEDIR}${PREFIX}/bin/unifi-poller
	${INSTALL_SCRIPT} ${WRKSRC}/init/bsd/freebsd.rc.d ${STAGEDIR}${PREFIX}/etc/rc.d/unifi-poller
	${INSTALL_MAN} ${WRKSRC}/examples/up.conf.example ${STAGEDIR}${PREFIX}/etc/unifi-poller/up.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${GO_WRKSRC}/examples/MANUAL.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${GO_WRKSRC}/examples/MANUAL.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${GO_WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${GO_WRKSRC}/examples/up.conf.example ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${GO_WRKSRC}/examples/up.json.example ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${GO_WRKSRC}/examples/up.yaml.example ${STAGEDIR}${DOCSDIR}
.endif
	${INSTALL_MAN} ${GO_WRKSRC}/examples/MANUAL ${STAGEDIR}${MAN1PREFIX}/man/man1/unifi-poller.1

.include <bsd.port.mk>
