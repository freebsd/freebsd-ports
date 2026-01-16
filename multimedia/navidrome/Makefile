PORTNAME=	navidrome
DISTVERSIONPREFIX=	v
DISTVERSION=	0.59.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Modern Music Server and Streamer compatible with Subsonic/Airsonic
WWW=		https://www.navidrome.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

FETCH_DEPENDS=	npm:www/npm${NODEJS_SUFFIX}
FETCH_DEPENDS=	npm:www/npm${NODEJS_SUFFIX}
LIB_DEPENDS=	libtag.so:audio/taglib
RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg

USES=		cpe go:1.25+,modules nodejs:24,build pkgconfig

USE_GITHUB=	yes
GH_TUPLE=	\
		Masterminds:semver:v3.4.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		Masterminds:squirrel:v1.5.4:masterminds_squirrel/vendor/github.com/Masterminds/squirrel \
		RaveNoX:go-jsoncommentstrip:v1.0.0:ravenox_go_jsoncommentstrip/vendor/github.com/RaveNoX/go-jsoncommentstrip \
		andybalholm:cascadia:v1.3.3:andybalholm_cascadia/vendor/github.com/andybalholm/cascadia \
		atombender:go-jsonschema:v0.20.0:atombender_go_jsonschema/vendor/github.com/atombender/go-jsonschema \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bmatcuk:doublestar:v4.9.1:bmatcuk_doublestar_v4/vendor/github.com/bmatcuk/doublestar/v4 \
		bradleyjkemp:cupaloy:v2.8.0:bradleyjkemp_cupaloy_v2/vendor/github.com/bradleyjkemp/cupaloy/v2 \
		cespare:reflex:v0.3.1:cespare_reflex/vendor/github.com/cespare/reflex \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		creack:pty:v1.1.11:creack_pty/vendor/github.com/creack/pty \
		davecgh:go-spew:d8f796af33cc:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deluan:rest:6260bc399cbf:deluan_rest/vendor/github.com/deluan/rest \
		deluan:sanitize:fdfd8fdfaa55:deluan_sanitize/vendor/github.com/deluan/sanitize \
		deluan:tag:dfe5e6ea396d:deluan_tag/vendor/github.com/dhowden/tag \
		dexterlb:mpvipc:7cdefca0e933:dexterlb_mpvipc/vendor/github.com/dexterlb/mpvipc \
		disintegration:imaging:v1.6.2:disintegration_imaging/vendor/github.com/disintegration/imaging \
		djherbis:atime:v1.1.0:djherbis_atime/vendor/github.com/djherbis/atime \
		djherbis:fscache:442a07e326c4:djherbis_fscache/vendor/github.com/djherbis/fscache \
		djherbis:stream:v1.4.0:djherbis_stream/vendor/github.com/djherbis/stream \
		djherbis:times:v1.6.0:djherbis_times/vendor/github.com/djherbis/times \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		fsnotify:fsnotify:v1.9.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-chi:chi:v5.2.3:go_chi_chi_v5/vendor/github.com/go-chi/chi/v5 \
		go-chi:cors:v1.2.2:go_chi_cors/vendor/github.com/go-chi/cors \
		go-chi:httprate:v0.15.0:go_chi_httprate/vendor/github.com/go-chi/httprate \
		go-chi:jwtauth:v5.3.3:go_chi_jwtauth_v5/vendor/github.com/go-chi/jwtauth/v5 \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-logr:logr:v1.4.3:go_logr_logr/vendor/github.com/go-logr/logr \
		go-task:slim-sprig:v3.0.0:go_task_slim_sprig_v3/vendor/github.com/go-task/slim-sprig/v3 \
		go-viper:encoding:ini/v0.1.1:go_viper_encoding_ini/vendor/github.com/go-viper/encoding \
		go-viper:mapstructure:v2.4.0:go_viper_mapstructure_v2/vendor/github.com/go-viper/mapstructure/v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		goccy:go-json:v0.10.5:goccy_go_json/vendor/github.com/goccy/go-json \
		goccy:go-yaml:v1.18.0:goccy_go_yaml/vendor/github.com/goccy/go-yaml \
		gohugoio:hashstructure:v0.6.0:gohugoio_hashstructure/vendor/github.com/gohugoio/hashstructure \
		golang:crypto:v0.45.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:e25ba8c21ef6:golang_exp/vendor/golang.org/x/exp \
		golang:image:v0.33.0:golang_image/vendor/golang.org/x/image \
		golang:mod:v0.30.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.47.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.18.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.38.0:golang_sys/vendor/golang.org/x/sys \
		golang:telemetry:bc8e575c7b54:golang_telemetry/vendor/golang.org/x/telemetry \
		golang:term:v0.37.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.31.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.14.0:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.39.0:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.7.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-pipeline:6cbedfc1d3fc:google_go_pipeline/vendor/github.com/google/go-pipeline \
		google:pprof:4902fdda35c8:google_pprof/vendor/github.com/google/pprof \
		google:subcommands:v1.2.0:google_subcommands/vendor/github.com/google/subcommands \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		google:wire:v0.7.0:google_wire/vendor/github.com/google/wire \
		gorilla:css:v1.0.1:gorilla_css/vendor/github.com/gorilla/css \
		gorilla:websocket:v1.5.3:gorilla_websocket/vendor/github.com/gorilla/websocket \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		imdario:mergo:v1.0.2:imdario_mergo/vendor/dario.cat/mergo \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jellydator:ttlcache:v3.4.0:jellydator_ttlcache_v3/vendor/github.com/jellydator/ttlcache/v3 \
		kardianos:service:v1.2.4:kardianos_service/vendor/github.com/kardianos/service \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:cpuid:v2.3.0:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		knqyf263:go-plugin:v0.9.0:knqyf263_go_plugin/vendor/github.com/knqyf263/go-plugin \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		lann:builder:47ae307949d0:lann_builder/vendor/github.com/lann/builder \
		lann:ps:62de8c46ede0:lann_ps/vendor/github.com/lann/ps \
		lestrrat-go:blackmagic:v1.0.4:lestrrat_go_blackmagic/vendor/github.com/lestrrat-go/blackmagic \
		lestrrat-go:httpcc:v1.0.1:lestrrat_go_httpcc/vendor/github.com/lestrrat-go/httpcc \
		lestrrat-go:httprc:v1.0.6:lestrrat_go_httprc/vendor/github.com/lestrrat-go/httprc \
		lestrrat-go:iter:v1.0.2:lestrrat_go_iter/vendor/github.com/lestrrat-go/iter \
		lestrrat-go:jwx:v2.1.6:lestrrat_go_jwx_v2/vendor/github.com/lestrrat-go/jwx/v2 \
		lestrrat-go:option:v1.0.1:lestrrat_go_option/vendor/github.com/lestrrat-go/option \
		maruel:natural:v1.2.1:maruel_natural/vendor/github.com/maruel/natural \
		matoous:go-nanoid:v2.1.0:matoous_go_nanoid_v2/vendor/github.com/matoous/go-nanoid/v2 \
		mattn:go-sqlite3:v1.14.32:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mfridman:interpolate:v0.0.2:mfridman_interpolate/vendor/github.com/mfridman/interpolate \
		microcosm-cc:bluemonday:v1.0.27:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mileusna:useragent:v1.3.5:mileusna_useragent/vendor/github.com/mileusna/useragent \
		mitchellh:go-wordwrap:v1.0.1:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		munnerz:goautoneg:a7dc8b61c822:munnerz_goautoneg/vendor/github.com/munnerz/goautoneg \
		natefinch:npipe:c1b8fa8bdcce:natefinch_npipe/vendor/gopkg.in/natefinch/npipe.v2 \
		ogier:pflag:v0.0.1:ogier_pflag/vendor/github.com/ogier/pflag \
		onsi:ginkgo:v2.27.2:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		onsi:gomega:v1.38.2:onsi_gomega/vendor/github.com/onsi/gomega \
		pelletier:go-toml:v2.2.4:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:5d4384ee4fb2:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pocketbase:dbx:v1.11.0:pocketbase_dbx/vendor/github.com/pocketbase/dbx \
		pressly:goose:v3.26.0:pressly_goose_v3/vendor/github.com/pressly/goose/v3 \
		prometheus:client_golang:v1.23.2:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.6.2:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.66.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.16.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.36.10:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rjeczalik:notify:v0.9.3:rjeczalik_notify/vendor/github.com/rjeczalik/notify \
		robfig:cron:v3.0.1:robfig_cron_v3/vendor/github.com/robfig/cron/v3 \
		rogpeppe:go-internal:v1.14.1:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		sabhiram:go-gitignore:525f6e181f06:sabhiram_go_gitignore/vendor/github.com/sabhiram/go-gitignore \
		sagikazarmark:locafero:v0.12.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sanity-io:litter:v1.5.8:sanity_io_litter/vendor/github.com/sanity-io/litter \
		segmentio:asm:v1.2.1:segmentio_asm/vendor/github.com/segmentio/asm \
		sethvargo:go-retry:v0.3.0:sethvargo_go_retry/vendor/github.com/sethvargo/go-retry \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sosodev:duration:v1.3.1:sosodev_duration/vendor/github.com/sosodev/duration \
		spf13:afero:v1.15.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.10.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.10.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.10:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.21.0:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:objx:v0.5.2:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.11.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tetratelabs:wazero:v1.10.1:tetratelabs_wazero/vendor/github.com/tetratelabs/wazero \
		uber-go:goleak:v1.3.0:uber_go_goleak/vendor/go.uber.org/goleak \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		unrolled:secure:v1.17.0:unrolled_secure/vendor/github.com/unrolled/secure \
		xrash:smetrics:55b8f293f342:xrash_smetrics/vendor/github.com/xrash/smetrics \
		yaml:go-yaml:v2.4.2:yaml_go_yaml/vendor/go.yaml.in/yaml/v2 \
		yaml:go-yaml:v3.0.4:yaml_go_yaml_1/vendor/go.yaml.in/yaml/v3 \
		zeebo:xxh3:v1.0.2:zeebo_xxh3/vendor/github.com/zeebo/xxh3

