PORTNAME=	syft
DISTVERSIONPREFIX=	v
DISTVERSION=	1.42.2
CATEGORIES=	security devel

MAINTAINER=	youngbill.empire411@gmail.com
COMMENT=	CLI tool for generating SBOMs from container images and filesystems
WWW=		https://github.com/anchore/syft

LICENSE=	APACHE20

GO_WRKSRC=	${WRKSRC}

USES=		go:modules,1.25
USE_GITHUB=	yes
GH_ACCOUNT=	anchore
USE_GITLAB=	nodefault

GO_TARGET=	./cmd/syft
GO_BUILDFLAGS=	-ldflags="-s -w -X main.version=${DISTVERSION}"

PLIST_FILES=	bin/syft

GH_TUPLE=	\
		acarl005:stripansi:5a71ef0e047d:acarl005_stripansi/vendor/github.com/acarl005/stripansi \
		acobaugh:osrelease:v0.1.0:acobaugh_osrelease/vendor/github.com/acobaugh/osrelease \
		adrg:xdg:v0.5.3:adrg_xdg/vendor/github.com/adrg/xdg \
		agext:levenshtein:v1.2.1:agext_levenshtein/vendor/github.com/agext/levenshtein \
		anchore:bubbly:def0aba654a9:anchore_bubbly/vendor/github.com/anchore/bubbly \
		anchore:clio:2cfe4b0cb716:anchore_clio/vendor/github.com/anchore/clio \
		anchore:fangs:446a1e748ec2:anchore_fangs/vendor/github.com/anchore/fangs \
		anchore:go-collections:a3c352120e8c:anchore_go_collections/vendor/github.com/anchore/go-collections \
		anchore:go-homedir:c29668562e4d:anchore_go_homedir/vendor/github.com/anchore/go-homedir \
		anchore:go-logger:07ae343dd722:anchore_go_logger/vendor/github.com/anchore/go-logger \
		anchore:go-lzo:v0.1.0:anchore_go_lzo/vendor/github.com/anchore/go-lzo \
		anchore:go-macholibre:53e6d0aaf6fb:anchore_go_macholibre/vendor/github.com/anchore/go-macholibre \
		anchore:go-rpmdb:f77691e1faec:anchore_go_rpmdb/vendor/github.com/anchore/go-rpmdb \
		anchore:go-struct-converter:v0.1.0:anchore_go_struct_converter/vendor/github.com/anchore/go-struct-converter \
		anchore:go-sync:4eda43a485b6:anchore_go_sync/vendor/github.com/anchore/go-sync \
		anchore:go-version:18adb9c92b9b:anchore_go_version/vendor/github.com/anchore/go-version \
		anchore:packageurl-go:d62adb6e1115:anchore_packageurl_go/vendor/github.com/anchore/packageurl-go \
		anchore:stereoscope:v0.1.21:anchore_stereoscope/vendor/github.com/anchore/stereoscope \
		andybalholm:brotli:v1.2.0:andybalholm_brotli/vendor/github.com/andybalholm/brotli \
		anmitsu:go-shlex:38f4b401e2be:anmitsu_go_shlex/vendor/github.com/anmitsu/go-shlex \
		apparentlymart:go-textseg:v15.0.0:apparentlymart_go_textseg_v15/vendor/github.com/apparentlymart/go-textseg/v15 \
		aquasecurity:go-pep440-version:v0.0.1:aquasecurity_go_pep440_version/vendor/github.com/aquasecurity/go-pep440-version \
		aquasecurity:go-version:v0.0.1:aquasecurity_go_version/vendor/github.com/aquasecurity/go-version \
		atotto:clipboard:v0.1.4:atotto_clipboard/vendor/github.com/atotto/clipboard \
		aws:aws-sdk-go-v2:v1.41.2:aws_aws_sdk_go_v2/vendor/github.com/aws/aws-sdk-go-v2 \
		aws:smithy-go:v1.24.1:aws_smithy_go/vendor/github.com/aws/smithy-go \
		aymanbagabas:go-osc52:v2.0.1:aymanbagabas_go_osc52_v2/vendor/github.com/aymanbagabas/go-osc52/v2 \
		bahlo:generic-list-go:v0.2.0:bahlo_generic_list_go/vendor/github.com/bahlo/generic-list-go \
		becheran:wildmatch-go:v1.0.0:becheran_wildmatch_go/vendor/github.com/becheran/wildmatch-go \
		bgentry:go-netrc:9fd32a8b3d3d:bgentry_go_netrc/vendor/github.com/bgentry/go-netrc \
		bitnami:go-version:b1f57a8634ef:bitnami_go_version/vendor/github.com/bitnami/go-version \
		blakesmith:ar:809d4375e1fb:blakesmith_ar/vendor/github.com/blakesmith/ar \
		bmatcuk:doublestar:v4.10.0:bmatcuk_doublestar_v4/vendor/github.com/bmatcuk/doublestar/v4 \
		bodgit:plumbing:v1.3.0:bodgit_plumbing/vendor/github.com/bodgit/plumbing \
		bodgit:sevenzip:v1.6.1:bodgit_sevenzip/vendor/github.com/bodgit/sevenzip \
		bodgit:windows:v1.0.1:bodgit_windows/vendor/github.com/bodgit/windows \
		buger:jsonparser:v1.1.1:buger_jsonparser/vendor/github.com/buger/jsonparser \
		BurntSushi:toml:v1.6.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		census-instrumentation:opencensus-go:v0.24.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		charmbracelet:bubbles:v1.0.0:charmbracelet_bubbles/vendor/github.com/charmbracelet/bubbles \
		charmbracelet:bubbletea:v1.3.10:charmbracelet_bubbletea/vendor/github.com/charmbracelet/bubbletea \
		charmbracelet:colorprofile:v0.4.1:charmbracelet_colorprofile/vendor/github.com/charmbracelet/colorprofile \
		charmbracelet:harmonica:v0.2.0:charmbracelet_harmonica/vendor/github.com/charmbracelet/harmonica \
		charmbracelet:lipgloss:v1.1.0:charmbracelet_lipgloss/vendor/github.com/charmbracelet/lipgloss \
		charmbracelet:x:ansi/v0.11.6:charmbracelet_x_ansi \
		charmbracelet:x:cellbuf/v0.0.15:charmbracelet_x_cellbuf \
		charmbracelet:x:term/v0.2.2:charmbracelet_x_term/vendor/github.com/charmbracelet/x \
		clipperhouse:displaywidth:v0.9.0:clipperhouse_displaywidth/vendor/github.com/clipperhouse/displaywidth \
		clipperhouse:stringish:v0.1.1:clipperhouse_stringish/vendor/github.com/clipperhouse/stringish \
		clipperhouse:uax29:v2.5.0:clipperhouse_uax29_v2/vendor/github.com/clipperhouse/uax29/v2 \
		cloudflare:circl:v1.6.3:cloudflare_circl/vendor/github.com/cloudflare/circl \
		cncf:xds:2ac532fd4443:cncf_xds_go/vendor/github.com/cncf/xds \
		containerd:cgroups:v3.1.2:containerd_cgroups_v3/vendor/github.com/containerd/cgroups/v3 \
		containerd:containerd:api/v1.10.0:containerd_containerd_api/vendor/github.com/containerd/containerd \
		containerd:containerd:v2.2.1:containerd_containerd_v2/vendor/github.com/containerd/containerd/v2 \
		containerd:continuity:v0.4.5:containerd_continuity/vendor/github.com/containerd/continuity \
		containerd:errdefs:v0.3.0:containerd_errdefs_pkg/vendor/github.com/containerd/errdefs \
		containerd:errdefs:v1.0.0:containerd_errdefs \
		containerd:fifo:v1.1.0:containerd_fifo/vendor/github.com/containerd/fifo \
		containerd:log:v0.1.0:containerd_log/vendor/github.com/containerd/log \
		containerd:platforms:v1.0.0-rc.2:containerd_platforms/vendor/github.com/containerd/platforms \
		containerd:plugin:v1.0.0:containerd_plugin/vendor/github.com/containerd/plugin \
		containerd:stargz-snapshotter:v0.18.2:containerd_stargz_snapshotter_estargz/vendor/github.com/containerd/stargz-snapshotter \
		containerd:ttrpc:v1.2.7:containerd_ttrpc/vendor/github.com/containerd/ttrpc \
		containerd:typeurl:v2.2.3:containerd_typeurl_v2/vendor/github.com/containerd/typeurl/v2 \
		CycloneDX:cyclonedx-go:v0.10.0:cyclonedx_cyclonedx_go/vendor/github.com/CycloneDX/cyclonedx-go \
		cyphar:filepath-securejoin:v0.6.0:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		cyphar:libpathrs:go-pathrs/v0.2.1:cyphar_go_pathrs \
		DataDog:zstd:v1.5.5:datadog_zstd/vendor/github.com/DataDog/zstd \
		dave:jennifer:v1.7.1:dave_jennifer/vendor/github.com/dave/jennifer \
		davecgh:go-spew:d8f796af33cc:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deitch:magic:1ff89d7342da:deitch_magic/vendor/github.com/deitch/magic \
		diskfs:go-diskfs:v1.7.0:diskfs_go_diskfs/vendor/github.com/diskfs/go-diskfs \
		distribution:reference:v0.6.0:distribution_reference/vendor/github.com/distribution/reference \
		docker:cli:v29.2.1:docker_cli/vendor/github.com/docker/cli \
		docker:distribution:v2.8.3:docker_distribution/vendor/github.com/docker/distribution \
		docker:docker-credential-helpers:v0.9.5:docker_docker_credential_helpers/vendor/github.com/docker/docker-credential-helpers \
		docker:go-connections:v0.6.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.5.0:docker_go_units/vendor/github.com/docker/go-units \
		dsnet:compress:39efe44ab707:dsnet_compress/vendor/github.com/dsnet/compress \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		elliotchance:phpserialize:v1.4.0:elliotchance_phpserialize/vendor/github.com/elliotchance/phpserialize \
		emirpasic:gods:v1.18.1:emirpasic_gods/vendor/github.com/emirpasic/gods \
		envoyproxy:go-control-plane:envoy/v1.32.4:envoyproxy_go_control_plane_envoy/vendor/github.com/envoyproxy/go-control-plane \
		envoyproxy:protoc-gen-validate:v1.2.1:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		erikgeiser:coninput:1c3628e74d0f:erikgeiser_coninput/vendor/github.com/erikgeiser/coninput \
		facebookincubator:nvdtools:v0.1.5:facebookincubator_nvdtools/vendor/github.com/facebookincubator/nvdtools \
		fatih:color:v1.18.0:fatih_color/vendor/github.com/fatih/color \
		felixge:fgprof:v0.9.5:felixge_fgprof/vendor/github.com/felixge/fgprof \
		felixge:httpsnoop:v1.0.4:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		fsnotify:fsnotify:v1.9.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gabriel-vasile:mimetype:v1.4.13:gabriel_vasile_mimetype/vendor/github.com/gabriel-vasile/mimetype \
		github:go-spdx:v2.4.0:github_go_spdx_v2/vendor/github.com/github/go-spdx/v2 \
		gkampitakis:ciinfo:v0.3.2:gkampitakis_ciinfo/vendor/github.com/gkampitakis/ciinfo \
		gkampitakis:go-snaps:v0.5.20:gkampitakis_go_snaps/vendor/github.com/gkampitakis/go-snaps \
		go-git:gcfg:3a3c6141e376:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.8.0:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.17.0:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-jose:go-jose:v4.1.2:go_jose_go_jose_v4/vendor/github.com/go-jose/go-jose/v4 \
		go-logr:logr:v1.4.3:go_logr_logr/vendor/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/vendor/github.com/go-logr/stdr \
		go-restruct:restruct:v1.2.0-alpha:go_restruct_restruct/vendor/github.com/go-restruct/restruct \
		go-test:deep:v1.1.1:go_test_deep/vendor/github.com/go-test/deep \
		go-viper:mapstructure:v2.5.0:go_viper_mapstructure_v2/vendor/github.com/go-viper/mapstructure/v2 \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		go4org:go4:214862532bf5:go4org_go4/vendor/go4.org \
		goccy:go-yaml:v1.19.2:goccy_go_yaml/vendor/github.com/goccy/go-yaml \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		gohugoio:hashstructure:v0.6.0:gohugoio_hashstructure/vendor/github.com/gohugoio/hashstructure \
		golang:crypto:v0.48.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:a4bb9ffd2546:golang_exp/vendor/golang.org/x/exp \
		golang:groupcache:2c02b8208cf8:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:mod:v0.33.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.51.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.35.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sync:v0.19.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.41.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.40.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.34.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.14.0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.42.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:104605ab7028:golang_xerrors/vendor/golang.org/x/xerrors \
		gonum:gonum:v0.16.0:gonum_gonum/vendor/gonum.org/v1/gonum \
		google:cel-spec:v0.24.0:google_cel_spec/vendor/cel.dev/expr \
		google:go-cmp:v0.7.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-containerregistry:v0.21.1:google_go_containerregistry/vendor/github.com/google/go-containerregistry \
		google:go-genproto:9219d122eba9:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-genproto:95abcf5c77ba:google_go_genproto_1/vendor/google.golang.org/genproto/googleapis/api \
		google:go-genproto:95abcf5c77ba:google_go_genproto_2/vendor/google.golang.org/genproto/googleapis/rpc \
		google:licensecheck:v0.3.1:google_licensecheck/vendor/github.com/google/licensecheck \
		google:pprof:a4b03ec1a45e:google_pprof/vendor/github.com/google/pprof \
		google:s2a-go:v0.1.9:google_s2a_go/vendor/github.com/google/s2a-go \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:enterprise-certificate-proxy:v0.3.7:googleapis_enterprise_certificate_proxy/vendor/github.com/googleapis/enterprise-certificate-proxy \
		googleapis:gax-go:v2.15.0:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.256.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:auth/oauth2adapt/v0.2.8:googleapis_google_cloud_go_1/vendor/cloud.google.com/go/auth/oauth2adapt \
		googleapis:google-cloud-go:compute/metadata/v0.9.0:googleapis_google_cloud_go_2/vendor/cloud.google.com/go/compute/metadata \
		googleapis:google-cloud-go:iam/v1.5.3:googleapis_google_cloud_go_iam \
		googleapis:google-cloud-go:monitoring/v1.24.2:googleapis_google_cloud_go_monitoring \
		googleapis:google-cloud-go:storage/v1.58.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.123.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		googleapis:google-cloud-go:v0.17.0:googleapis_google_cloud_go_auth/vendor/cloud.google.com/go/auth \
		GoogleCloudPlatform:opentelemetry-operations-go:214376d00c74:googlecloudplatform_opentelemetry_operations_go_gcp \
		GoogleCloudPlatform:opentelemetry-operations-go:v0.54.0:googlecloudplatform_opentelemetry_operations_go_metric/vendor/github.com/GoogleCloudPlatform/opentelemetry-operations-go \
		gookit:color:v1.6.0:gookit_color/vendor/github.com/gookit/color \
		gpustack:gguf-parser-go:v0.24.0:gpustack_gguf_parser_go/vendor/github.com/gpustack/gguf-parser-go \
		grpc:grpc-go:v1.76.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:aws-sdk-go-base:v2.0.0-beta.70:hashicorp_aws_sdk_go_base_v2/vendor/github.com/hashicorp/aws-sdk-go-base/v2 \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.2:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-getter:v1.8.4:hashicorp_go_getter/vendor/github.com/hashicorp/go-getter \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-version:v1.8.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:golang-lru:v2.0.7:hashicorp_golang_lru_v2/vendor/github.com/hashicorp/golang-lru/v2 \
		hashicorp:hcl:v2.24.0:hashicorp_hcl_v2/vendor/github.com/hashicorp/hcl/v2 \
		henvic:httpretty:v0.1.4:henvic_httpretty/vendor/github.com/henvic/httpretty \
		huandu:xstrings:v1.5.0:huandu_xstrings/vendor/github.com/huandu/xstrings \
		iancoleman:strcase:v0.3.0:iancoleman_strcase/vendor/github.com/iancoleman/strcase \
		imdario:mergo:v1.0.2:imdario_mergo/vendor/dario.cat/mergo \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		invopop:jsonschema:v0.13.0:invopop_jsonschema/vendor/github.com/invopop/jsonschema \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		jedib0t:go-pretty:v6.7.8:jedib0t_go_pretty_v6/vendor/github.com/jedib0t/go-pretty/v6 \
		jinzhu:copier:v0.4.0:jinzhu_copier/vendor/github.com/jinzhu/copier \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		kastenhq:goversion:93b2f8823953:kastenhq_goversion/vendor/github.com/kastenhq/goversion \
		kevinburke:ssh_config:v1.2.0:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		klauspost:compress:v1.18.4:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:pgzip:v1.2.6:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		lucasb-eyer:go-colorful:v1.3.0:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		magiconair:properties:v1.8.10:magiconair_properties/vendor/github.com/magiconair/properties \
		mailru:easyjson:v0.7.7:mailru_easyjson/vendor/github.com/mailru/easyjson \
		maruel:natural:v1.1.1:maruel_natural/vendor/github.com/maruel/natural \
		Masterminds:goutils:v1.1.1:masterminds_goutils/vendor/github.com/Masterminds/goutils \
		Masterminds:semver:v3.4.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:sprig:v3.3.0:masterminds_sprig_v3/vendor/github.com/Masterminds/sprig/v3 \
		mattn:go-colorable:v0.1.14:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-localereader:2491eb6c1c75:mattn_go_localereader/vendor/github.com/mattn/go-localereader \
		mattn:go-runewidth:v0.0.19:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		mholt:archives:v0.1.5:mholt_archives/vendor/github.com/mholt/archives \
		Microsoft:go-winio:v0.6.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.14.0-rc.1:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		mikelolasagasti:xz:v1.0.1:mikelolasagasti_xz/vendor/github.com/mikelolasagasti/xz \
		minio:minlz:v1.0.1:minio_minlz/vendor/github.com/minio/minlz \
		mitchellh:copystructure:v1.2.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-wordwrap:v1.0.1:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:reflectwalk:v1.0.2:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		moby:docker-image-spec:v1.3.1:moby_docker_image_spec/vendor/github.com/moby/docker-image-spec \
		moby:locker:v1.0.1:moby_locker/vendor/github.com/moby/locker \
		moby:moby:api/v1.53.0:moby_moby_api/vendor/github.com/moby/moby \
		moby:moby:client/v0.2.2:moby_moby_client \
		moby:sys:mountinfo/v0.7.2:moby_sys_mountinfo \
		moby:sys:sequential/v0.6.0:moby_sys_sequential \
		moby:sys:signal/v0.7.1:moby_sys_signal \
		moby:sys:user/v0.4.0:moby_sys_user/vendor/github.com/moby/sys \
		moby:sys:userns/v0.1.0:moby_sys_userns \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:35a7c28c31ee:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		muesli:ansi:276c6243b2f6:muesli_ansi/vendor/github.com/muesli/ansi \
		muesli:cancelreader:v0.2.2:muesli_cancelreader/vendor/github.com/muesli/cancelreader \
		muesli:termenv:v0.16.0:muesli_termenv/vendor/github.com/muesli/termenv \
		ncruces:go-strftime:v1.0.0:ncruces_go_strftime/vendor/github.com/ncruces/go-strftime \
		nix-community:go-nix:4bdde671e0a1:nix_community_go_nix/vendor/github.com/nix-community/go-nix \
		nwaples:rardecode:v2.2.0:nwaples_rardecode_v2/vendor/github.com/nwaples/rardecode/v2 \
		olekukonko:cat:50322a0618f6:olekukonko_cat/vendor/github.com/olekukonko/cat \
		olekukonko:errors:v1.1.0:olekukonko_errors/vendor/github.com/olekukonko/errors \
		olekukonko:ll:9e59c2286df0:olekukonko_ll/vendor/github.com/olekukonko/ll \
		olekukonko:tablewriter:v1.1.3:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		OneOfOne:xxhash:v1.2.8:oneofone_xxhash/vendor/github.com/OneOfOne/xxhash \
		open-telemetry:opentelemetry-go-contrib:detectors/gcp/v1.36.0:open_telemetry_opentelemetry_go_contrib/vendor/go.opentelemetry.io/contrib \
		open-telemetry:opentelemetry-go-contrib:instrumentation/google.golang.org/grpc/otelgrpc/v0.63.0:open_telemetry_opentelemetry_go_contrib_1 \
		open-telemetry:opentelemetry-go-contrib:instrumentation/net/http/otelhttp/v0.61.0:open_telemetry_opentelemetry_go_contrib_2 \
		open-telemetry:opentelemetry-go-instrumentation:sdk/v1.2.1:open_telemetry_opentelemetry_go_instrumentation \
		open-telemetry:opentelemetry-go:v1.40.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.1.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runtime-spec:v1.3.0:opencontainers_runtime_spec/vendor/github.com/opencontainers/runtime-spec \
		opencontainers:selinux:v1.13.1:opencontainers_selinux/vendor/github.com/opencontainers/selinux \
		pborman:indent:v1.2.1:pborman_indent/vendor/github.com/pborman/indent \
		pelletier:go-toml:v1.9.5:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pelletier:go-toml:v2.2.4:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		pierrec:lz4:v4.1.22:pierrec_lz4_v4/vendor/github.com/pierrec/lz4/v4 \
		pjbgf:sha1cd:v0.3.2:pjbgf_sha1cd/vendor/github.com/pjbgf/sha1cd \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:v1.7.0:pkg_profile/vendor/github.com/pkg/profile \
		pkg:xattr:v0.4.9:pkg_xattr/vendor/github.com/pkg/xattr \
		planetscale:vtprotobuf:0393e58bdf10:planetscale_vtprotobuf/vendor/github.com/planetscale/vtprotobuf \
		pmezard:go-difflib:5d4384ee4fb2:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.36.11:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		ProtonMail:go-crypto:v1.3.0:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		quasilyte:go-ruleguard:dsl/v0.3.23:quasilyte_go_ruleguard_dsl/vendor/github.com/quasilyte/go-ruleguard \
		remyoudompheng:bigfft:24d4a6f8daec:remyoudompheng_bigfft/vendor/github.com/remyoudompheng/bigfft \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rogpeppe:go-internal:v1.14.1:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		rust-secure-code:go-rustaudit:e20ec32e963c:rust_secure_code_go_rustaudit/vendor/github.com/rust-secure-code/go-rustaudit \
		sagikazarmark:locafero:v0.7.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sahilm:fuzzy:v0.1.1:sahilm_fuzzy/vendor/github.com/sahilm/fuzzy \
		saintfish:chardet:5e3ef4b5456d:saintfish_chardet/vendor/github.com/saintfish/chardet \
		sanity-io:litter:v1.5.8:sanity_io_litter/vendor/github.com/sanity-io/litter \
		sassoftware:go-rpmutils:v0.4.0:sassoftware_go_rpmutils/vendor/github.com/sassoftware/go-rpmutils \
		scylladb:go-set:cc7b2070d91e:scylladb_go_set/vendor/github.com/scylladb/go-set \
		sergi:go-diff:v1.4.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shopspring:decimal:v1.4.0:shopspring_decimal/vendor/github.com/shopspring/decimal \
		sirupsen:logrus:v1.9.4:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		skeema:knownhosts:v1.3.1:skeema_knownhosts/vendor/github.com/skeema/knownhosts \
		smallnest:ringbuffer:461381446e3d:smallnest_ringbuffer/vendor/github.com/smallnest/ringbuffer \
		sorairolake:lzip-go:v0.3.8:sorairolake_lzip_go/vendor/github.com/sorairolake/lzip-go \
		sourcegraph:conc:v0.3.0:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spdx:gordf:7098f93598fb:spdx_gordf/vendor/github.com/spdx/gordf \
		spdx:tools-golang:v0.5.7:spdx_tools_golang/vendor/github.com/spdx/tools-golang \
		spf13:afero:v1.15.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.7.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.10.2:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.10:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.20.0:spf13_viper/vendor/github.com/spf13/viper \
		spiffe:go-spiffe:v2.5.0:spiffe_go_spiffe_v2/vendor/github.com/spiffe/go-spiffe \
		STARRY-S:zip:v0.2.3:starry_s_zip/vendor/github.com/STARRY-S/zip \
		stretchr:objx:v0.5.2:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.11.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		sylabs:sif:v2.23.0:sylabs_sif_v2/vendor/github.com/sylabs/sif/v2 \
		sylabs:squashfs:v1.0.6:sylabs_squashfs/vendor/github.com/sylabs/squashfs \
		therootcompany:xz:v1.0.1:therootcompany_xz \
		tidwall:gjson:v1.18.0:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.1:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tidwall:sjson:v1.2.5:tidwall_sjson/vendor/github.com/tidwall/sjson \
		uber-go:goleak:v1.3.0:uber_go_goleak/vendor/go.uber.org/goleak \
		ulikunitz:xz:v0.5.15:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		vbatts:go-mtree:v0.7.0:vbatts_go_mtree/vendor/github.com/vbatts/go-mtree \
		vbatts:tar-split:v0.12.2:vbatts_tar_split/vendor/github.com/vbatts/tar-split \
		vifraa:gopom:v1.0.0:vifraa_gopom/vendor/github.com/vifraa/gopom \
		wagoodman:go-partybus:8ccac152c651:wagoodman_go_partybus/vendor/github.com/wagoodman/go-partybus \
		wagoodman:go-progress:10176f79b2c0:wagoodman_go_progress/vendor/github.com/wagoodman/go-progress \
		wk8:go-ordered-map:v2.1.8:wk8_go_ordered_map_v2/vendor/github.com/wk8/go-ordered-map/v2 \
		xanzy:ssh-agent:v0.3.3:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent \
		xeipuuv:gojsonpointer:02993c407bfb:xeipuuv_gojsonpointer/vendor/github.com/xeipuuv/gojsonpointer \
		xeipuuv:gojsonreference:bd5ef7bd5415:xeipuuv_gojsonreference/vendor/github.com/xeipuuv/gojsonreference \
		xeipuuv:gojsonschema:v1.2.0:xeipuuv_gojsonschema/vendor/github.com/xeipuuv/gojsonschema \
		xi2:xz:48954b6210f8:xi2_xz/vendor/github.com/xi2/xz \
		xo:terminfo:abceb7e1c41e:xo_terminfo/vendor/github.com/xo/terminfo \
		yaml:go-yaml:v3.0.4:yaml_go_yaml/vendor/go.yaml.in/yaml/v3 \
		zclconf:go-cty:v1.16.3:zclconf_go_cty/vendor/github.com/zclconf/go-cty \
		zeebo:errs:v1.4.0:zeebo_errs/vendor/github.com/zeebo/errs \
		zyedidia:generic:4410d2372cb1:zyedidia_generic/vendor/github.com/zyedidia/generic

