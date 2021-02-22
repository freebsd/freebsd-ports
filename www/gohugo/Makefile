# $FreeBSD$

PORTNAME=	hugo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.81.0
CATEGORIES=	www
PKGNAMEPREFIX=	go
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	ben.lavery@hashbang0.com
COMMENT=	Fast and flexible static site generator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	gohugoio
GH_TUPLE=	\
		Azure:azure-pipeline-go:v0.2.2:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.9.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		BurntSushi:locker:a6e239ea1c69:burntsushi_locker/vendor/github.com/BurntSushi/locker \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		alecthomas:chroma:v0.8.2:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		aws:aws-sdk-go:v1.37.11:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		bep:debounce:v1.2.0:bep_debounce/vendor/github.com/bep/debounce \
		bep:gitmap:v1.1.2:bep_gitmap/vendor/github.com/bep/gitmap \
		bep:godartsass:v0.12.0:bep_godartsass/vendor/github.com/bep/godartsass \
		bep:golibsass:v0.7.0:bep_golibsass/vendor/github.com/bep/golibsass \
		bep:tmc:v0.5.1:bep_tmc/vendor/github.com/bep/tmc \
		census-instrumentation:opencensus-go:v0.22.5:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cli:safeexec:v1.0.0:cli_safeexec/vendor/github.com/cli/safeexec \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		disintegration:gift:v1.2.1:disintegration_gift/vendor/github.com/disintegration/gift \
		dlclark:regexp2:v1.4.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		evanw:esbuild:v0.8.46:evanw_esbuild/vendor/github.com/evanw/esbuild \
		fortytw2:leaktest:v1.3.0:fortytw2_leaktest/vendor/github.com/fortytw2/leaktest \
		frankban:quicktest:v1.11.3:frankban_quicktest/vendor/github.com/frankban/quicktest \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		getkin:kin-openapi:v0.39.0:getkin_kin_openapi/vendor/github.com/getkin/kin-openapi \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-ini:ini:v1.51.1:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-openapi:jsonpointer:v0.19.5:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:swag:v0.19.5:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:flect:v0.2.2:gobuffalo_flect/vendor/github.com/gobuffalo/flect \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gohugoio:testmodBuilder:c56af20f2e95:gohugoio_testmodbuilder_mods/vendor/github.com/gohugoio/testmodBuilder \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:image:9130b4cfad52:golang_image/vendor/golang.org/x/image \
		golang:lint:83fdc39ff7b5:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.4.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:6772e930b67b:golang_net/vendor/golang.org/x/net \
		golang:oauth2:08078c50e5b5:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:09787c993a3a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:6f8348627aad:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		golang:tools:b0ab187a4818:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cloud:v0.20.0:google_go_cloud/vendor/gocloud.dev \
		google:go-cmp:v0.5.4:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:8c77b98c765d:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		google:wire:v0.4.0:google_wire/vendor/github.com/google/wire \
		googleapis:gax-go:v2.0.2:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2 \
		googleapis:google-api-go-client:v0.40.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:storage/v1.10.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.74.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.34.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jdkato:prose:v1.2.0:jdkato_prose/vendor/github.com/jdkato/prose \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		kr:pretty:v0.2.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.1.0:kr_text/vendor/github.com/kr/text \
		kylelemons:godebug:v1.1.0:kylelemons_godebug/vendor/github.com/kylelemons/godebug \
		kyokomi:emoji:v2.2.7:kyokomi_emoji_v2/vendor/github.com/kyokomi/emoji/v2 \
		magefile:mage:v1.10.0:magefile_mage/vendor/github.com/magefile/mage \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mailru:easyjson:b2ccc519800e:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		miekg:mmark:v1.3.6:miekg_mmark/vendor/github.com/miekg/mmark \
		mitchellh:hashstructure:v1.0.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.3.3:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		muesli:smartcrop:v0.3.0:muesli_smartcrop/vendor/github.com/muesli/smartcrop \
		nicksnyder:go-i18n:v2.1.1:nicksnyder_go_i18n_v2/vendor/github.com/nicksnyder/go-i18n \
		niklasfasching:go-org:v1.4.0:niklasfasching_go_org/vendor/github.com/niklasfasching/go-org \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pelletier:go-toml:v1.8.1:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rogpeppe:go-internal:v1.6.2:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		russross:blackfriday:41c5fccfd6f6:russross_blackfriday/vendor/github.com/russross/blackfriday \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		rwcarlsen:goexif:9e8deecbddbd:rwcarlsen_goexif/vendor/github.com/rwcarlsen/goexif \
		sanity-io:litter:v1.5.0:sanity_io_litter/vendor/github.com/sanity-io/litter \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		spf13:afero:v1.5.1:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.1.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:fsync:v0.9.0:spf13_fsync/vendor/github.com/spf13/fsync \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.1:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tdewolff:minify:v2.9.13:tdewolff_minify_v2/vendor/github.com/tdewolff/minify/v2 \
		tdewolff:parse:v2.5.10:tdewolff_parse_v2/vendor/github.com/tdewolff/parse/v2 \
		yuin:goldmark-highlighting:60d527fdb691:yuin_goldmark_highlighting/vendor/github.com/yuin/goldmark-highlighting \
		yuin:goldmark:v1.3.2:yuin_goldmark/vendor/github.com/yuin/goldmark

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/googleapis/gax-go/v2
	@${RLN} ${WRKSRC_googleapis_gax_go_v2}/v2 ${WRKSRC}/vendor/github.com/googleapis/gax-go/v2

