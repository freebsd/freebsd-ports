PORTNAME=	choria
PORTVERSION=	0.30.2
DISTVERSIONPREFIX=v
CATEGORIES=	sysutils

MAINTAINER=	puppet@FreeBSD.org
COMMENT=	Server to host Choria agents, networks, federations and discovery
WWW=		https://choria.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	choria-io
GH_PROJECT=	go-choria
USE_RC_SUBR=	choria-broker choria-server

GH_TUPLE=	\
		AlecAivazis:survey:v2.3.7:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		CloudyKit:fastprinter:1725d2651bd4:cloudykit_fastprinter/vendor/github.com/CloudyKit/fastprinter \
		CloudyKit:jet:v6.3.2:cloudykit_jet_v6/vendor/github.com/CloudyKit/jet/v6 \
		HdrHistogram:hdrhistogram-go:v1.2.0:hdrhistogram_hdrhistogram_go/vendor/github.com/HdrHistogram/hdrhistogram-go \
		Masterminds:goutils:v1.1.1:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.5.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.3.0:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		achanda:go-sysctl:6be7678c45d2:achanda_go_sysctl/vendor/github.com/achanda/go-sysctl \
		adrg:xdg:v0.5.3:adrg_xdg/vendor/github.com/adrg/xdg \
		agnivade:levenshtein:v1.2.1:agnivade_levenshtein/vendor/github.com/agnivade/levenshtein \
		alessio:shellescape:v1.6.0:alessio_shellescape/vendor/al.essio.dev/pkg/shellescape \
		antithesishq:antithesis-sdk-go:v0.7.0:antithesishq_antithesis_sdk_go/vendor/github.com/antithesishq/antithesis-sdk-go \
		awesome-gocui:gocui:v1.1.0:awesome_gocui_gocui/vendor/github.com/awesome-gocui/gocui \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		blang:semver:v4.0.0:blang_semver_v4/vendor/github.com/blang/semver \
		brutella:hc:v1.2.5:brutella_hc/vendor/github.com/brutella/hc \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		choria-io:appbuilder:v0.17.1:choria_io_appbuilder/vendor/github.com/choria-io/appbuilder \
		choria-io:ccm:v0.0.31:choria_io_ccm/vendor/github.com/choria-io/ccm \
		choria-io:fisk:v0.9.0:choria_io_fisk/vendor/github.com/choria-io/fisk \
		choria-io:go-updater:v0.1.0:choria_io_go_updater/vendor/github.com/choria-io/go-updater \
		choria-io:goform:v0.1.0:choria_io_goform/vendor/github.com/choria-io/goform \
		choria-io:scaffold:v0.0.11:choria_io_scaffold/vendor/github.com/choria-io/scaffold \
		choria-io:tokens:v0.0.4:choria_io_tokens/vendor/github.com/choria-io/tokens \
		choria-io:validator:v0.0.2:choria_io_validator/vendor/github.com/choria-io/validator \
		clipperhouse:uax29:v2.7.0:clipperhouse_uax29_v2/vendor/github.com/clipperhouse/uax29/v2 \
		cloudevents:sdk-go:v2.16.2:cloudevents_sdk_go_v2/vendor/github.com/cloudevents/sdk-go \
		decred:dcrd:76c0dc4f362b:decred_dcrd_v4/vendor/dcrec/secp256k1 \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		ebitengine:purego:v0.10.1:ebitengine_purego/vendor/github.com/ebitengine/purego \
		emicklei:dot:v1.11.0:emicklei_dot/vendor/github.com/emicklei/dot \
		expr-lang:expr:v1.17.8:expr_lang_expr/vendor/github.com/expr-lang/expr \
		fatih:color:v1.19.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structtag:v1.2.0:fatih_structtag/vendor/github.com/fatih/structtag \
		freman:eventloghook:a195f2852650:freman_eventloghook/vendor/github.com/freman/eventloghook \
		gdamore:encoding:v1.0.1:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:v2.13.10:gdamore_tcell_v2/vendor/github.com/gdamore/tcell/v2 \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		gizak:termui:e62b5929642a:gizak_termui/vendor/gopkg.in/gizak/termui.v1 \
		go-logr:logr:v1.4.3:go_logr_logr/vendor/github.com/go-logr/logr \
		go-ole:go-ole:v1.3.0:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-task:slim-sprig:v3.0.0:go_task_slim_sprig_v3/vendor/github.com/go-task/slim-sprig/v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		goccy:go-json:v0.10.6:goccy_go_json/vendor/github.com/goccy/go-json \
		goccy:go-yaml:v1.19.2:goccy_go_yaml/vendor/github.com/goccy/go-yaml \
		gofrs:uuid:v4.4.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		golang-jwt:jwt:v5.3.1:golang_jwt_jwt_v5/vendor/github.com/golang-jwt/jwt/v5 \
		golang:crypto:v0.53.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:c48552f49976:golang_exp/vendor/golang.org/x/exp \
		golang:mod:v0.37.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.56.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.21.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.46.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.44.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.38.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.15.0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.46.0:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.7.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-tpm:v0.9.8:google_go_tpm/vendor/github.com/google/go-tpm \
		google:pprof:7023385849c0:google_pprof/vendor/github.com/google/pprof \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		goss-org:GOnetstat:22be0bd9e64d:goss_org_gonetstat/vendor/github.com/goss-org/GOnetstat \
		goss-org:go-ps:7b318e6a56e5:goss_org_go_ps/vendor/github.com/goss-org/go-ps \
		goss-org:goss:v0.4.9:goss_org_goss/vendor/github.com/goss-org/goss \
		gosuri:uilive:v0.0.4:gosuri_uilive/vendor/github.com/gosuri/uilive \
		gosuri:uiprogress:v0.0.1:gosuri_uiprogress/vendor/github.com/gosuri/uiprogress \
		guptarohit:asciigraph:v0.9.0:guptarohit_asciigraph/vendor/github.com/guptarohit/asciigraph \
		hashicorp:logutils:v1.0.0:hashicorp_logutils/vendor/github.com/hashicorp/logutils \
		huandu:xstrings:v1.5.0:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v1.0.2:imdario_mergo/vendor/dario.cat/mergo \
		itchyny:gojq:v0.12.19:itchyny_gojq/vendor/github.com/itchyny/gojq \
		itchyny:timefmt-go:v0.1.8:itchyny_timefmt_go/vendor/github.com/itchyny/timefmt-go \
		jedib0t:go-pretty:v6.8.1:jedib0t_go_pretty_v6/vendor/github.com/jedib0t/go-pretty/v6 \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.18.6:klauspost_compress/vendor/github.com/klauspost/compress \
		kubernetes-sigs:yaml:v1.6.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		lestrrat-go:blackmagic:v1.0.4:lestrrat_go_blackmagic/vendor/github.com/lestrrat-go/blackmagic \
		lestrrat-go:dsig-secp256k1:v1.0.0:lestrrat_go_dsig_secp256k1/vendor/github.com/lestrrat-go/dsig-secp256k1 \
		lestrrat-go:dsig:v1.3.0:lestrrat_go_dsig/vendor/github.com/lestrrat-go/dsig \
		lestrrat-go:httpcc:v1.0.1:lestrrat_go_httpcc/vendor/github.com/lestrrat-go/httpcc \
		lestrrat-go:httprc:v3.0.6:lestrrat_go_httprc_v3/vendor/github.com/lestrrat-go/httprc/v3 \
		lestrrat-go:jwx:v3.1.1:lestrrat_go_jwx_v3/vendor/github.com/lestrrat-go/jwx/v3 \
		lestrrat-go:option:v2.0.0:lestrrat_go_option_v2/vendor/github.com/lestrrat-go/option/v2 \
		looplab:fsm:v1.0.3:looplab_fsm/vendor/github.com/looplab/fsm \
		lucasb-eyer:go-colorful:v1.4.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		lufia:plan9stats:c963978e514e:lufia_plan9stats/vendor/github.com/lufia/plan9stats \
		mattn:go-colorable:v0.1.15:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.22:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.24:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		miekg:dns:v1.1.72:miekg_dns/vendor/github.com/miekg/dns \
		miekg:pkcs11:v1.1.2:miekg_pkcs11/vendor/github.com/miekg/pkcs11 \
		minio:highwayhash:v1.0.4:minio_highwayhash/vendor/github.com/minio/highwayhash \
		mitchellh:copystructure:v1.2.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.2:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		moby:sys:mountinfo/v0.7.2:moby_sys_mountinfo/vendor/github.com/moby/sys \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		munnerz:goautoneg:a7dc8b61c822:munnerz_goautoneg/vendor/github.com/munnerz/goautoneg \
		nats-io:jsm.go:v0.4.1:nats_io_jsm_go/vendor/github.com/nats-io/jsm.go \
		nats-io:jwt:v2.8.2:nats_io_jwt_v2/vendor/github.com/nats-io/jwt \
		nats-io:nats-server:v2.14.2:nats_io_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		nats-io:nats.go:v1.52.0:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:natscli:v0.4.0:nats_io_natscli/vendor/github.com/nats-io/natscli \
		nats-io:nkeys:v0.4.16:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nsc:v2.15.0:nats_io_nsc_v2/vendor/github.com/nats-io/nsc/v2 \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		nsf:termbox-go:v1.1.1:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		oleiade:reflections:v1.1.0:oleiade_reflections/vendor/github.com/oleiade/reflections \
		onsi:ginkgo:v2.31.0:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		onsi:gomega:v1.42.0:onsi_gomega/vendor/github.com/onsi/gomega \
		open-policy-agent:opa:v1.17.1:open_policy_agent_opa/vendor/github.com/open-policy-agent/opa \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pmezard:go-difflib:5d4384ee4fb2:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		power-devops:perfstat:82ca36839d55:power_devops_perfstat/vendor/github.com/power-devops/perfstat \
		prometheus:client_golang:v1.23.2:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.6.2:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.68.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.20.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.36.11:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:65e299d6c5c9:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		robfig:cron:v1.2.0:robfig_cron/vendor/github.com/robfig/cron \
		samber:lo:v1.53.0:samber_lo/vendor/github.com/samber/lo \
		santhosh-tekuri:jsonschema:v5.3.1:santhosh_tekuri_jsonschema_v5/vendor/github.com/santhosh-tekuri/jsonschema/v5 \
		santhosh-tekuri:jsonschema:v6.0.2:santhosh_tekuri_jsonschema_v6/vendor/github.com/santhosh-tekuri/jsonschema/v6 \
		segmentio:asm:v1.2.1:segmentio_asm/vendor/github.com/segmentio/asm \
		segmentio:ksuid:v1.0.4:segmentio_ksuid/vendor/github.com/segmentio/ksuid \
		shirou:gopsutil:v4.26.5:shirou_gopsutil_v4/vendor/github.com/shirou/gopsutil/v4 \
		shopspring:decimal:v1.4.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		sirupsen:logrus:v1.9.4:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cast:v1.10.0:spf13_cast/vendor/github.com/spf13/cast \
		synadia-io:jwt-auth-builder.go:v0.0.10:synadia_io_jwt_auth_builder_go/vendor/github.com/synadia-io/jwt-auth-builder.go \
		synadia-io:orbit.go:counters/v0.1.1:synadia_io_orbit_go_counters \
		synadia-io:orbit.go:jetstreamext/v0.3.1:synadia_io_orbit_go_jetstreamext \
		synadia-io:orbit.go:natscontext/v0.1.2:synadia_io_orbit_go_natscontext \
		synadia-io:orbit.go:natsext/v0.1.2:synadia_io_orbit_go_natsext/vendor/github.com/synadia-io/orbit.go \
		tchap:go-patricia:v2.3.3:tchap_go_patricia_v2/vendor/github.com/tchap/go-patricia/v2 \
		tidwall:gjson:v1.19.0:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.2.0:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.1:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tklauser:go-sysconf:v0.4.0:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.12.0:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		tylertreat:hdrhistogram-writer:2e440612a39f:tylertreat_hdrhistogram_writer/vendor/github.com/tylertreat/hdrhistogram-writer \
		uber-go:mock:v0.6.0:uber_go_mock/vendor/go.uber.org/mock \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.28.0:uber_go_zap/vendor/go.uber.org/zap \
		valyala:fastjson:v1.6.10:valyala_fastjson/vendor/github.com/valyala/fastjson \
		vektah:gqlparser:v2.5.34:vektah_gqlparser_v2/vendor/github.com/vektah/gqlparser/v2 \
		xeipuuv:gojsonpointer:02993c407bfb:xeipuuv_gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
		xeipuuv:gojsonreference:bd5ef7bd5415:xeipuuv_gojsonreference/vendor/github.com/xeipuuv/gojsonreference \
		xiam:to:d60d31e03561:xiam_to/vendor/github.com/xiam/to \
		xlab:tablewriter:80b567a11ad5:xlab_tablewriter/vendor/github.com/xlab/tablewriter \
		yaml:go-yaml:v2.4.4:yaml_go_yaml/vendor/go.yaml.in/yaml/v2 \
		yaml:go-yaml:v3.0.4:yaml_go_yaml_1/vendor/go.yaml.in/yaml/v3 \
		yashtewari:glob-intersection:v0.2.0:yashtewari_glob_intersection/vendor/github.com/yashtewari/glob-intersection \
		yusufpapurcu:wmi:v1.2.4:yusufpapurcu_wmi/vendor/github.com/yusufpapurcu/wmi

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/synadia-io/orbit.go/counters
	@${RLN} ${WRKSRC_synadia_io_orbit_go_counters}/counters ${WRKSRC}/vendor/github.com/synadia-io/orbit.go/counters
	@${RM} -r ${WRKSRC}/vendor/github.com/synadia-io/orbit.go/jetstreamext
	@${RLN} ${WRKSRC_synadia_io_orbit_go_jetstreamext}/jetstreamext ${WRKSRC}/vendor/github.com/synadia-io/orbit.go/jetstreamext
	@${RM} -r ${WRKSRC}/vendor/github.com/synadia-io/orbit.go/natscontext
	@${RLN} ${WRKSRC_synadia_io_orbit_go_natscontext}/natscontext ${WRKSRC}/vendor/github.com/synadia-io/orbit.go/natscontext

post-patch:
	${REINPLACE_CMD} -e 's/{{cpkg_name}}/choria-broker/' \
		${WRKSRC}/packager/templates/debian/global/broker.conf
	${REINPLACE_CMD} -e 's/{{cpkg_name}}/choria-server/' \
		${WRKSRC}/packager/templates/debian/global/server.conf

pre-build:
#	(cd ${GO_WRKSRC} && \
#		go generate -mod=vendor -run plugin)
	(cd ${GO_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOMAXPROCS=${MAKE_JOBS_NUMBER} GOPROXY=off ${GO_CMD} generate -mod=vendor -run plugin)


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
