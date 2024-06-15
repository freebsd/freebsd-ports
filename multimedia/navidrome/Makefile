PORTNAME=	navidrome
DISTVERSIONPREFIX=	v
DISTVERSION=	0.50.2
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freebsd.org/~kbowling/distfiles/:npmcache
DISTFILES=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npmcache
DIST_SUBDIR=	navidrome

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Modern Music Server and Streamer compatible with Subsonic/Airsonic
WWW=		https://www.navidrome.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS+=	npm>0:www/npm
LIB_DEPENDS+=	libtag.so:audio/taglib
RUN_DEPENDS+=	ffmpeg:multimedia/ffmpeg

USES=		cpe go:modules pkgconfig
USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}
GH_TUPLE=	\
		DexterLB:mpvipc:38b9935eae9d:dexterlb_mpvipc/vendor/github.com/DexterLB/mpvipc \
		Masterminds:squirrel:v1.5.4:masterminds_squirrel/vendor/github.com/Masterminds/squirrel \
		ReneKroon:ttlcache:v2.11.0:renekroon_ttlcache_v2/vendor/github.com/ReneKroon/ttlcache/v2 \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		beego:beego:v2.1.3:beego_beego_v2/vendor/github.com/beego/beego/v2 \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bradleyjkemp:cupaloy:v2.8.0:bradleyjkemp_cupaloy_v2/vendor/github.com/bradleyjkemp/cupaloy/v2 \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cloudfoundry:go-diodes:f77fb823c7ee:cloudfoundry_go_diodes/vendor/code.cloudfoundry.org/go-diodes \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deluan:rest:380523c4bb47:deluan_rest/vendor/github.com/deluan/rest \
		deluan:sanitize:6e18967d9fc1:deluan_sanitize/vendor/github.com/deluan/sanitize \
		dhowden:tag:978a0926ee25:dhowden_tag/vendor/github.com/dhowden/tag \
		disintegration:imaging:v1.6.2:disintegration_imaging/vendor/github.com/disintegration/imaging \
		djherbis:atime:v1.1.0:djherbis_atime/vendor/github.com/djherbis/atime \
		djherbis:fscache:2909c950912d:djherbis_fscache/vendor/github.com/djherbis/fscache \
		djherbis:stream:v1.4.0:djherbis_stream/vendor/github.com/djherbis/stream \
		djherbis:times:v1.6.0:djherbis_times/vendor/github.com/djherbis/times \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		faiface:beep:v1.1.0:faiface_beep/vendor/github.com/faiface/beep \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		fsnotify:fsnotify:v1.6.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-chi:chi:v5.0.10:go_chi_chi_v5/vendor/github.com/go-chi/chi/v5 \
		go-chi:cors:v1.2.1:go_chi_cors/vendor/github.com/go-chi/cors \
		go-chi:httprate:v0.7.4:go_chi_httprate/vendor/github.com/go-chi/httprate \
		go-chi:jwtauth:v5.1.1:go_chi_jwtauth_v5/vendor/github.com/go-chi/jwtauth/v5 \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-logr:logr:v1.3.0:go_logr_logr/vendor/github.com/go-logr/logr \
		go-task:slim-sprig:52ccab3ef572:go_task_slim_sprig/vendor/github.com/go-task/slim-sprig \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		goccy:go-json:v0.10.2:goccy_go_json/vendor/github.com/goccy/go-json \
		golang:crypto:v0.15.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:a9213eeb770e:golang_exp/vendor/golang.org/x/exp \
		golang:image:v0.14.0:golang_image/vendor/golang.org/x/image \
		golang:mobile:e8d11dd0ba41:golang_mobile/vendor/golang.org/x/mobile \
		golang:mod:v0.14.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.18.0:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:v0.5.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.14.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.15.0:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.6.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:pprof:e72429f035bd:google_pprof/vendor/github.com/google/pprof \
		google:uuid:v1.4.0:google_uuid/vendor/github.com/google/uuid \
		google:wire:v0.5.0:google_wire/vendor/github.com/google/wire \
		gorilla:css:v1.0.0:gorilla_css/vendor/github.com/gorilla/css \
		hajimehoshi:go-mp3:v0.3.4:hajimehoshi_go_mp3/vendor/github.com/hajimehoshi/go-mp3 \
		hajimehoshi:oto:v1.0.1:hajimehoshi_oto/vendor/github.com/hajimehoshi/oto \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		icza:bitio:v1.0.0:icza_bitio/vendor/github.com/icza/bitio \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		lann:builder:47ae307949d0:lann_builder/vendor/github.com/lann/builder \
		lann:ps:62de8c46ede0:lann_ps/vendor/github.com/lann/ps \
		lestrrat-go:blackmagic:v1.0.2:lestrrat_go_blackmagic/vendor/github.com/lestrrat-go/blackmagic \
		lestrrat-go:httpcc:v1.0.1:lestrrat_go_httpcc/vendor/github.com/lestrrat-go/httpcc \
		lestrrat-go:httprc:v1.0.4:lestrrat_go_httprc/vendor/github.com/lestrrat-go/httprc \
		lestrrat-go:iter:v1.0.2:lestrrat_go_iter/vendor/github.com/lestrrat-go/iter \
		lestrrat-go:jwx:v2.0.17:lestrrat_go_jwx_v2/vendor/github.com/lestrrat-go/jwx/v2 \
		lestrrat-go:option:v1.0.1:lestrrat_go_option/vendor/github.com/lestrrat-go/option \
		magiconair:properties:v1.8.7:magiconair_properties/vendor/github.com/magiconair/properties \
		matoous:go-nanoid:v2.0.0:matoous_go_nanoid_v2/vendor/github.com/matoous/go-nanoid/v2 \
		mattn:go-sqlite3:v1.14.18:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mattn:go-zglob:v0.0.3:mattn_go_zglob/vendor/github.com/mattn/go-zglob \
		matttproud:golang_protobuf_extensions:v1.0.4:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mewkiz:flac:v1.0.7:mewkiz_flac/vendor/github.com/mewkiz/flac \
		mewkiz:pkg:518ade7978e2:mewkiz_pkg/vendor/github.com/mewkiz/pkg \
		microcosm-cc:bluemonday:v1.0.26:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mileusna:useragent:v1.3.4:mileusna_useragent/vendor/github.com/mileusna/useragent \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		natefinch:npipe:c1b8fa8bdcce:natefinch_npipe/vendor/gopkg.in/natefinch/npipe.v2 \
		onsi:ginkgo:v1.16.5:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:ginkgo:v2.13.1:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		onsi:gomega:v1.30.0:onsi_gomega/vendor/github.com/onsi/gomega \
		pelletier:go-toml:v2.0.6:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pressly:goose:v3.11.2:pressly_goose_v3/vendor/github.com/pressly/goose/v3 \
		prometheus:client_golang:v1.17.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:9a2bf3000d16:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.44.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.11.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.31.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		robfig:cron:v3.0.1:robfig_cron_v3/vendor/github.com/robfig/cron/v3 \
		rogpeppe:go-internal:v1.10.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		segmentio:asm:v1.2.0:segmentio_asm/vendor/github.com/segmentio/asm \
		shiena:ansicolor:c7312218db18:shiena_ansicolor/vendor/github.com/shiena/ansicolor \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.9.3:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.5.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.8.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.15.0:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:objx:v0.5.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.8.4:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.4.2:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber-go:goleak:v1.1.11:uber_go_goleak/vendor/go.uber.org/goleak \
		unrolled:secure:v1.13.0:unrolled_secure/vendor/github.com/unrolled/secure \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		xrash:smetrics:89a2a8a1fb0b:xrash_smetrics/vendor/github.com/xrash/smetrics