PREFETCH_TIMESTAMP=	61171200
USE_RC_SUBR=	${PORTNAME}

_BUILD_SHA=	cc3cca6

GO_BUILDFLAGS=	-ldflags="-X github.com/navidrome/navidrome/consts.gitSha=${_BUILD_SHA} -X github.com/navidrome/navidrome/consts.gitTag=${GH_TAGNAME}-FREEBSD" -tags=netgo

SUB_FILES+=	config.toml.sample pkg-message
SUB_LIST+=	NAVIDROMEGROUP=${GROUPS} \
		NAVIDROMEUSER=${USERS} \
		PORTNAME=${PORTNAME}

USERS=		www
GROUPS=		www

# We need ARCH to be defined, which can only happen after options.mk
.include <bsd.port.options.mk>

# Compiler runs out of memory when compiling the ui on 32-bit platforms:
# https://github.com/navidrome/navidrome/issues/524
.if ${ARCH} != amd64 || ${ARCH} != aarch64
MAKE_ENV+=	NODE_OPTIONS='--max-old-space-size=1492'
.endif

.if ${ARCH} == amd64 || make(makesum)
FILE_AMD64=		${PORTNAME}-${DISTVERSION}-node${NODEJS_VERSION}-amd64-modules.tar.gz
DISTFILES+=	${FILE_AMD64}:prefetch
COMBIARCH+=	x64 ${FILE_AMD64}
.endif

