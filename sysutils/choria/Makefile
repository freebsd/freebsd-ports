PORTNAME=	choria
PORTVERSION=	0.29.4
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Server to host Choria agents, networks, federations and discovery
WWW=		https://choria.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules

USE_GITHUB=	yes
GH_ACCOUNT=	choria-io
GH_PROJECT=	go-choria
USE_RC_SUBR=	choria-broker choria-server

GH_TUPLE=	\
		AlecAivazis:survey:v2.3.7:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		Freman:eventloghook:e4d803b6b48b:freman_eventloghook/vendor/github.com/Freman/eventloghook \
		HdrHistogram:hdrhistogram-go:v1.1.2:hdrhistogram_hdrhistogram_go/vendor/github.com/HdrHistogram/hdrhistogram-go \
		Masterminds:goutils:v1.1.1:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v1.5.0:masterminds_semver/vendor/github.com/Masterminds/semver \
		Masterminds:semver:v3.3.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.3.0:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		OneOfOne:xxhash:v1.2.8:oneofone_xxhash/vendor/github.com/OneOfOne/xxhash \
		achanda:go-sysctl:6be7678c45d2:achanda_go_sysctl/vendor/github.com/achanda/go-sysctl \
		adrg:xdg:v0.5.0:adrg_xdg/vendor/github.com/adrg/xdg \
		agnivade:levenshtein:v1.1.1:agnivade_levenshtein/vendor/github.com/agnivade/levenshtein \
		alessio:shellescape:v1.5.0:alessio_shellescape/vendor/al.essio.dev/pkg/shellescape \
		awesome-gocui:gocui:v1.1.0:awesome_gocui_gocui/vendor/github.com/awesome-gocui/gocui \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		blang:semver:v4.0.0:blang_semver_v4/vendor/github.com/blang/semver \
		brutella:dnssd:v1.2.12:brutella_dnssd/vendor/github.com/brutella/dnssd \
		brutella:hc:v1.2.5:brutella_hc/vendor/github.com/brutella/hc \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		choria-io:appbuilder:v0.10.0:choria_io_appbuilder/vendor/github.com/choria-io/appbuilder \
		choria-io:fisk:v0.6.4:choria_io_fisk/vendor/github.com/choria-io/fisk \
		choria-io:go-updater:v0.1.0:choria_io_go_updater/vendor/github.com/choria-io/go-updater \
		choria-io:goform:v0.0.3:choria_io_goform/vendor/github.com/choria-io/goform \
		choria-io:scaffold:v0.0.2:choria_io_scaffold/vendor/github.com/choria-io/scaffold \
		choria-io:tokens:a929d9325d48:choria_io_tokens/vendor/github.com/choria-io/tokens \
		cloudevents:sdk-go:v2.15.2:cloudevents_sdk_go_v2/vendor/github.com/cloudevents/sdk-go \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		emicklei:dot:v1.6.2:emicklei_dot/vendor/github.com/emicklei/dot \
		expr-lang:expr:v1.16.9:expr_lang_expr/vendor/github.com/expr-lang/expr \
		fatih:color:v1.17.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structtag:v1.2.0:fatih_structtag/vendor/github.com/fatih/structtag \
		gdamore:encoding:v1.0.1:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.7.4:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/github.com/go-ini/ini \
		go-logr:logr:v1.4.2:go_logr_logr/vendor/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/vendor/github.com/go-logr/stdr \
		go-task:slim-sprig:v3.0.0:go_task_slim_sprig_v3/vendor/github.com/go-task/slim-sprig/v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gofrs:uuid:v4.4.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		golang-jwt:jwt:v4.5.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:crypto:v0.26.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:9b4947da3948:golang_exp/vendor/golang.org/x/exp \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.20.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.28.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.8.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.24.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.23.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.17.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.6.0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.24.0:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.6.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:pprof:da1f7e9f2b25:google_pprof/vendor/github.com/google/pprof \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		goss-org:GOnetstat:22be0bd9e64d:goss_org_gonetstat/vendor/github.com/goss-org/GOnetstat \
		goss-org:go-ps:7b318e6a56e5:goss_org_go_ps/vendor/github.com/goss-org/go-ps \
		goss-org:goss:v0.4.8:goss_org_goss/vendor/github.com/goss-org/goss \
		gosuri:uilive:v0.0.4:gosuri_uilive/vendor/github.com/gosuri/uilive \
		gosuri:uiprogress:v0.0.1:gosuri_uiprogress/vendor/github.com/gosuri/uiprogress \
		guptarohit:asciigraph:v0.7.2:guptarohit_asciigraph/vendor/github.com/guptarohit/asciigraph \
		hashicorp:logutils:v1.0.0:hashicorp_logutils/vendor/github.com/hashicorp/logutils \
		huandu:xstrings:v1.5.0:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v1.0.1:imdario_mergo/vendor/dario.cat/mergo \
		itchyny:gojq:v0.12.16:itchyny_gojq/vendor/github.com/itchyny/gojq \
		itchyny:timefmt-go:v0.1.6:itchyny_timefmt_go/vendor/github.com/itchyny/timefmt-go \
		jedib0t:go-pretty:v6.5.9:jedib0t_go_pretty_v6/vendor/github.com/jedib0t/go-pretty/v6 \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.17.9:klauspost_compress/vendor/github.com/klauspost/compress \
		kubernetes-sigs:yaml:v1.4.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		looplab:fsm:v1.0.2:looplab_fsm/vendor/github.com/looplab/fsm \
		lucasb-eyer:go-colorful:v1.2.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.16:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		miekg:dns:v1.1.62:miekg_dns/vendor/github.com/miekg/dns \
		miekg:pkcs11:v1.1.1:miekg_pkcs11/vendor/github.com/miekg/pkcs11 \
		minio:highwayhash:v1.0.3:minio_highwayhash/vendor/github.com/minio/highwayhash \
		mitchellh:copystructure:v1.2.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.2:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		moby:sys:mountinfo/v0.7.2:moby_sys_mountinfo/vendor/github.com/moby/sys \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		munnerz:goautoneg:a7dc8b61c822:munnerz_goautoneg/vendor/github.com/munnerz/goautoneg \
		nats-io:jsm.go:v0.1.2:nats_io_jsm_go/vendor/github.com/nats-io/jsm.go \
		nats-io:jwt:v2.5.8:nats_io_jwt_v2/vendor/github.com/nats-io/jwt \
		nats-io:nats-server:v2.10.20:nats_io_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		nats-io:nats.go:v1.37.0:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:natscli:v0.1.5:nats_io_natscli/vendor/github.com/nats-io/natscli \
		nats-io:nkeys:v0.4.7:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		oleiade:reflections:v1.0.1:oleiade_reflections/vendor/github.com/oleiade/reflections \
		onsi:ginkgo:v2.20.2:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		onsi:gomega:v1.34.2:onsi_gomega/vendor/github.com/onsi/gomega \
		open-policy-agent:opa:v0.68.0:open_policy_agent_opa/vendor/github.com/open-policy-agent/opa \
		open-telemetry:opentelemetry-go:v1.29.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.20.2:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.6.1:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.57.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.15.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.34.2:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:cf1acfcdf475:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		robfig:cron:v1.2.0:robfig_cron/vendor/github.com/robfig/cron \
		samber:lo:v1.47.0:samber_lo/vendor/github.com/samber/lo \
		santhosh-tekuri:jsonschema:v5.3.1:santhosh_tekuri_jsonschema_v5/vendor/github.com/santhosh-tekuri/jsonschema/v5 \
		segmentio:ksuid:v1.0.4:segmentio_ksuid/vendor/github.com/segmentio/ksuid \
		shopspring:decimal:v1.4.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cast:v1.7.0:spf13_cast/vendor/github.com/spf13/cast \
		tadglines:go-pkgs:b983b20f54f9:tadglines_go_pkgs/vendor/github.com/tadglines/go-pkgs \
		tchap:go-patricia:v2.3.1:tchap_go_patricia_v2/vendor/github.com/tchap/go-patricia/v2 \
		tidwall:gjson:v1.17.3:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.1:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tylertreat:hdrhistogram-writer:2e440612a39f:tylertreat_hdrhistogram_writer/vendor/github.com/tylertreat/hdrhistogram-writer \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.27.0:uber_go_zap/vendor/go.uber.org/zap \
		vishvananda:netlink:v1.3.0:vishvananda_netlink/vendor/github.com/vishvananda/netlink \
		vishvananda:netns:v0.0.4:vishvananda_netns/vendor/github.com/vishvananda/netns \
		xeipuuv:gojsonpointer:02993c407bfb:xeipuuv_gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
		xeipuuv:gojsonreference:bd5ef7bd5415:xeipuuv_gojsonreference/vendor/github.com/xeipuuv/gojsonreference \
		xiam:to:d60d31e03561:xiam_to/vendor/github.com/xiam/to \
		xlab:tablewriter:80b567a11ad5:xlab_tablewriter/vendor/github.com/xlab/tablewriter \
		yashtewari:glob-intersection:v0.2.0:yashtewari_glob_intersection/vendor/github.com/yashtewari/glob-intersection

x-post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/nats-io/jwt/v2
	@${RLN} ${WRKSRC_nats_io_jwt_v2}/v2 ${WRKSRC}/vendor/github.com/nats-io/jwt/v2

post-patch:
	${REINPLACE_CMD} -e 's/{{cpkg_name}}/choria-broker/' \
		${WRKSRC}/packager/templates/debian/global/broker.conf
	${REINPLACE_CMD} -e 's/{{cpkg_name}}/choria-server/' \
		${WRKSRC}/packager/templates/debian/global/server.conf

pre-build:
	(cd ${GO_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} generate ${GO_BUILDFLAGS} -run plugin)

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
