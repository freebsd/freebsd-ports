PORTNAME=	concourse
DISTVERSIONPREFIX=	v
DISTVERSION=	8.2.3
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Automation system written in Go
WWW=		https://concourse-ci.org/ \
		https://github.com/concourse/concourse

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cpe go:1.26+,modules
USE_GITHUB=	yes

CONFLICTS_INSTALL=	concourse-fly fly # bin/fly

CPE_VENDOR=	pivotal_software

GH_TUPLE=	\
		AppsFlyer:go-sundheit:v0.6.0:appsflyer_go_sundheit/vendor/github.com/AppsFlyer/go-sundheit \
		Azure:go-ntlmssp:v0.1.1:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		DataDog:datadog-go:v5.8.3:datadog_datadog_go_v5/vendor/github.com/DataDog/datadog-go/v5 \
		FiloSottile:edwards25519:v1.2.0:filosottile_edwards25519/vendor/filippo.io/edwards25519 \
		GoogleCloudPlatform:opentelemetry-operations-go:exporter/trace/v1.32.0:googlecloudplatform_opentelemetry_operations_go_trace/vendor/github.com/GoogleCloudPlatform/opentelemetry-operations-go \
		GoogleCloudPlatform:opentelemetry-operations-go:internal/resourcemapping/v0.56.0:googlecloudplatform_opentelemetry_operations_go_resourcemapping \
		Masterminds:goutils:v1.1.1:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.5.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.3.0:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		Masterminds:squirrel:v1.5.4:masterminds_squirrel/vendor/github.com/Masterminds/squirrel \
		Microsoft:go-winio:ad3df93bed29:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.15.0-rc.1:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		VividCortex:ewma:v1.2.0:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		acarl005:stripansi:5a71ef0e047d:acarl005_stripansi/vendor/github.com/acarl005/stripansi \
		aryann:difflib:ff5ff6dc229b:aryann_difflib/vendor/github.com/aryann/difflib \
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aws:aws-sdk-go-v2:config/v1.32.17:aws_aws_sdk_go_v2_config \
		aws:aws-sdk-go-v2:credentials/v1.19.16:aws_aws_sdk_go_v2_credentials \
		aws:aws-sdk-go-v2:feature/ec2/imds/v1.18.23:aws_aws_sdk_go_v2_imds \
		aws:aws-sdk-go-v2:internal/configsources/v1.4.23:aws_aws_sdk_go_v2_configsources \
		aws:aws-sdk-go-v2:internal/endpoints/v2.7.23:aws_aws_sdk_go_v2_v2 \
		aws:aws-sdk-go-v2:internal/v4a/v1.4.24:aws_aws_sdk_go_v2_v4a \
		aws:aws-sdk-go-v2:service/internal/accept-encoding/v1.13.9:aws_aws_sdk_go_v2_accept_encoding \
		aws:aws-sdk-go-v2:service/internal/presigned-url/v1.13.23:aws_aws_sdk_go_v2_presigned_url \
		aws:aws-sdk-go-v2:service/secretsmanager/v1.41.7:aws_aws_sdk_go_v2_secretsmanager \
		aws:aws-sdk-go-v2:service/signin/v1.0.11:aws_aws_sdk_go_v2_signin \
		aws:aws-sdk-go-v2:service/ssm/v1.68.6:aws_aws_sdk_go_v2_ssm \
		aws:aws-sdk-go-v2:service/sso/v1.30.17:aws_aws_sdk_go_v2_sso \
		aws:aws-sdk-go-v2:service/ssooidc/v1.35.21:aws_aws_sdk_go_v2_ssooidc \
		aws:aws-sdk-go-v2:service/sts/v1.42.1:aws_aws_sdk_go_v2_sts \
		aws:aws-sdk-go-v2:v1.41.7:aws_aws_sdk_go_v2/vendor/github.com/aws/aws-sdk-go-v2 \
		aws:smithy-go:v1.25.1:aws_smithy_go/vendor/github.com/aws/smithy-go \
		beevik:etree:v1.6.0:beevik_etree/vendor/github.com/beevik/etree \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		bmizerany:pat:e4b6760bdd6f:bmizerany_pat/vendor/github.com/bmizerany/pat \
		caarlos0:env:v11.4.0:caarlos0_env_v11/vendor/github.com/caarlos0/env/v11 \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		cenkalti:backoff:v4.3.0:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		cenkalti:backoff:v5.0.3:cenkalti_backoff_v5/vendor/github.com/cenkalti/backoff/v5 \
		census-instrumentation:opencensus-go:v0.24.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		charlievieth:fs:v0.0.3:charlievieth_fs/vendor/github.com/charlievieth/fs \
		charmbracelet:bubbles:v2.1.0:charmbracelet_bubbles_v2/vendor/charm.land/bubbles/v2 \
		charmbracelet:bubbletea:v2.0.6:charmbracelet_bubbletea_v2/vendor/charm.land/bubbletea/v2 \
		charmbracelet:colorprofile:v0.4.3:charmbracelet_colorprofile/vendor/github.com/charmbracelet/colorprofile \
		charmbracelet:lipgloss:v2.0.3:charmbracelet_lipgloss_v2/vendor/charm.land/lipgloss/v2 \
		charmbracelet:ultraviolet:66037269d7be:charmbracelet_ultraviolet/vendor/github.com/charmbracelet/ultraviolet \
		charmbracelet:x:ansi/v0.11.7:charmbracelet_x_ansi \
		charmbracelet:x:term/v0.2.2:charmbracelet_x_term/vendor/github.com/charmbracelet/x \
		charmbracelet:x:termios/v0.1.1:charmbracelet_x_termios \
		charmbracelet:x:windows/v0.2.2:charmbracelet_x_windows \
		clipperhouse:displaywidth:v0.11.0:clipperhouse_displaywidth/vendor/github.com/clipperhouse/displaywidth \
		clipperhouse:uax29:v2.7.0:clipperhouse_uax29_v2/vendor/github.com/clipperhouse/uax29/v2 \
		cloudfoundry:clock:v1.68.0:cloudfoundry_clock/vendor/code.cloudfoundry.org/clock \
		cloudfoundry:credhub-cli:96647328890b:cloudfoundry_credhub_cli/vendor/code.cloudfoundry.org/credhub-cli \
		cloudfoundry:garden:3f9ac7a76d56:cloudfoundry_garden/vendor/code.cloudfoundry.org/garden \
		cloudfoundry:go-socks5:4ad5fea42851:cloudfoundry_go_socks5/vendor/github.com/cloudfoundry/go-socks5 \
		cloudfoundry:lager:v3.67.0:cloudfoundry_lager_v3/vendor/code.cloudfoundry.org/lager/v3 \
		cloudfoundry:localip:v0.69.0:cloudfoundry_localip/vendor/code.cloudfoundry.org/localip \
		cloudfoundry:socks5-proxy:v0.2.173:cloudfoundry_socks5_proxy/vendor/github.com/cloudfoundry/socks5-proxy \
		concourse:dex:v1.14.0:concourse_dex/vendor/github.com/concourse/dex \
		concourse:go-archive:v1.0.1:concourse_go_archive/vendor/github.com/concourse/go-archive \
		concourse:houdini:v1.3.0:concourse_houdini/vendor/github.com/concourse/houdini \
		concourse:retryhttp:v1.3.0:concourse_retryhttp/vendor/github.com/concourse/retryhttp \
		containerd:cgroups:v3.1.3:containerd_cgroups_v3/vendor/github.com/containerd/cgroups/v3 \
		containerd:containerd:api/v1.11.1:containerd_containerd_api/vendor/github.com/containerd/containerd \
		containerd:containerd:v2.3.1:containerd_containerd_v2/vendor/github.com/containerd/containerd/v2 \
		containerd:continuity:v0.5.0:containerd_continuity/vendor/github.com/containerd/continuity \
		containerd:errdefs:pkg/v0.3.0:containerd_errdefs_pkg \
		containerd:errdefs:v1.0.0:containerd_errdefs/vendor/github.com/containerd/errdefs \
		containerd:fifo:v1.1.0:containerd_fifo/vendor/github.com/containerd/fifo \
		containerd:go-cni:v1.1.13:containerd_go_cni/vendor/github.com/containerd/go-cni \
		containerd:log:v0.1.0:containerd_log/vendor/github.com/containerd/log \
		containerd:platforms:v1.0.0-rc.4:containerd_platforms/vendor/github.com/containerd/platforms \
		containerd:plugin:v1.1.0:containerd_plugin/vendor/github.com/containerd/plugin \
		containerd:ttrpc:v1.2.8:containerd_ttrpc/vendor/github.com/containerd/ttrpc \
		containerd:typeurl:v2.2.3:containerd_typeurl_v2/vendor/github.com/containerd/typeurl/v2 \
		containernetworking:cni:v1.3.0:containernetworking_cni/vendor/github.com/containernetworking/cni \
		coreos:go-iptables:v0.8.0:coreos_go_iptables/vendor/github.com/coreos/go-iptables \
		coreos:go-oidc:v3.18.0:coreos_go_oidc_v3/vendor/github.com/coreos/go-oidc/v3 \
		coreos:go-systemd:v22.7.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		cppforlife:go-semi-semantic:576b6af77ae4:cppforlife_go_semi_semantic/vendor/github.com/cppforlife/go-semi-semantic \
		creack:pty:v1.1.24:creack_pty/vendor/github.com/creack/pty \
		cyberark:conjur-api-go:v0.13.19:cyberark_conjur_api_go/vendor/github.com/cyberark/conjur-api-go \
		cyphar:filepath-securejoin:v0.6.1:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		danieljoos:wincred:v1.2.3:danieljoos_wincred/vendor/github.com/danieljoos/wincred \
		davecgh:go-spew:d8f796af33cc:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dexidp:dex:api/v2.4.0:dexidp_dex_v2/vendor/github.com/dexidp/dex \
		distribution:reference:v0.6.0:distribution_reference/vendor/github.com/distribution/reference \
		emicklei:go-restful:v3.13.0:emicklei_go_restful_v3/vendor/github.com/emicklei/go-restful/v3 \
		evanphx:json-patch:v4.13.0:evanphx_json_patch/vendor/gopkg.in/evanphx/json-patch.v4 \
		fatih:color:v1.19.0:fatih_color/vendor/github.com/fatih/color \
		felixge:httpsnoop:v1.0.4:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		fxamacker:cbor:v2.9.1:fxamacker_cbor_v2/vendor/github.com/fxamacker/cbor/v2 \
		go-asn1-ber:asn1-ber:29230038a667:go_asn1_ber_asn1_ber/vendor/github.com/go-asn1-ber/asn1-ber \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-jose:go-jose:v4.1.4:go_jose_go_jose_v4/vendor/github.com/go-jose/go-jose/v4 \
		go-ldap:ldap:v3.4.13:go_ldap_ldap_v3/vendor/github.com/go-ldap/ldap \
		go-logr:logr:v1.4.3:go_logr_logr/vendor/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/vendor/github.com/go-logr/stdr \
		go-openapi:jsonpointer:v0.23.1:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.21.5:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:swag:cmdutils/v0.26.0:go_openapi_swag_cmdutils \
		go-openapi:swag:conv/v0.26.0:go_openapi_swag_conv \
		go-openapi:swag:fileutils/v0.26.0:go_openapi_swag_fileutils \
		go-openapi:swag:jsonname/v0.26.0:go_openapi_swag_jsonname \
		go-openapi:swag:jsonutils/v0.26.0:go_openapi_swag_jsonutils \
		go-openapi:swag:loading/v0.26.0:go_openapi_swag_loading \
		go-openapi:swag:mangling/v0.26.0:go_openapi_swag_mangling \
		go-openapi:swag:netutils/v0.26.0:go_openapi_swag_netutils \
		go-openapi:swag:stringutils/v0.26.0:go_openapi_swag_stringutils \
		go-openapi:swag:typeutils/v0.26.0:go_openapi_swag_typeutils \
		go-openapi:swag:v0.26.0:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-openapi:swag:yamlutils/v0.26.0:go_openapi_swag_yamlutils \
		go-sql-driver:mysql:v1.10.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-task:slim-sprig:v3.0.0:go_task_slim_sprig_v3/vendor/github.com/go-task/slim-sprig/v3 \
		go-viper:mapstructure:v2.5.0:go_viper_mapstructure_v2/vendor/github.com/go-viper/mapstructure/v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		goccy:go-yaml:v1.19.2:goccy_go_yaml/vendor/github.com/goccy/go-yaml \
		godbus:dbus:v5.2.2:godbus_dbus_v5/vendor/github.com/godbus/dbus/v5 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-jwt:jwt:v5.3.1:golang_jwt_jwt_v5/vendor/github.com/golang-jwt/jwt/v5 \
		golang:crypto:v0.50.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:746e56fc9e2f:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:2c02b8208cf8:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mod:v0.35.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.53.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.36.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sync:v0.20.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.43.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.42.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.36.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.15.0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.44.0:golang_tools/vendor/golang.org/x/tools \
		google:gnostic-models:v0.7.1:google_gnostic_models/vendor/github.com/google/gnostic-models \
		google:go-cmp:v0.7.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:7cedc36a6bc4:google_go_genproto_api/vendor/google.golang.org/genproto \
		google:jsonapi:v1.0.0:google_jsonapi/vendor/github.com/google/jsonapi \
		google:pprof:545e8a4df936:google_pprof/vendor/github.com/google/pprof \
		google:s2a-go:v0.1.9:google_s2a_go/vendor/github.com/google/s2a-go \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:enterprise-certificate-proxy:v0.3.15:googleapis_enterprise_certificate_proxy/vendor/github.com/googleapis/enterprise-certificate-proxy \
		googleapis:gax-go:v2.22.0:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.277.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:auth/oauth2adapt/v0.2.8:googleapis_google_cloud_go_oauth2adapt \
		googleapis:google-cloud-go:auth/v0.20.0:googleapis_google_cloud_go_auth/vendor/cloud.google.com/go \
		googleapis:google-cloud-go:compute/metadata/v0.9.0:googleapis_google_cloud_go_metadata \
		googleapis:google-cloud-go:logging/v1.13.1:googleapis_google_cloud_go_logging \
		googleapis:google-cloud-go:longrunning/v0.7.0:googleapis_google_cloud_go_longrunning \
		googleapis:google-cloud-go:monitoring/v1.24.3:googleapis_google_cloud_go_monitoring \
		googleapis:google-cloud-go:trace/v1.15.0:googleapis_google_cloud_go_trace \
		gorilla:handlers:v1.5.2:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:e064f32e3674:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc-ecosystem:grpc-gateway:v2.29.0:grpc_ecosystem_grpc_gateway_v2/vendor/github.com/grpc-ecosystem/grpc-gateway/v2 \
		grpc:grpc-go:v1.80.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.2:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.7.8:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-secure-stdlib:parseutil/v0.2.0:hashicorp_go_secure_stdlib_parseutil \
		hashicorp:go-secure-stdlib:strutil/v0.1.2:hashicorp_go_secure_stdlib_strutil/vendor/github.com/hashicorp/go-secure-stdlib \
		hashicorp:go-sockaddr:v1.0.7:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-version:v1.9.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl:v1.0.1-vault-7:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:vault:api/v1.23.0:hashicorp_vault_api/vendor/github.com/hashicorp/vault \
		huandu:xstrings:v1.5.0:huandu_xstrings/vendor/github.com/huandu/xstrings \
		imdario:mergo:v1.0.2:imdario_mergo/vendor/dario.cat/mergo \
		inconshreveable:go-update:8152e7eb6ccf:inconshreveable_go_update/vendor/github.com/inconshreveable/go-update \
		influxdata:influxdb1-client:a9ab5670611c:influxdata_influxdb1_client/vendor/github.com/influxdata/influxdb1-client \
		jackc:pgerrcode:afb5586c32a6:jackc_pgerrcode/vendor/github.com/jackc/pgerrcode \
		jackc:pgpassfile:v1.0.0:jackc_pgpassfile/vendor/github.com/jackc/pgpassfile \
		jackc:pgservicefile:5a60cdf6a761:jackc_pgservicefile/vendor/github.com/jackc/pgservicefile \
		jackc:pgx:v5.9.2:jackc_pgx_v5/vendor/github.com/jackc/pgx/v5 \
		jackc:puddle:v2.2.2:jackc_puddle_v2/vendor/github.com/jackc/puddle/v2 \
		jackpal:gateway:v1.2.0:jackpal_gateway/vendor/github.com/jackpal/gateway \
		jessevdk:go-flags:v1.6.1:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		jonboulle:clockwork:v0.5.0:jonboulle_clockwork/vendor/github.com/jonboulle/clockwork \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		klauspost:compress:v1.18.6:klauspost_compress/vendor/github.com/klauspost/compress \
		kubernetes-sigs:json:2d320260d730:kubernetes_sigs_json/vendor/sigs.k8s.io/json \
		kubernetes-sigs:randfill:v1.0.0:kubernetes_sigs_randfill/vendor/sigs.k8s.io/randfill \
		kubernetes-sigs:structured-merge-diff:v6.4.0:kubernetes_sigs_structured_merge_diff_v6/vendor/sigs.k8s.io/structured-merge-diff/v6 \
		kubernetes-sigs:yaml:v1.6.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.36.0:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.36.0:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.36.0:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v2.140.0:kubernetes_klog_v2/vendor/k8s.io/klog/v2 \
		kubernetes:kube-openapi:927ab1f70cd6:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:utils:28399d86e0b5:kubernetes_utils/vendor/k8s.io/utils \
		lann:builder:47ae307949d0:lann_builder/vendor/github.com/lann/builder \
		lann:ps:62de8c46ede0:lann_ps/vendor/github.com/lann/ps \
		lib:pq:v1.12.3:lib_pq/vendor/github.com/lib/pq \
		lucasb-eyer:go-colorful:v1.4.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		madflojo:testcerts:v1.5.0:madflojo_testcerts/vendor/github.com/madflojo/testcerts \
		mattermost:xml-roundtrip-validator:v0.1.0:mattermost_xml_roundtrip_validator/vendor/github.com/mattermost/xml-roundtrip-validator \
		mattn:go-colorable:v0.1.14:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.22:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.23:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v1.14.44:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		maxbrunsfeld:counterfeiter:v6.12.2:maxbrunsfeld_counterfeiter_v6/vendor/github.com/maxbrunsfeld/counterfeiter/v6 \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		miekg:dns:v1.1.72:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:copystructure:v1.2.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.2:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		moby:locker:v1.0.1:moby_locker/vendor/github.com/moby/locker \
		moby:sys:mountinfo/v0.7.2:moby_sys_mountinfo \
		moby:sys:sequential/v0.6.0:moby_sys_sequential \
		moby:sys:signal/v0.7.1:moby_sys_signal \
		moby:sys:user/v0.4.0:moby_sys_user/vendor/github.com/moby/sys \
		moby:sys:userns/v0.1.0:moby_sys_userns \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:35a7c28c31ee:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		munnerz:goautoneg:a7dc8b61c822:munnerz_goautoneg/vendor/github.com/munnerz/goautoneg \
		onsi:ginkgo:v2.28.3:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		onsi:gomega:v1.40.0:onsi_gomega/vendor/github.com/onsi/gomega \
		open-telemetry:opentelemetry-go-contrib:instrumentation/google.golang.org/grpc/otelgrpc/v0.68.0:open_telemetry_opentelemetry_go_contrib_otelgrpc \
		open-telemetry:opentelemetry-go-contrib:instrumentation/net/http/otelhttp/v0.68.0:open_telemetry_opentelemetry_go_contrib_otelhttp/vendor/go.opentelemetry.io/contrib \
		open-telemetry:opentelemetry-go-instrumentation:sdk/v1.2.1:open_telemetry_opentelemetry_go_instrumentation_sdk/vendor/go.opentelemetry.io/auto \
		open-telemetry:opentelemetry-go:exporters/jaeger/v1.17.0:open_telemetry_opentelemetry_go_jaeger \
		open-telemetry:opentelemetry-go:exporters/otlp/otlptrace/otlptracegrpc/v1.43.0:open_telemetry_opentelemetry_go_otlptracegrpc \
		open-telemetry:opentelemetry-go:exporters/otlp/otlptrace/v1.43.0:open_telemetry_opentelemetry_go_otlptrace \
		open-telemetry:opentelemetry-go:metric/v1.43.0:open_telemetry_opentelemetry_go_metric \
		open-telemetry:opentelemetry-go:sdk/v1.43.0:open_telemetry_opentelemetry_go_sdk \
		open-telemetry:opentelemetry-go:trace/v1.43.0:open_telemetry_opentelemetry_go_trace \
		open-telemetry:opentelemetry-go:v1.43.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		open-telemetry:opentelemetry-proto-go:otlp/v1.10.0:open_telemetry_opentelemetry_proto_go_otlp/vendor/go.opentelemetry.io/proto \
		openbao:openbao:api/v2.5.1:openbao_openbao_v2 \
		opencontainers:cgroups:v0.0.6:opencontainers_cgroups/vendor/github.com/opencontainers/cgroups \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.1.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runtime-spec:v1.3.0:opencontainers_runtime_spec/vendor/github.com/opencontainers/runtime-spec \
		openzipkin:zipkin-go:v0.4.3:openzipkin_zipkin_go/vendor/github.com/openzipkin/zipkin-go \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		peterhellberg:link:v1.2.0:peterhellberg_link/vendor/github.com/peterhellberg/link \
		petermattis:goid:df67b199bc81:petermattis_goid/vendor/github.com/petermattis/goid \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:term:1a4a3b719465:pkg_term/vendor/github.com/pkg/term \
		pmezard:go-difflib:5d4384ee4fb2:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.23.2:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.6.2:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.67.5:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.20.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:f2248ac996af:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		racksec:srslog:a4725f04ec91:racksec_srslog/vendor/github.com/racksec/srslog \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		russellhaering:goxmldsig:v1.6.0:russellhaering_goxmldsig/vendor/github.com/russellhaering/goxmldsig \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		sahilm:fuzzy:v0.1.1:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		sasha-s:go-deadlock:v0.3.9:sasha_s_go_deadlock/vendor/github.com/sasha-s/go-deadlock \
		shopspring:decimal:v1.4.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		sirupsen:logrus:v1.9.4:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		skratchdot:open-golang:eef842397966:skratchdot_open_golang/vendor/github.com/skratchdot/open-golang \
		smallstep:crypto:v0.67.0:smallstep_crypto/vendor/go.step.sm/crypto \
		spf13:cast:v1.10.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:pflag:v1.0.10:spf13_pflag/vendor/github.com/spf13/pflag \
		square:certstrap:v1.3.0:square_certstrap/vendor/github.com/square/certstrap \
		stretchr:testify:v1.11.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tedsuo:ifrit:846868129986:tedsuo_ifrit/vendor/github.com/tedsuo/ifrit \
		tedsuo:rata:07d200713958:tedsuo_rata/vendor/github.com/tedsuo/rata \
		txn2:txeh:v1.8.0:txn2_txeh/vendor/github.com/txn2/txeh \
		vbauerster:mpb:v8.12.0:vbauerster_mpb_v8/vendor/github.com/vbauerster/mpb/v8 \
		vito:go-sse:v1.1.3:vito_go_sse/vendor/github.com/vito/go-sse \
		vito:twentythousandtonnesofcrudeoil:3b21ad808fcb:vito_twentythousandtonnesofcrudeoil/vendor/github.com/vito/twentythousandtonnesofcrudeoil \
		x448:float16:v0.8.4:x448_float16/vendor/github.com/x448/float16 \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo \
		yaml:go-yaml:v2.4.4:yaml_go_yaml/vendor/go.yaml.in/yaml/v2 \
		yaml:go-yaml:v3.0.4:yaml_go_yaml_1/vendor/go.yaml.in/yaml/v3 \
		zalando:go-keyring:v0.2.8:zalando_go_keyring/vendor/github.com/zalando/go-keyring