GO_BUILDFLAGS=	-ldflags="\
		-s -w \
		-X github.com/gohugoio/hugo/common/hugo.buildDate=${SOURCE_DATE_EPOCH:U${SOURCE_DATE_EPOCH_CMD:sh}} \
		-X github.com/gohugoio/hugo/common/hugo.commitHash=${COMMIT_ID}" \
		${BUILD_TAGS}

OPTIONS_DEFINE=		MANPAGES EXTENDED
OPTIONS_DEFAULT=	MANPAGES EXTENDED
OPTIONS_SUB=		yes

EXTENDED_DESC=		Enable SCSS/SASS support

EXTENDED_VARS=		CGO_ENABLED=1 BUILD_TAGS="-tags extended"
EXTENDED_VARS_OFF=	CGO_ENABLED=0

PORTMANS=	hugo-config.1 hugo-convert-toJSON.1 hugo-convert-toTOML.1 \
		hugo-convert-toYAML.1 hugo-convert.1 hugo-env.1 \
		hugo-gen-autocomplete.1 hugo-gen-chromastyles.1 \
		hugo-gen-doc.1 hugo-gen-man.1 hugo-gen.1 \
		hugo-import-jekyll.1 hugo-import.1 hugo-list-drafts.1 \
		hugo-list-expired.1 hugo-list-future.1 hugo-list.1 \
		hugo-new-site.1 hugo-new-theme.1 hugo-new.1 hugo-server.1 \
		hugo-version.1 hugo.1

# needed to get DISTINFO_FILE in scope for the shell command evaluation by go.mk
.include <bsd.port.pre.mk>

SOURCE_DATE_EPOCH_CMD=	date -r $$(grep TIMESTAMP ${DISTINFO_FILE} | ${SED} -e 's/[^0-9]//g') '+%FT%TZ%z'
COMMIT_ID=		59d15c97

do-build-MANPAGES-on:
	@cd ${GO_WRKSRC} && ${GO_WRKDIR_BIN}/${PORTNAME} gen man --dir man/man1/

do-install-MANPAGES-on:
.for i in ${PORTMANS}
	${INSTALL_MAN} ${WRKSRC}/man/man1/$i ${STAGEDIR}/${PREFIX}/man/man1
.endfor

.include <bsd.port.post.mk>
