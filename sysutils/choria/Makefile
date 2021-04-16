PORTNAME=	choria
PORTVERSION=	0.21.0
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Server to host Choria agents, networks, federations and discovery

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	choria-io
GH_PROJECT=	go-choria
USE_RC_SUBR=	choria-broker choria-server

GH_TUPLE=	\
		AlecAivazis:survey:v2.2.9:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Freman:eventloghook:e4d803b6b48b:freman_eventloghook/vendor/github.com/Freman/eventloghook \
		Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v1.5.0:masterminds_semver/vendor/github.com/Masterminds/semver \
		Masterminds:sprig:v2.22.0:masterminds_sprig/vendor/github.com/Masterminds/sprig \
		OneOfOne:xxhash:v1.2.8:oneofone_xxhash/vendor/github.com/OneOfOne/xxhash \
		achanda:go-sysctl:6be7678c45d2:achanda_go_sysctl/vendor/github.com/achanda/go-sysctl \
		aelsabbahy:GOnetstat:edf89f784e08:aelsabbahy_gonetstat/vendor/github.com/aelsabbahy/GOnetstat \
		aelsabbahy:go-ps:61c449472dcf:aelsabbahy_go_ps/vendor/github.com/aelsabbahy/go-ps \
		aelsabbahy:goss:v0.3.16:aelsabbahy_goss/vendor/github.com/aelsabbahy/goss \
		alecthomas:kingpin:v2.2.6:alecthomas_kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b899a751:alecthomas_template/vendor/github.com/alecthomas/template \
		alecthomas:units:f65c72e2690d:alecthomas_units/vendor/github.com/alecthomas/units \
		antonmedv:expr:v1.8.9:antonmedv_expr/vendor/github.com/antonmedv/expr \
		awesome-gocui:gocui:v0.6.0:awesome_gocui_gocui/vendor/github.com/awesome-gocui/gocui \
		awesome-gocui:termbox-go:c0aef3d18bcc:awesome_gocui_termbox_go/vendor/github.com/awesome-gocui/termbox-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		brutella:dnssd:v1.2.0:brutella_dnssd/vendor/github.com/brutella/dnssd \
		brutella:hc:v1.2.4:brutella_hc/vendor/github.com/brutella/hc \
		bytecodealliance:wasmtime-go:v0.24.0:bytecodealliance_wasmtime_go/vendor/github.com/bytecodealliance/wasmtime-go \
		census-instrumentation:opencensus-go:v0.22.2:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		choria-io:provisioning-agent:ac3a9cf4a41b:choria_io_provisioning_agent/vendor/github.com/choria-io/provisioning-agent \
		cloudevents:sdk-go:v1.2.0:cloudevents_sdk_go/vendor/github.com/cloudevents/sdk-go \
		dgrijalva:jwt-go:dc14462fd587:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dominikh:go-tools:v0.0.1-2019.2.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-errors:errors:v1.0.1:go_errors_errors/vendor/github.com/go-errors/errors \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gofrs:uuid:v4.0.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:e6e6c4f2bb5b:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:869f871628b6:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:83fdc39ff7b5:golang_lint/vendor/golang.org/x/lint \
		golang:mock:v1.5.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:e18ecbb05110:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:1e4c9ba3b0c4:golang_sys/vendor/golang.org/x/sys \
		golang:term:de623e64d2a6:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:time:89c76fbcd5d1:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.5:google_go_cmp/vendor/github.com/google/go-cmp \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		gosuri:uilive:v0.0.3:gosuri_uilive/vendor/github.com/gosuri/uilive \
		gosuri:uiprogress:v0.0.1:gosuri_uiprogress/vendor/github.com/gosuri/uiprogress \
		guptarohit:asciigraph:v0.5.1:guptarohit_asciigraph/vendor/github.com/guptarohit/asciigraph \
		huandu:xstrings:v1.3.0:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v0.3.8:imdario_mergo/vendor/github.com/imdario/mergo \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.11.12:klauspost_compress/vendor/github.com/klauspost/compress \
		lightstep:tracecontext.go:1757c391b1ac:lightstep_tracecontext_go/vendor/github.com/lightstep/tracecontext.go \
		looplab:fsm:v0.2.0:looplab_fsm/vendor/github.com/looplab/fsm \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		miekg:dns:v1.1.35:miekg_dns/vendor/github.com/miekg/dns \
		miekg:pkcs11:v1.0.3:miekg_pkcs11/vendor/github.com/miekg/pkcs11 \
		minio:highwayhash:v1.0.1:minio_highwayhash/vendor/github.com/minio/highwayhash \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:mapstructure:v1.4.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.0:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		moby:moby:v1.13.1:moby_moby/vendor/github.com/docker/docker \
		nats-io:jsm.go:b64af1ad7f66:nats_io_jsm_go/vendor/github.com/nats-io/jsm.go \
		nats-io:jwt:v2.0.1:nats_io_jwt_v2/vendor/github.com/nats-io/jwt \
		nats-io:nats-server:c8d812d805cc:nats_io_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		nats-io:nats.go:18aff2894af3:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.3.0:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		nats-io:stan.go:v0.8.3:nats_io_stan_go/vendor/github.com/nats-io/stan.go \
		nxadm:tail:v1.4.8:nxadm_tail/vendor/github.com/nxadm/tail \
		oleiade:reflections:0e86b3c98b2f:oleiade_reflections/vendor/github.com/oleiade/reflections \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		onsi:ginkgo:v1.15.2:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.11.0:onsi_gomega/vendor/github.com/onsi/gomega \
		open-policy-agent:opa:v0.27.1:open_policy_agent_opa/vendor/github.com/open-policy-agent/opa \
		opencontainers:runc:8779fa57eb4a:opencontainers_runc/vendor/github.com/opencontainers/runc \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.10.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.18.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.24.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:10cdbea86bc0:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		robfig:cron:v1.2.0:robfig_cron/vendor/github.com/robfig/cron \
		rsc:goversion:v1.2.0:rsc_goversion/vendor/rsc.io/goversion \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		tadglines:go-pkgs:1f86682992f1:tadglines_go_pkgs/vendor/github.com/tadglines/go-pkgs \
		tidwall:gjson:v1.7.1:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.0.3:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.1.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.3.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:tools:2cfd321de3ee:uber_go_tools/vendor/go.uber.org/tools \
		uber-go:zap:v1.13.0:uber_go_zap/vendor/go.uber.org/zap \
		xeipuuv:gojsonpointer:02993c407bfb:xeipuuv_gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
		xeipuuv:gojsonreference:bd5ef7bd5415:xeipuuv_gojsonreference/vendor/github.com/xeipuuv/gojsonreference \
		xeipuuv:gojsonschema:v1.2.0:xeipuuv_gojsonschema/vendor/github.com/xeipuuv/gojsonschema \
		xiam:to:8328998fc0ed:xiam_to/vendor/github.com/xiam/to \
		yashtewari:glob-intersection:5c77d914dd0b:yashtewari_glob_intersection/vendor/github.com/yashtewari/glob-intersection