.if ${ARCH} == aarch64 || make(makesum)
FILE_ARM64=		${PORTNAME}-${DISTVERSION}-node${NODEJS_VERSION}-arm64-modules.tar.gz
DISTFILES+=	${FILE_ARM64}:prefetch
COMBIARCH+=	arm64 ${FILE_ARM64}
.endif

# We need NODEJS_VERSION to be expanded before assigning it so MAKESUM_DEP and NODEJS_VERSION
# is only expanded after pre.mk
.include <bsd.port.pre.mk>

.for c f in ${COMBIARCH}
${DISTDIR}/$f:
	${MKDIR} ${WRKDIR}/ui/node-modules-cache; \
	${CP} -R ${FILESDIR}/packagejsons/* ${WRKDIR}/ui/node-modules-cache; \
	cd ${WRKDIR}/ui/node-modules-cache && \
	${SETENV} HOME=${WRKDIR} \
		npm ci --ignore-scripts --no-progress --no-audit --no-fund --cpu=$c; \
	${FIND} ${WRKDIR}/ui/node-modules-cache -depth 1 -print | \
		${GREP} -v node_modules | ${XARGS} ${RM} -r; \
	${FIND} ${WRKDIR}/ui/node-modules-cache -type d -exec ${CHMOD} 755 {} ';'; \
	cd ${WRKDIR}//ui/node-modules-cache && \
	${MTREE_CMD} -cbnSp node_modules | ${MTREE_CMD} -C | ${SED} \
		-e 's:time=[0-9.]*:time=${PREFETCH_TIMESTAMP}.000000000:' \
		-e 's:\([gu]id\)=[0-9]*:\1=0:g' \
		-e 's:flags=.*:flags=none:' \
		-e 's:^\.:./node_modules:' > node-modules-cache.mtree; \
	${TAR} -cz --options 'gzip:!timestamp' \
		-f ${DISTDIR}/$f \
		@node-modules-cache.mtree; \
	${RM} -r ${WRKDIR}; \

pre-fetch: ${DISTDIR}/$f
MAKESUM_DEP+= ${DISTDIR}/$f
.endfor

pre-build:
	cd ${WRKSRC}/ui && ${SETENV} ${MAKE_ENV} npm run build
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor/

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${DESTDIR}/var/db/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}/music
	${INSTALL_DATA} ${WRKDIR}/config.toml.sample \
		${STAGEDIR}${ETCDIR}/config.toml.sample

.include <bsd.port.mk>

makesum: ${MAKESUM_DEP}