GO_TARGET=	./cmd/concourse \
		./fly

post-extract:
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor/modules.txt
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/auth/oauth2adapt
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_oauth2adapt}/auth/oauth2adapt ${WRKSRC}/vendor/cloud.google.com/go/auth/oauth2adapt
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/compute/metadata
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_metadata}/compute/metadata ${WRKSRC}/vendor/cloud.google.com/go/compute/metadata
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/logging
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_logging}/logging ${WRKSRC}/vendor/cloud.google.com/go/logging
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/longrunning
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_longrunning}/longrunning ${WRKSRC}/vendor/cloud.google.com/go/longrunning
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/monitoring
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_monitoring}/monitoring ${WRKSRC}/vendor/cloud.google.com/go/monitoring
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/trace
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_trace}/trace ${WRKSRC}/vendor/cloud.google.com/go/trace
	@${RM} -r ${WRKSRC}/vendor/github.com/GoogleCloudPlatform/opentelemetry-operations-go/internal/resourcemapping
	@${RLN} ${WRKSRC_googlecloudplatform_opentelemetry_operations_go_resourcemapping}/internal/resourcemapping ${WRKSRC}/vendor/github.com/GoogleCloudPlatform/opentelemetry-operations-go/internal/resourcemapping
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/config
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_config}/config ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/config
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/credentials
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_credentials}/credentials ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/credentials
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/feature/ec2/imds
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_imds}/feature/ec2/imds ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/feature/ec2/imds
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/internal/configsources
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_configsources}/internal/configsources ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/internal/configsources
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/internal/endpoints/v2
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_v2}/internal/endpoints/v2 ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/internal/endpoints/v2
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/internal/v4a
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_v4a}/internal/v4a ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/internal/v4a
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/internal/accept-encoding
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_accept_encoding}/service/internal/accept-encoding ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/internal/accept-encoding
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/internal/presigned-url
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_presigned_url}/service/internal/presigned-url ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/internal/presigned-url
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/secretsmanager
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_secretsmanager}/service/secretsmanager ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/secretsmanager
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/signin
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_signin}/service/signin ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/signin
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/ssm
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_ssm}/service/ssm ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/ssm
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/sso
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_sso}/service/sso ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/sso
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/ssooidc
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_ssooidc}/service/ssooidc ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/ssooidc
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/sts
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_sts}/service/sts ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/sts
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/ansi
	@${RLN} ${WRKSRC_charmbracelet_x_ansi}/ansi ${WRKSRC}/vendor/github.com/charmbracelet/x/ansi
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/termios
	@${RLN} ${WRKSRC_charmbracelet_x_termios}/termios ${WRKSRC}/vendor/github.com/charmbracelet/x/termios
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/windows
	@${RLN} ${WRKSRC_charmbracelet_x_windows}/windows ${WRKSRC}/vendor/github.com/charmbracelet/x/windows
	@${RM} -r ${WRKSRC}/vendor/github.com/containerd/errdefs/pkg
	@${RLN} ${WRKSRC_containerd_errdefs_pkg}/pkg ${WRKSRC}/vendor/github.com/containerd/errdefs/pkg
	@${RM} -r ${WRKSRC}/vendor/github.com/go-openapi/swag/cmdutils
	@${RLN} ${WRKSRC_go_openapi_swag_cmdutils}/cmdutils ${WRKSRC}/vendor/github.com/go-openapi/swag/cmdutils
	@${RM} -r ${WRKSRC}/vendor/github.com/go-openapi/swag/conv
	@${RLN} ${WRKSRC_go_openapi_swag_conv}/conv ${WRKSRC}/vendor/github.com/go-openapi/swag/conv
	@${RM} -r ${WRKSRC}/vendor/github.com/go-openapi/swag/fileutils
	@${RLN} ${WRKSRC_go_openapi_swag_fileutils}/fileutils ${WRKSRC}/vendor/github.com/go-openapi/swag/fileutils
	@${RM} -r ${WRKSRC}/vendor/github.com/go-openapi/swag/jsonname
	@${RLN} ${WRKSRC_go_openapi_swag_jsonname}/jsonname ${WRKSRC}/vendor/github.com/go-openapi/swag/jsonname
	@${RM} -r ${WRKSRC}/vendor/github.com/go-openapi/swag/jsonutils
	@${RLN} ${WRKSRC_go_openapi_swag_jsonutils}/jsonutils ${WRKSRC}/vendor/github.com/go-openapi/swag/jsonutils
	@${RM} -r ${WRKSRC}/vendor/github.com/go-openapi/swag/loading
	@${RLN} ${WRKSRC_go_openapi_swag_loading}/loading ${WRKSRC}/vendor/github.com/go-openapi/swag/loading
	@${RM} -r ${WRKSRC}/vendor/github.com/go-openapi/swag/mangling
	@${RLN} ${WRKSRC_go_openapi_swag_mangling}/mangling ${WRKSRC}/vendor/github.com/go-openapi/swag/mangling
	@${RM} -r ${WRKSRC}/vendor/github.com/go-openapi/swag/netutils
	@${RLN} ${WRKSRC_go_openapi_swag_netutils}/netutils ${WRKSRC}/vendor/github.com/go-openapi/swag/netutils
	@${RM} -r ${WRKSRC}/vendor/github.com/go-openapi/swag/stringutils
	@${RLN} ${WRKSRC_go_openapi_swag_stringutils}/stringutils ${WRKSRC}/vendor/github.com/go-openapi/swag/stringutils
	@${RM} -r ${WRKSRC}/vendor/github.com/go-openapi/swag/typeutils
	@${RLN} ${WRKSRC_go_openapi_swag_typeutils}/typeutils ${WRKSRC}/vendor/github.com/go-openapi/swag/typeutils
	@${RM} -r ${WRKSRC}/vendor/github.com/go-openapi/swag/yamlutils
	@${RLN} ${WRKSRC_go_openapi_swag_yamlutils}/yamlutils ${WRKSRC}/vendor/github.com/go-openapi/swag/yamlutils
	@${RM} -r ${WRKSRC}/vendor/github.com/hashicorp/go-secure-stdlib/parseutil
	@${RLN} ${WRKSRC_hashicorp_go_secure_stdlib_parseutil}/parseutil ${WRKSRC}/vendor/github.com/hashicorp/go-secure-stdlib/parseutil
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/mountinfo
	@${RLN} ${WRKSRC_moby_sys_mountinfo}/mountinfo ${WRKSRC}/vendor/github.com/moby/sys/mountinfo
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/sequential
	@${RLN} ${WRKSRC_moby_sys_sequential}/sequential ${WRKSRC}/vendor/github.com/moby/sys/sequential
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/signal
	@${RLN} ${WRKSRC_moby_sys_signal}/signal ${WRKSRC}/vendor/github.com/moby/sys/signal
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/userns
	@${RLN} ${WRKSRC_moby_sys_userns}/userns ${WRKSRC}/vendor/github.com/moby/sys/userns
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/contrib/instrumentation/google.golang.org/grpc/otelgrpc
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_contrib_otelgrpc}/instrumentation/google.golang.org/grpc/otelgrpc ${WRKSRC}/vendor/go.opentelemetry.io/contrib/instrumentation/google.golang.org/grpc/otelgrpc
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/otel/exporters/jaeger
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_jaeger}/exporters/jaeger ${WRKSRC}/vendor/go.opentelemetry.io/otel/exporters/jaeger
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/otel/exporters/otlp/otlptrace
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_otlptrace}/exporters/otlp/otlptrace ${WRKSRC}/vendor/go.opentelemetry.io/otel/exporters/otlp/otlptrace
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/otel/exporters/otlp/otlptrace/otlptracegrpc
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_otlptracegrpc}/exporters/otlp/otlptrace/otlptracegrpc ${WRKSRC}/vendor/go.opentelemetry.io/otel/exporters/otlp/otlptrace/otlptracegrpc
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/otel/metric
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_metric}/metric ${WRKSRC}/vendor/go.opentelemetry.io/otel/metric
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/otel/sdk
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_sdk}/sdk ${WRKSRC}/vendor/go.opentelemetry.io/otel/sdk
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/otel/trace
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_trace}/trace ${WRKSRC}/vendor/go.opentelemetry.io/otel/trace

	@${MKDIR} ${WRKSRC}/vendor/github.com/openbao/openbao/api
	@${RLN} ${WRKSRC_openbao_openbao_v2}/api ${WRKSRC}/vendor/github.com/openbao/openbao/api/v2

PLIST_FILES=	bin/concourse \
	bin/fly

.include <bsd.port.mk>