x-post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/nats-io/jwt/v2
	@${RLN} ${WRKSRC_nats_io_jwt_v2}/v2 ${WRKSRC}/vendor/github.com/nats-io/jwt/v2

# Missing dependency
GH_TUPLE+=	choria-io:go-updater:v0.0.3:choria_io_go_updater/vendor/github.com/choria-io/go-updater \
		fatih:structtag:v1.2.0:fatih_structtag/vendor/github.com/fatih/structtag

post-patch:
	${REINPLACE_CMD} -e 's/{{cpkg_name}}/choria-broker/' \
		${WRKSRC}/packager/templates/debian/global/broker.conf
	${REINPLACE_CMD} -e 's/{{cpkg_name}}/choria-server/' \
		${WRKSRC}/packager/templates/debian/global/server.conf

pre-build:
	(cd ${GO_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} generate ${GO_BUILDFLAGS})

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/choria
	${INSTALL_DATA} ${WRKSRC}/packager/templates/debian/global/broker.conf ${STAGEDIR}${PREFIX}/etc/choria/broker.conf.sample
	${INSTALL_DATA} ${WRKSRC}/packager/templates/debian/global/server.conf ${STAGEDIR}${PREFIX}/etc/choria/server.conf.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/share/choria
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${STAGEDIR}${PREFIX}/bin/choria completion --zsh > ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_choria
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${STAGEDIR}${PREFIX}/bin/choria completion --bash > ${STAGEDIR}${PREFIX}/etc/bash_completion.d/choria

.include <bsd.port.mk>
