# Created by: Anthony Brown <anthony@found-it.ne >
# $FreeBSD$

PORTNAME=	unifi-poller
DISTVERSIONPREFIX=v
DISTVERSION=	2.0.1
CATEGORIES=	net-mgmt

MAINTAINER=	anthony@found-it.net
COMMENT=	Collect unifi controller data

LICENSE=	MIT

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	unifi-poller
GH_TUPLE=	BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		github:hub:v2.11.2:github_hub/vendor/github.com/github/hub \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:net:627f9648deb9:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:226ff32320da:golang_sys/vendor/golang.org/x/sys \
		golift:cnfg:v0.0.5:golift_cnfg/vendor/golift.io/cnfg \
		influxdata:influxdb1-client:02f0bf5dbca3:influxdata_influxdb1_client/vendor/github.com/influxdata/influxdb1-client \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.11:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.6.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.10.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.1.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.24.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		russross:blackfriday:v2.0.0:russross_blackfriday/vendor/github.com/russross/blackfriday \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		unifi-poller:influxunifi:v0.0.9:unifi_poller_influxunifi/vendor/github.com/unifi-poller/influxunifi \
		unifi-poller:inputunifi:v0.0.7:unifi_poller_inputunifi/vendor/github.com/unifi-poller/inputunifi \
		unifi-poller:poller:v0.0.7:unifi_poller_poller/vendor/github.com/unifi-poller/poller \
		unifi-poller:promunifi:v0.0.8:unifi_poller_promunifi/vendor/github.com/unifi-poller/promunifi \
		unifi-poller:unifi:v0.0.5:unifi_poller_unifi/vendor/github.com/unifi-poller/unifi

post-build:
	(cd ${GO_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} run github.com/github/hub/md2roff-bin --manual="unifi-poller" --version="${DISTVERSION}" examples/MANUAL.md)
	@${REINPLACE_CMD} -e "s/{{BINARY}}/unifi-poller/g" -e "s/{{BINARYU}}/unifi_poller/g" -e "s/{{CONFIG_FILE}}/up.conf/g" \
			${GO_WRKSRC}/init/bsd/freebsd.rc.d

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/unifi-poller \
	${STAGEDIR}${PREFIX}/share/doc/unifi-poller \
	${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKDIR}/bin/unifi-poller ${STAGEDIR}${PREFIX}/bin/unifi-poller
	${INSTALL_SCRIPT} ${WRKSRC}/init/bsd/freebsd.rc.d ${STAGEDIR}${PREFIX}/etc/rc.d/unifi-poller
	${INSTALL_DATA} ${WRKSRC}/examples/up.conf.example ${STAGEDIR}${PREFIX}/etc/unifi-poller/up.conf.sample
	${INSTALL_DATA} ${GO_WRKSRC}/LICENSE ${STAGEDIR}${PREFIX}/share/doc/unifi-poller/LICENSE
	${INSTALL_DATA} ${GO_WRKSRC}/examples/MANUAL.md ${STAGEDIR}${PREFIX}/share/doc/unifi-poller/
	${INSTALL_DATA} ${GO_WRKSRC}/examples/MANUAL.html ${STAGEDIR}${PREFIX}/share/doc/unifi-poller/
	${INSTALL_DATA} ${GO_WRKSRC}/README.md ${STAGEDIR}${PREFIX}/share/doc/unifi-poller/
	${INSTALL_DATA} ${GO_WRKSRC}/examples/up.conf.example ${STAGEDIR}${PREFIX}/share/doc/unifi-poller/up.conf.example
	${INSTALL_DATA} ${GO_WRKSRC}/examples/up.json.example ${STAGEDIR}${PREFIX}/share/doc/unifi-poller/up.json.example
	${INSTALL_DATA} ${GO_WRKSRC}/examples/up.xml.example ${STAGEDIR}${PREFIX}/share/doc/unifi-poller/up.xml.example
	${INSTALL_DATA} ${GO_WRKSRC}/examples/up.yaml.example ${STAGEDIR}${PREFIX}/share/doc/unifi-poller/up.yaml.example
	${INSTALL_MAN} ${GO_WRKSRC}/examples/MANUAL ${STAGEDIR}${MAN1PREFIX}/man/man1/unifi-poller.1

.include <bsd.port.mk>
