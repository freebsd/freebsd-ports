# $FreeBSD$

PORTNAME=	step-cli
DISTVERSIONPREFIX=v
DISTVERSION=	0.15.7
CATEGORIES=	security

MAINTAINER=	mw@wipp.bayern
COMMENT=	Smallstep step-ca command line client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	smallstep
GH_PROJECT=	cli
GH_TUPLE=	\
		AndreasBriese:bbloom:46b345b51c96:andreasbriese_bbloom/vendor/github.com/AndreasBriese/bbloom \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		DataDog:zstd:v1.4.5:datadog_zstd/vendor/github.com/DataDog/zstd \
		Masterminds:goutils:v1.1.0:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.1.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.1.0:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		Microsoft:go-winio:v0.4.14:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		OpenPeeDeeP:depguard:v1.0.0:openpeedeep_depguard/vendor/github.com/OpenPeeDeeP/depguard \
		ThomasRooney:gexpect:5482f0350944:thomasrooney_gexpect/vendor/github.com/ThomasRooney/gexpect \
		asaskevich:govalidator:f9ffefc3facf:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		beorn7:perks:v1.0.0:beorn7_perks/vendor/github.com/beorn7/perks \
		bgentry:speakeasy:v0.1.0:bgentry_speakeasy/vendor/github.com/bgentry/speakeasy \
		boombuler:barcode:v1.0.0:boombuler_barcode/vendor/github.com/boombuler/barcode \
		census-instrumentation:opencensus-go:v0.22.5:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cheggaaa:pb:v1.0.28:cheggaaa_pb/vendor/gopkg.in/cheggaaa/pb.v1 \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		coreos:bbolt:v1.3.2:coreos_bbolt/vendor/github.com/coreos/bbolt \
		coreos:etcd:v3.3.13:coreos_etcd/vendor/github.com/coreos/etcd \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:95778dfbb74e:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		coreos:pkg:399ea9e2e55f:coreos_pkg/vendor/github.com/coreos/pkg \
		corpix:uarand:v0.1.1:corpix_uarand/vendor/github.com/corpix/uarand \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgraph-io:badger:5d1bab4fc658:dgraph_io_badger_v2/vendor/github.com/dgraph-io/badger/v2 \
		dgraph-io:badger:v1.6.2:dgraph_io_badger/vendor/github.com/dgraph-io/badger \
		dgraph-io:ristretto:41ebdbffecfd:dgraph_io_ristretto/vendor/github.com/dgraph-io/ristretto \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dgryski:go-farm:a6ae2369ad13:dgryski_go_farm/vendor/github.com/dgryski/go-farm \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		etcd-io:bbolt:v1.3.5:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		etcd-io:etcd:v3.3.13:etcd_io_etcd \
		fatih:color:v1.6.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-chi:chi:v4.0.2:go_chi_chi/vendor/github.com/go-chi/chi \
		go-critic:go-critic:1df300866540:go_critic_go_critic/vendor/github.com/go-critic/go-critic \
		go-lintpack:lintpack:v0.5.2:go_lintpack_lintpack/vendor/github.com/go-lintpack/lintpack \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-toolsmith:astcast:v1.0.0:go_toolsmith_astcast/vendor/github.com/go-toolsmith/astcast \
		go-toolsmith:astcopy:v1.0.0:go_toolsmith_astcopy/vendor/github.com/go-toolsmith/astcopy \
		go-toolsmith:astequal:v1.0.0:go_toolsmith_astequal/vendor/github.com/go-toolsmith/astequal \
		go-toolsmith:astfmt:v1.0.0:go_toolsmith_astfmt/vendor/github.com/go-toolsmith/astfmt \
		go-toolsmith:astp:v1.0.0:go_toolsmith_astp/vendor/github.com/go-toolsmith/astp \
		go-toolsmith:strparse:v1.0.0:go_toolsmith_strparse/vendor/github.com/go-toolsmith/strparse \
		go-toolsmith:typep:v1.0.0:go_toolsmith_typep/vendor/github.com/go-toolsmith/typep \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.2.7:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gogo:protobuf:v1.1.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.6:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:9e8e0b390897:golang_crypto/vendor/golang.org/x/crypto \
		golang:glog:23def4e6c14b:golang_glog/vendor/github.com/golang/glog \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mock:v1.4.4:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:5f4716e94777:golang_net/vendor/golang.org/x/net \
		golang:oauth2:5d25da1a8d43:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.2:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:22da62e12c0c:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		golang:tools:6003fad69a88:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		golangci:check:cfe4005ccda2:golangci_check/vendor/github.com/golangci/check \
		golangci:dupl:3e9179ac440a:golangci_dupl/vendor/github.com/golangci/dupl \
		golangci:errcheck:ef45e06d44b6:golangci_errcheck/vendor/github.com/golangci/errcheck \
		golangci:go-misc:927a3d87b613:golangci_go_misc/vendor/github.com/golangci/go-misc \
		golangci:go-tools:e32c54105b7c:golangci_go_tools/vendor/github.com/golangci/go-tools \
		golangci:goconst:041c5f2b40f3:golangci_goconst/vendor/github.com/golangci/goconst \
		golangci:gocyclo:2becd97e67ee:golangci_gocyclo/vendor/github.com/golangci/gocyclo \
		golangci:gofmt:0b8337e80d98:golangci_gofmt/vendor/github.com/golangci/gofmt \
		golangci:golangci-lint:bad04bb7378f:golangci_golangci_lint/vendor/github.com/golangci/golangci-lint \
		golangci:gosec:66fb7fc33547:golangci_gosec/vendor/github.com/golangci/gosec \
		golangci:ineffassign:42439a7714cc:golangci_ineffassign/vendor/github.com/golangci/ineffassign \
		golangci:lint-1:ee948d087217:golangci_lint_1/vendor/github.com/golangci/lint-1 \
		golangci:maligned:b1d89398deca:golangci_maligned/vendor/github.com/golangci/maligned \
		golangci:misspell:950f5d19e770:golangci_misspell/vendor/github.com/golangci/misspell \
		golangci:prealloc:215b22d4de21:golangci_prealloc/vendor/github.com/golangci/prealloc \
		golangci:revgrep:d9c87f5ffaf0:golangci_revgrep/vendor/github.com/golangci/revgrep \
		golangci:unconvert:28b1c447d1f4:golangci_unconvert/vendor/github.com/golangci/unconvert \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		google:certificate-transparency-go:v1.1.0:google_certificate_transparency_go/vendor/github.com/google/certificate-transparency-go \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:1ed22bb0c154:google_go_genproto/vendor/google.golang.org/genproto \
		google:monologue:4b11a32b5934:google_monologue/vendor/github.com/google/monologue \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.33.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.70.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		gostaticanalysis:analysisutil:4088753ea4d3:gostaticanalysis_analysisutil/vendor/github.com/gostaticanalysis/analysisutil \
		grpc-ecosystem:go-grpc-middleware:v1.0.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc-ecosystem:grpc-gateway:v1.9.0:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.29.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		huandu:xstrings:v1.3.1:huandu_xstrings/vendor/github.com/huandu/xstrings \
		icrowley:fake:4178557ae428:icrowley_fake/vendor/github.com/icrowley/fake \
		imdario:mergo:v0.3.8:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jonboulle:clockwork:v0.1.0:jonboulle_clockwork/vendor/github.com/jonboulle/clockwork \
		json-iterator:go:v1.1.6:json_iterator_go/vendor/github.com/json-iterator/go \
		juju:ansiterm:720a0952cc2a:juju_ansiterm/vendor/github.com/juju/ansiterm \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		kisielk:gotool:v1.0.0:kisielk_gotool/vendor/github.com/kisielk/gotool \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kr:pty:v1.1.1:kr_pty/vendor/github.com/kr/pty \
		lunixbochs:vtclean:v1.0.0:lunixbochs_vtclean/vendor/github.com/lunixbochs/vtclean \
		magiconair:properties:v1.8.0:magiconair_properties/vendor/github.com/magiconair/properties \
		manifoldco:promptui:v0.8.0:manifoldco_promptui/vendor/github.com/manifoldco/promptui \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.11:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:copystructure:v1.0.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.0:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mozilla-services:pkcs7:432b2356ecb1:mozilla_services_pkcs7/vendor/go.mozilla.org/pkcs7 \
		mvdan:interfacer:c20040233aed:mvdan_interfacer/vendor/mvdan.cc/interfacer \
		mvdan:lint:adc824a0674b:mvdan_lint/vendor/mvdan.cc/lint \
		mvdan:unparam:fbb59629db34:mvdan_unparam/vendor/mvdan.cc/unparam \
		nbutton23:zxcvbn-go:eafdab6b0663:nbutton23_zxcvbn_go/vendor/github.com/nbutton23/zxcvbn-go \
		newrelic:go-agent:v2.15.0:newrelic_go_agent/vendor/github.com/newrelic/go-agent \
		olekukonko:tablewriter:v0.0.1:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pquerna:otp:v1.0.0:pquerna_otp/vendor/github.com/pquerna/otp \
		prometheus:client_golang:v0.9.4:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:14fe0d1b01d4:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.4.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.2:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rs:xid:v1.2.1:rs_xid/vendor/github.com/rs/xid \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		samfoo:ansi:b6bd2ded7189:samfoo_ansi/vendor/github.com/samfoo/ansi \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		smallstep:assert:82e2b9b3b262:smallstep_assert/vendor/github.com/smallstep/assert \
		smallstep:certificates:v0.15.7:smallstep_certificates/vendor/github.com/smallstep/certificates \
		smallstep:certinfo:v1.5.0:smallstep_certinfo/vendor/github.com/smallstep/certinfo \
		smallstep:cli-utils:v0.1.0:smallstep_cli_utils/vendor/go.step.sm/cli-utils \
		smallstep:crypto:v0.7.3:smallstep_crypto/vendor/go.step.sm/crypto \
		smallstep:nosql:v0.3.6:smallstep_nosql/vendor/github.com/smallstep/nosql \
		smallstep:truststore:v0.9.6:smallstep_truststore/vendor/github.com/smallstep/truststore \
		smallstep:zcrypto:fbc32cf76bce:smallstep_zcrypto/vendor/github.com/smallstep/zcrypto \
		smallstep:zlint:d84eaafe274f:smallstep_zlint/vendor/github.com/smallstep/zlint \
		soheilhy:cmux:v0.1.4:soheilhy_cmux/vendor/github.com/soheilhy/cmux \
		sourcegraph:go-diff:v0.5.1:sourcegraph_go_diff/vendor/github.com/sourcegraph/go-diff \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.3.2:spf13_viper/vendor/github.com/spf13/viper \
		sqs:pbtypes:d3ebe8f20ae4:sqs_pbtypes/vendor/sourcegraph.com/sqs/pbtypes \
		square:go-jose:v2.5.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		timakin:bodyclose:87058b9bfcec:timakin_bodyclose/vendor/github.com/timakin/bodyclose \
		tmc:grpc-websocket-proxy:0ad062ec5ee5:tmc_grpc_websocket_proxy/vendor/github.com/tmc/grpc-websocket-proxy \
		uber-go:atomic:v1.4.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.1.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.10.0:uber_go_zap/vendor/go.uber.org/zap \
		ultraware:funlen:v0.0.1:ultraware_funlen/vendor/github.com/ultraware/funlen \
		urfave:cli:v1.22.4:urfave_cli/vendor/github.com/urfave/cli \
		weppos:publicsuffix-go:v0.4.0:weppos_publicsuffix_go/vendor/github.com/weppos/publicsuffix-go \
		xiang90:probing:43a291ad63a2:xiang90_probing/vendor/github.com/xiang90/probing \
		sslmate:go-pkcs12:57fc603b7f52:sslmate_pkcs12/vendor/software.sslmate.com/src/go-pkcs12

GL_TUPLE=	https://gitlab.howett.net:go:plist:591f970eefbbeb04d7b37f334a0c4c3256e32876:go_plist/vendor/howett.net/plist

		# Mirrors for the following packages are not currently known, please look them up and handle these tuples manually:
		#	::57fc603b7f52:group_name/vendor/software.sslmate.com/src/go-pkcs12 (from software.sslmate.com/src/go-pkcs12@57fc603b7f52)


SHEBANG_FILES=	autocomplete/bash_autocomplete

GO_TARGET=	./cmd/step
GO_BUILDFLAGS=	-ldflags "-w -X main.Version=${PORTVERSION}"

PLIST_FILES=	bin/step \
		etc/bash_completion.d/step-completion.bash \
		share/zsh/site-functions/_step

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/go.etcd.io
	@${RLN} ${WRKSRC_coreos_etcd} ${WRKSRC}/vendor/go.etcd.io/etcd

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${CP} ${WRKSRC}/autocomplete/bash_autocomplete ${STAGEDIR}${PREFIX}/etc/bash_completion.d/step-completion.bash
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${CP} ${WRKSRC}/autocomplete/zsh_autocomplete ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_step

.include <bsd.port.mk>
