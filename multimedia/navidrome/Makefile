PORTNAME=	navidrome
DISTVERSIONPREFIX=	v
DISTVERSION=	0.52.5
PORTREVISION=	4
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

USES=		cpe go:1.22,modules pkgconfig
USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}
GH_TUPLE=	\
		Masterminds:squirrel:v1.5.4:masterminds_squirrel/vendor/github.com/Masterminds/squirrel \
		RaveNoX:go-jsoncommentstrip:v1.0.0:ravenox_go_jsoncommentstrip/vendor/github.com/RaveNoX/go-jsoncommentstrip \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bradleyjkemp:cupaloy:v2.8.0:bradleyjkemp_cupaloy_v2/vendor/github.com/bradleyjkemp/cupaloy/v2 \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:d8f796af33cc:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deluan:rest:6260bc399cbf:deluan_rest/vendor/github.com/deluan/rest \
		deluan:sanitize:6e18967d9fc1:deluan_sanitize/vendor/github.com/deluan/sanitize \
		dexterlb:mpvipc:145d6eabdc37:dexterlb_mpvipc/vendor/github.com/dexterlb/mpvipc \
		dhowden:tag:3d75831295e8:dhowden_tag/vendor/github.com/dhowden/tag \
		disintegration:imaging:v1.6.2:disintegration_imaging/vendor/github.com/disintegration/imaging \
		djherbis:atime:v1.1.0:djherbis_atime/vendor/github.com/djherbis/atime \
		djherbis:fscache:2909c950912d:djherbis_fscache/vendor/github.com/djherbis/fscache \
		djherbis:stream:v1.4.0:djherbis_stream/vendor/github.com/djherbis/stream \
		djherbis:times:v1.6.0:djherbis_times/vendor/github.com/djherbis/times \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		fsnotify:fsnotify:v1.7.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-chi:chi:v5.0.12:go_chi_chi_v5/vendor/github.com/go-chi/chi/v5 \
		go-chi:cors:v1.2.1:go_chi_cors/vendor/github.com/go-chi/cors \
		go-chi:httprate:v0.9.0:go_chi_httprate/vendor/github.com/go-chi/httprate \
		go-chi:jwtauth:v5.3.1:go_chi_jwtauth_v5/vendor/github.com/go-chi/jwtauth/v5 \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-logr:logr:v1.4.1:go_logr_logr/vendor/github.com/go-logr/logr \
		go-task:slim-sprig:v3.0.0:go_task_slim_sprig_v3/vendor/github.com/go-task/slim-sprig/v3 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		goccy:go-json:v0.10.2:goccy_go_json/vendor/github.com/goccy/go-json \
		golang:crypto:v0.23.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:9bf2ced13842:golang_exp/vendor/golang.org/x/exp \
		golang:image:v0.16.0:golang_image/vendor/golang.org/x/image \
		golang:net:v0.25.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.7.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.20.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.15.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.21.0:golang_tools/vendor/golang.org/x/tools \
		google:go-cmp:v0.6.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:pprof:a892ee059fd6:google_pprof/vendor/github.com/google/pprof \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		google:wire:v0.6.0:google_wire/vendor/github.com/google/wire \
		gorilla:css:v1.0.0:gorilla_css/vendor/github.com/gorilla/css \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jellydator:ttlcache:v2.11.1:jellydator_ttlcache_v2/vendor/github.com/jellydator/ttlcache/v2 \
		kr:pretty:v0.3.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		lann:builder:47ae307949d0:lann_builder/vendor/github.com/lann/builder \
		lann:ps:62de8c46ede0:lann_ps/vendor/github.com/lann/ps \
		lestrrat-go:blackmagic:v1.0.2:lestrrat_go_blackmagic/vendor/github.com/lestrrat-go/blackmagic \
		lestrrat-go:httpcc:v1.0.1:lestrrat_go_httpcc/vendor/github.com/lestrrat-go/httpcc \
		lestrrat-go:httprc:v1.0.5:lestrrat_go_httprc/vendor/github.com/lestrrat-go/httprc \
		lestrrat-go:iter:v1.0.2:lestrrat_go_iter/vendor/github.com/lestrrat-go/iter \
		lestrrat-go:jwx:v2.0.21:lestrrat_go_jwx_v2/vendor/github.com/lestrrat-go/jwx/v2 \
		lestrrat-go:option:v1.0.1:lestrrat_go_option/vendor/github.com/lestrrat-go/option \
		magiconair:properties:v1.8.7:magiconair_properties/vendor/github.com/magiconair/properties \
		matoous:go-nanoid:v2.0.0:matoous_go_nanoid_v2/vendor/github.com/matoous/go-nanoid/v2 \
		mattn:go-sqlite3:v1.14.22:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mattn:go-zglob:v0.0.4:mattn_go_zglob/vendor/github.com/mattn/go-zglob \
		mfridman:interpolate:v0.0.2:mfridman_interpolate/vendor/github.com/mfridman/interpolate \
		microcosm-cc:bluemonday:v1.0.26:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mileusna:useragent:v1.3.4:mileusna_useragent/vendor/github.com/mileusna/useragent \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		natefinch:npipe:c1b8fa8bdcce:natefinch_npipe/vendor/gopkg.in/natefinch/npipe.v2 \
		onsi:ginkgo:v2.17.3:onsi_ginkgo_v2/vendor/github.com/onsi/ginkgo/v2 \
		onsi:gomega:v1.33.1:onsi_gomega/vendor/github.com/onsi/gomega \
		pelletier:go-toml:v2.2.2:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		pmezard:go-difflib:5d4384ee4fb2:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pocketbase:dbx:v1.10.1:pocketbase_dbx/vendor/github.com/pocketbase/dbx \
		pressly:goose:v3.20.0:pressly_goose_v3/vendor/github.com/pressly/goose/v3 \
		prometheus:client_golang:v1.19.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.5.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.48.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.12.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.33.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		robfig:cron:v3.0.1:robfig_cron_v3/vendor/github.com/robfig/cron/v3 \
		rogpeppe:go-internal:v1.10.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		sagikazarmark:locafero:v0.4.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sagikazarmark:slog-shim:v0.1.0:sagikazarmark_slog_shim/vendor/github.com/sagikazarmark/slog-shim \
		segmentio:asm:v1.2.0:segmentio_asm/vendor/github.com/segmentio/asm \
		sethvargo:go-retry:v0.2.4:sethvargo_go_retry/vendor/github.com/sethvargo/go-retry \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sourcegraph:conc:v0.3.0:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spf13:afero:v1.11.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.6.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.8.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.18.2:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:objx:v0.5.2:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.9.0:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr \
		unrolled:secure:v1.14.0:unrolled_secure/vendor/github.com/unrolled/secure \
		xrash:smetrics:5f08fbb34913:xrash_smetrics/vendor/github.com/xrash/smetrics

_BUILD_SHA=	c556088

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