GL_TUPLE=	cznic:libc:v1.67.6:cznic_libc/vendor/modernc.org/libc \
		cznic:mathutil:v1.7.1:cznic_mathutil/vendor/modernc.org/mathutil \
		cznic:memory:v1.11.0:cznic_memory/vendor/modernc.org/memory \
		cznic:sqlite:v1.46.1:cznic_sqlite/vendor/modernc.org/sqlite

post-extract:
	@${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor/modules.txt
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/iam
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_iam}/iam ${WRKSRC}/vendor/cloud.google.com/go/iam
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/monitoring
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_monitoring}/monitoring ${WRKSRC}/vendor/cloud.google.com/go/monitoring
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/GoogleCloudPlatform/opentelemetry-operations-go/detectors/gcp
	@${RLN} ${WRKSRC_googlecloudplatform_opentelemetry_operations_go_gcp}/detectors/gcp ${WRKSRC}/vendor/github.com/GoogleCloudPlatform/opentelemetry-operations-go/detectors/gcp
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/ansi
	@${RLN} ${WRKSRC_charmbracelet_x_ansi}/ansi ${WRKSRC}/vendor/github.com/charmbracelet/x/ansi
	@${RM} -r ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf
	@${RLN} ${WRKSRC_charmbracelet_x_cellbuf}/cellbuf ${WRKSRC}/vendor/github.com/charmbracelet/x/cellbuf
	@${RLN} ${WRKSRC_containerd_errdefs} ${WRKSRC}/vendor/github.com/containerd/errdefs
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/mountinfo
	@${RLN} ${WRKSRC_moby_sys_mountinfo}/mountinfo ${WRKSRC}/vendor/github.com/moby/sys/mountinfo
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/sequential
	@${RLN} ${WRKSRC_moby_sys_sequential}/sequential ${WRKSRC}/vendor/github.com/moby/sys/sequential
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/signal
	@${RLN} ${WRKSRC_moby_sys_signal}/signal ${WRKSRC}/vendor/github.com/moby/sys/signal
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/userns
	@${RLN} ${WRKSRC_moby_sys_userns}/userns ${WRKSRC}/vendor/github.com/moby/sys/userns
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/contrib/instrumentation/net/http/otelhttp
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_contrib_2}/instrumentation/net/http/otelhttp ${WRKSRC}/vendor/go.opentelemetry.io/contrib/instrumentation/net/http/otelhttp
	@${RM} -r ${WRKSRC}/vendor/go.opentelemetry.io/contrib/instrumentation/google.golang.org/grpc/otelgrpc
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_contrib_1}/instrumentation/google.golang.org/grpc/otelgrpc ${WRKSRC}/vendor/go.opentelemetry.io/contrib/instrumentation/google.golang.org/grpc/otelgrpc
	@${MKDIR} ${WRKSRC}/vendor/go.opentelemetry.io/auto
	@${RLN} ${WRKSRC_open_telemetry_opentelemetry_go_instrumentation}/sdk ${WRKSRC}/vendor/go.opentelemetry.io/auto/sdk
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/moby/client
	@${RLN} ${WRKSRC_moby_moby_client}/client ${WRKSRC}/vendor/github.com/moby/moby/client
	@${MKDIR} ${WRKSRC}/vendor/cyphar.com
	@${RLN} ${WRKSRC_cyphar_go_pathrs}/go-pathrs ${WRKSRC}/vendor/cyphar.com/go-pathrs
	@${MKDIR} ${WRKSRC}/vendor/github.com/therootcompany
	@${RLN} ${WRKSRC_mikelolasagasti_xz} ${WRKSRC}/vendor/github.com/therootcompany/xz
	@${MKDIR} ${WRKSRC}/vendor/go.uber.org
	@${RLN} ${WRKSRC_fsnotify_fsnotify} ${WRKSRC}/vendor/go.uber.org/atomic
	@${RLN} ${WRKSRC_fsnotify_fsnotify} ${WRKSRC}/vendor/go.uber.org/multierr

.include <bsd.port.mk>