_BUILD_SHA=	823bef5

GO_BUILDFLAGS=	-ldflags="-X github.com/navidrome/navidrome/consts.gitSha=${_BUILD_SHA} -X github.com/navidrome/navidrome/consts.gitTag=${GH_TAGNAME}-FREEBSD" -tags=netgo

MAKE_ENV+=	npm_config_offline=true

SUB_FILES+=	pkg-message config.toml.sample
SUB_LIST+=	PORTNAME=${PORTNAME} \
		NAVIDROMEUSER=${USERS} \
		NAVIDROMEGROUP=${GROUPS}

USERS=		www
GROUPS=		www

.include <bsd.port.options.mk>

# Compiler runs out of memory when compiling the ui on 32-bit platforms:
# https://github.com/navidrome/navidrome/issues/524
.if ${ARCH} != amd64 || ${ARCH} != aarch64
MAKE_ENV+=	NODE_OPTIONS='--max-old-space-size=1492'
.endif

pre-build:
	cd ${WRKSRC}/ui && ${SETENV} ${MAKE_ENV} npm ci
	cd ${WRKSRC}/ui && ${SETENV} ${MAKE_ENV} npm run build

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${DESTDIR}/var/db/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}/music
	${INSTALL_DATA} ${WRKDIR}/config.toml.sample \
		${STAGEDIR}${ETCDIR}/config.toml.sample

# Helper target to make the generation of node_modules easier
make-npm-cache:
	# Run "make extract" before executing this target
	@cd ${WRKDIR} && ${RM} -r .npm
	@cd ${WRKSRC}/ui \
		&& ${SETENV} HOME=${WRKDIR} npm ci
	@cd ${WRKDIR} \
		&& ${TAR} -czf ${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX} .npm \
		&& ${ECHO} "Please upload the file ${WRKDIR}/${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}"

.include <bsd.port.mk>
