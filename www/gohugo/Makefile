PORTNAME=	hugo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.92.0
CATEGORIES=	www
PKGNAMEPREFIX=	go
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	ben@lavery-griffiths.com
COMMENT=	Fast and Flexible Static Site Generator built with love in GoLang

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	gohugo
USE_GITHUB=	yes
GH_ACCOUNT=	gohugoio
GH_TUPLE=	\
		Azure:azure-pipeline-go:v0.2.2:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.9.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		BurntSushi:locker:a6e239ea1c69:burntsushi_locker/vendor/github.com/BurntSushi/locker \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		alecthomas:chroma:v0.9.4:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		aws:aws-sdk-go:v1.41.14:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		bep:debounce:v1.2.0:bep_debounce/vendor/github.com/bep/debounce \
		bep:gitmap:v1.1.2:bep_gitmap/vendor/github.com/bep/gitmap \
		bep:godartsass:v0.12.0:bep_godartsass/vendor/github.com/bep/godartsass \
		bep:golibsass:v1.0.0:bep_golibsass/vendor/github.com/bep/golibsass \
		bep:gowebp:v0.1.0:bep_gowebp/vendor/github.com/bep/gowebp \
		bep:tmc:v0.5.1:bep_tmc/vendor/github.com/bep/tmc \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		census-instrumentation:opencensus-proto:v0.2.1:census_instrumentation_opencensus_proto/vendor/github.com/census-instrumentation/opencensus-proto \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		clbanning:mxj:v2.5.5:clbanning_mxj_v2/vendor/github.com/clbanning/mxj/v2 \
		cli:safeexec:v1.0.0:cli_safeexec/vendor/github.com/cli/safeexec \
		cncf:udpa:5459f2c99403:cncf_udpa_go/vendor/github.com/cncf/udpa \
		cncf:xds:fbca930ec8ed:cncf_xds_go/vendor/github.com/cncf/xds \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		disintegration:gift:v1.2.1:disintegration_gift/vendor/github.com/disintegration/gift \
		dlclark:regexp2:v1.4.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		envoyproxy:go-control-plane:63b5d3c536b0:envoyproxy_go_control_plane/vendor/github.com/envoyproxy/go-control-plane \
		envoyproxy:protoc-gen-validate:v0.1.0:envoyproxy_protoc_gen_validate/vendor/github.com/envoyproxy/protoc-gen-validate \
		evanw:esbuild:v0.14.11:evanw_esbuild/vendor/github.com/evanw/esbuild \
		fortytw2:leaktest:v1.3.0:fortytw2_leaktest/vendor/github.com/fortytw2/leaktest \
		frankban:quicktest:v1.14.0:frankban_quicktest/vendor/github.com/frankban/quicktest \
		fsnotify:fsnotify:v1.5.1:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		getkin:kin-openapi:v0.85.0:getkin_kin_openapi/vendor/github.com/getkin/kin-openapi \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-check:check:41f04d3bba15:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.62.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-openapi:jsonpointer:v0.19.5:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:swag:v0.19.5:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:flect:v0.2.3:gobuffalo_flect/vendor/github.com/gobuffalo/flect \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gohugoio:go-i18n:4c28c89f8013:gohugoio_go_i18n_v2/vendor/github.com/gohugoio/go-i18n \
		gohugoio:locales:v0.14.0:gohugoio_locales/vendor/github.com/gohugoio/locales \
		gohugoio:localescompressed:v0.14.0:gohugoio_localescompressed/vendor/github.com/gohugoio/localescompressed \
		gohugoio:testmodBuilder:c56af20f2e95:gohugoio_testmodbuilder_mods/vendor/github.com/gohugoio/testmodBuilder \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:image:6944b10bf410:golang_image/vendor/golang.org/x/image \
		golang:net:04defd469f4e:golang_net/vendor/golang.org/x/net \
		golang:oauth2:d3ed0bb246c8:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:fe61309f8881:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cloud:v0.20.0:google_go_cloud/vendor/gocloud.dev \
		google:go-cmp:v0.5.6:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:81c1377c94b1:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		google:wire:v0.4.0:google_wire/vendor/github.com/google/wire \
		googleapis:gax-go:v2.0.2:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:gax-go:v2.1.1:googleapis_gax_go_v2 \
		googleapis:google-api-go-client:v0.61.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:storage/v1.10.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.97.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.40.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jdkato:prose:v1.2.1:jdkato_prose/vendor/github.com/jdkato/prose \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		kr:pretty:v0.3.0:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		kylelemons:godebug:v1.1.0:kylelemons_godebug/vendor/github.com/kylelemons/godebug \
		kyokomi:emoji:v2.2.8:kyokomi_emoji_v2/vendor/github.com/kyokomi/emoji/v2 \
		magefile:mage:v1.11.0:magefile_mage/vendor/github.com/magefile/mage \
		magiconair:properties:v1.8.5:magiconair_properties/vendor/github.com/magiconair/properties \
		mailru:easyjson:b2ccc519800e:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:hashstructure:v1.1.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.4.3:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		muesli:smartcrop:v0.3.0:muesli_smartcrop/vendor/github.com/muesli/smartcrop \
		nfnt:resize:83c6a9932646:nfnt_resize/vendor/github.com/nfnt/resize \
		niklasfasching:go-org:v1.6.0:niklasfasching_go_org/vendor/github.com/niklasfasching/go-org \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pelletier:go-toml:fa0796069526:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		pelletier:go-toml:v1.9.3:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rogpeppe:go-internal:v1.8.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		russross:blackfriday:v1.6.0:russross_blackfriday/vendor/github.com/russross/blackfriday \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		rwcarlsen:goexif:9e8deecbddbd:rwcarlsen_goexif/vendor/github.com/rwcarlsen/goexif \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		spf13:afero:v1.6.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.4.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.2.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:fsync:v0.9.0:spf13_fsync/vendor/github.com/spf13/fsync \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.8.1:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tdewolff:minify:v2.9.22:tdewolff_minify_v2/vendor/github.com/tdewolff/minify/v2 \
		tdewolff:parse:v2.5.21:tdewolff_parse_v2/vendor/github.com/tdewolff/parse/v2 \
		yuin:goldmark-highlighting:60d527fdb691:yuin_goldmark_highlighting/vendor/github.com/yuin/goldmark-highlighting \
		yuin:goldmark:v1.4.4:yuin_goldmark/vendor/github.com/yuin/goldmark \
		sanity-io:litter:v1.5.1:sanity_io_litter/vendor/github.com/sanity-io/litter

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/googleapis/gax-go/v2
	@${RLN} ${WRKSRC_googleapis_gax_go_v2}/v2 ${WRKSRC}/vendor/github.com/googleapis/gax-go/v2
	@${MKDIR} ${WRKSRC}/vendor/github.com/sanity-io
	@${RLN} ${WRKSRC_fsnotify_fsnotify} ${WRKSRC}/vendor/github.com/sanity-io/litter

