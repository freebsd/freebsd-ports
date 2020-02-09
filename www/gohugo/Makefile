# $FreeBSD$

PORTNAME=	hugo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.64.0
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
		Azure:azure-pipeline-go:v0.1.9:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.6.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		BurntSushi:locker:a6e239ea1c69:burntsushi_locker/vendor/github.com/BurntSushi/locker \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		alecthomas:chroma:v0.7.1:alecthomas_chroma/vendor/github.com/alecthomas/chroma \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		aws:aws-sdk-go:v1.27.1:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		bep:debounce:v1.2.0:bep_debounce/vendor/github.com/bep/debounce \
		bep:gitmap:v1.1.1:bep_gitmap/vendor/github.com/bep/gitmap \
		bep:go-tocss:v0.6.0:bep_go_tocss/vendor/github.com/bep/go-tocss \
		bep:tmc:v0.5.1:bep_tmc/vendor/github.com/bep/tmc \
		census-instrumentation:opencensus-go:v0.22.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cpuguy83:go-md2man:v1.0.10:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man \
		danwakefield:fnmatch:cbb64ac3d964:danwakefield_fnmatch/vendor/github.com/danwakefield/fnmatch \
		disintegration:gift:v1.2.1:disintegration_gift/vendor/github.com/disintegration/gift \
		dlclark:regexp2:v1.2.0:dlclark_regexp2/vendor/github.com/dlclark/regexp2 \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fortytw2:leaktest:v1.3.0:fortytw2_leaktest/vendor/github.com/fortytw2/leaktest \
		frankban:quicktest:v1.7.2:frankban_quicktest/vendor/github.com/frankban/quicktest \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.51.1:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v2.2.7:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gohugoio:testmodBuilder:c56af20f2e95:gohugoio_testmodbuilder/vendor/github.com/gohugoio/testmodBuilder/mods \
		golang:appengine:v1.6.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:image:9130b4cfad52:golang_image/vendor/golang.org/x/image \
		golang:net:c0dbc17a3553:golang_net/vendor/golang.org/x/net \
		golang:oauth2:aaccbc9213b0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:ef85f5a75ddf:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:xerrors:a985d3407aa7:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cloud:v0.15.0:google_go_cloud/vendor/gocloud.dev \
		google:go-cmp:481baca67f93:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:c2c4e71fbf69:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		google:wire:v0.2.2:google_wire/vendor/github.com/google/wire \
		googleapis:gax-go:v2.0.2:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:gax-go:v2.0.4:googleapis_gax_go_1/vendor/github.com/googleapis/gax-go/v2 \
		googleapis:google-api-go-client:v0.5.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.39.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.21.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jdkato:prose:v1.1.1:jdkato_prose/vendor/github.com/jdkato/prose \
		jmespath:go-jmespath:c2b33e8439af:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		kr:pretty:v0.2.0:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.1.0:kr_text/vendor/github.com/kr/text \
		kyokomi:emoji:v2.1.0:kyokomi_emoji/vendor/github.com/kyokomi/emoji \
		magefile:mage:v1.9.0:magefile_mage/vendor/github.com/magefile/mage \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		markbates:inflect:a12c3aec81a6:markbates_inflect/vendor/github.com/markbates/inflect \
		mattn:go-isatty:v0.0.11:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.7:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		miekg:mmark:v1.3.6:miekg_mmark/vendor/github.com/miekg/mmark \
		mitchellh:hashstructure:v1.0.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		muesli:smartcrop:v0.3.0:muesli_smartcrop/vendor/github.com/muesli/smartcrop \
		nicksnyder:go-i18n:v1.10.0:nicksnyder_go_i18n/vendor/github.com/nicksnyder/go-i18n \
		niklasfasching:go-org:v1.0.0:niklasfasching_go_org/vendor/github.com/niklasfasching/go-org \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		pelletier:go-toml:v1.6.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		rogpeppe:go-internal:v1.5.1:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		russross:blackfriday:a477dd164691:russross_blackfriday/vendor/github.com/russross/blackfriday \
		rwcarlsen:goexif:9e8deecbddbd:rwcarlsen_goexif/vendor/github.com/rwcarlsen/goexif \
		sanity-io:litter:v1.2.0:sanity_io_litter/vendor/github.com/sanity-io/litter \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:fsync:v0.9.0:spf13_fsync/vendor/github.com/spf13/fsync \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.6.1:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tdewolff:minify:v2.6.1:tdewolff_minify/vendor/github.com/tdewolff/minify/v2 \
		tdewolff:parse:v2.3.14:tdewolff_parse/vendor/github.com/tdewolff/parse/v2 \
		uber-go:atomic:v1.4.0:uber_go_atomic/vendor/go.uber.org/atomic \
		wellington:go-libsass:c63644206701:wellington_go_libsass/vendor/github.com/wellington/go-libsass \
		yuin:goldmark-highlighting:78f32c8dd6d5:yuin_goldmark_highlighting/vendor/github.com/yuin/goldmark-highlighting \
		yuin:goldmark:v1.1.22:yuin_goldmark/vendor/github.com/yuin/goldmark

GO_BUILDFLAGS=	-ldflags="\
		-s -w \
		-X github.com/gohugoio/hugo/hugolib.BuildDate=${SOURCE_DATE_EPOCH:U${SOURCE_DATE_EPOCH_CMD:sh}} \
		-X github.com/gohugoio/hugo/hugolib.CommitHash=${COMMIT_ID}" \
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
COMMIT_ID=		241db8f78a2d9a34b04a66dc63c810955ce7647c

do-build-MANPAGES-on:
	@cd ${GO_WRKSRC} && ${GO_WRKDIR_BIN}/${PORTNAME} gen man --dir man/man1/

do-install-MANPAGES-on:
.for i in ${PORTMANS}
	${INSTALL_MAN} ${WRKSRC}/man/man1/$i ${STAGEDIR}/${PREFIX}/man/man1
.endfor

.include <bsd.port.post.mk>