CONFLICTS_INSTALL=	hugo # bin/hugo

GO_BUILDFLAGS=	-ldflags="\
		-s -w \
		-X github.com/gohugoio/hugo/common/hugo.buildDate=${SOURCE_DATE_EPOCH:U${SOURCE_DATE_EPOCH_CMD:sh}} \
		-X github.com/gohugoio/hugo/common/hugo.commitHash=${COMMIT_ID} \
		-X github.com/gohugoio/hugo/common/hugo.vendorInfo=freebsd" \
		${BUILD_TAGS}

OPTIONS_DEFINE=		MANPAGES EXTENDED
OPTIONS_DEFAULT=	MANPAGES EXTENDED
OPTIONS_SUB=		yes

EXTENDED_DESC=		Enable SCSS/SASS support

EXTENDED_VARS=		CGO_ENABLED=1 CGO_LDFLAGS="-lm" BUILD_TAGS="-tags extended"
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
# COMMIT_ID should be the first 8 positions of the commit hash, characters should be UPPERCASE
COMMIT_ID=		B3549403

do-build-MANPAGES-on:
	@cd ${GO_WRKSRC} && ${GO_WRKDIR_BIN}/${PORTNAME} gen man --dir man/man1/

do-install-MANPAGES-on:
.for i in ${PORTMANS}
	${INSTALL_MAN} ${WRKSRC}/man/man1/$i ${STAGEDIR}/${PREFIX}/man/man1
.endfor

.include <bsd.port.post.mk>
