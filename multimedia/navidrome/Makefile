PORTNAME=	navidrome
DISTVERSIONPREFIX=	v
DISTVERSION=	0.40.0
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://cdn.pacyworld.com/morante.net/freebsd/ports/distfiles/navidrome/:npmcache
DISTFILES=	${PORTNAME}-npm-cache-${DISTVERSION}${EXTRACT_SUFX}:npmcache
DIST_SUBDIR=	navidrome

MAINTAINER=	daniel@morante.net
COMMENT=	Modern Music Server and Streamer compatible with Subsonic/Airsonic

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		react-scripts: not found

BUILD_DEPENDS+=	npm>0:www/npm \
				go-bindata:devel/go-bindata
LIB_DEPENDS+=	libtag.so:audio/taglib
RUN_DEPENDS+=	ffmpeg:multimedia/ffmpeg

USES=		cpe go:modules pkgconfig
USE_GITHUB=	yes
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		ClickHouse:clickhouse-go:v1.4.3:clickhouse_clickhouse_go/vendor/github.com/ClickHouse/clickhouse-go \
		Djarvur:go-err113:5174e21577d5:djarvur_go_err113/vendor/github.com/Djarvur/go-err113 \
		Masterminds:semver:v1.5.0:masterminds_semver/vendor/github.com/Masterminds/semver \
		Masterminds:squirrel:v1.5.0:masterminds_squirrel/vendor/github.com/Masterminds/squirrel \
		OpenPeeDeeP:depguard:v1.0.1:openpeedeep_depguard/vendor/github.com/OpenPeeDeeP/depguard \
		ashanbrown:forbidigo:v1.0.0:ashanbrown_forbidigo/vendor/github.com/ashanbrown/forbidigo \
		ashanbrown:makezero:7b7cdbb3025a:ashanbrown_makezero/vendor/github.com/ashanbrown/makezero \
		astaxie:beego:v1.12.3:astaxie_beego/vendor/github.com/astaxie/beego \
		aymerick:douceur:v0.2.0:aymerick_douceur/vendor/github.com/aymerick/douceur \
		bombsimon:wsl:v3.1.0:bombsimon_wsl_v3/vendor/github.com/bombsimon/wsl/v3 \
		bradleyjkemp:cupaloy:v2.3.0:bradleyjkemp_cupaloy/vendor/github.com/bradleyjkemp/cupaloy \
		cespare:reflex:v0.3.0:cespare_reflex/vendor/github.com/cespare/reflex \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		chris-ramon:douceur:v0.2.0:chris_ramon_douceur \
		cloudflare:golz4:ef862a3cdc58:cloudflare_golz4/vendor/github.com/cloudflare/golz4 \
		cloudfoundry:go-diodes:f77fb823c7ee:cloudfoundry_go_diodes/vendor/code.cloudfoundry.org/go-diodes \
		creack:pty:v1.1.11:creack_pty/vendor/github.com/creack/pty \
		daixiang0:gci:v0.2.8:daixiang0_gci/vendor/github.com/daixiang0/gci \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		deluan:rest:b71e558c45d0:deluan_rest/vendor/github.com/deluan/rest \
		denis-tingajkin:go-header:v0.4.2:denis_tingajkin_go_header/vendor/github.com/denis-tingajkin/go-header \
		denisenkom:go-mssqldb:v0.9.0:denisenkom_go_mssqldb/vendor/github.com/denisenkom/go-mssqldb \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		disintegration:imaging:v1.6.2:disintegration_imaging/vendor/github.com/disintegration/imaging \
		djherbis:atime:v1.0.0:djherbis_atime/vendor/gopkg.in/djherbis/atime.v1 \
		djherbis:fscache:a0daa9e52747:djherbis_fscache/vendor/github.com/djherbis/fscache \
		djherbis:stream:v1.3.1:djherbis_stream/vendor/gopkg.in/djherbis/stream.v1 \
		dominikh:go-tools:v0.0.1-2020.1.6:dominikh_go_tools/vendor/honnef.co/go/tools \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		esimonov:ifshort:v1.0.0:esimonov_ifshort/vendor/github.com/esimonov/ifshort \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-bindata:go-bindata:v3.1.2:go_bindata_go_bindata/vendor/github.com/go-bindata/go-bindata \
		go-chi:chi:v1.5.1:go_chi_chi/vendor/github.com/go-chi/chi \
		go-chi:cors:v1.1.1:go_chi_cors/vendor/github.com/go-chi/cors \
		go-chi:httprate:v0.4.0:go_chi_httprate/vendor/github.com/go-chi/httprate \
		go-chi:jwtauth:v4.0.4:go_chi_jwtauth/vendor/github.com/go-chi/jwtauth \
		go-critic:go-critic:v0.5.3:go_critic_go_critic/vendor/github.com/go-critic/go-critic \
		go-ini:ini:v1.57.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-toolsmith:astcast:v1.0.0:go_toolsmith_astcast/vendor/github.com/go-toolsmith/astcast \
		go-toolsmith:astcopy:v1.0.0:go_toolsmith_astcopy/vendor/github.com/go-toolsmith/astcopy \
		go-toolsmith:astequal:v1.0.0:go_toolsmith_astequal/vendor/github.com/go-toolsmith/astequal \
		go-toolsmith:astfmt:v1.0.0:go_toolsmith_astfmt/vendor/github.com/go-toolsmith/astfmt \
		go-toolsmith:astp:v1.0.0:go_toolsmith_astp/vendor/github.com/go-toolsmith/astp \
		go-toolsmith:strparse:v1.0.0:go_toolsmith_strparse/vendor/github.com/go-toolsmith/strparse \
		go-toolsmith:typep:v1.0.2:go_toolsmith_typep/vendor/github.com/go-toolsmith/typep \
		go-xmlfmt:xmlfmt:d5b6f63a941b:go_xmlfmt_xmlfmt/vendor/github.com/go-xmlfmt/xmlfmt \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gofrs:flock:v0.8.0:gofrs_flock/vendor/github.com/gofrs/flock \
		golang-sql:civil:cb61b32ac6fe:golang_sql_civil/vendor/github.com/golang-sql/civil \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:image:e7c1f5e7dbb8:golang_image/vendor/golang.org/x/image \
		golang:mod:v0.4.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:c7110b5ffcbb:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:489259a85091:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		golang:tools:9ed45478a130:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		golangci:check:cfe4005ccda2:golangci_check/vendor/github.com/golangci/check \
		golangci:dupl:3e9179ac440a:golangci_dupl/vendor/github.com/golangci/dupl \
		golangci:errcheck:ef45e06d44b6:golangci_errcheck/vendor/github.com/golangci/errcheck \
		golangci:go-misc:927a3d87b613:golangci_go_misc/vendor/github.com/golangci/go-misc \
		golangci:gocyclo:0a533e8fa43d:golangci_gocyclo/vendor/github.com/golangci/gocyclo \
		golangci:gofmt:244bba706f1a:golangci_gofmt/vendor/github.com/golangci/gofmt \
		golangci:golangci-lint:v1.36.0:golangci_golangci_lint/vendor/github.com/golangci/golangci-lint \
		golangci:ineffassign:42439a7714cc:golangci_ineffassign/vendor/github.com/golangci/ineffassign \
		golangci:lint-1:297bf364a8e0:golangci_lint_1/vendor/github.com/golangci/lint-1 \
		golangci:maligned:b1d89398deca:golangci_maligned/vendor/github.com/golangci/maligned \
		golangci:misspell:950f5d19e770:golangci_misspell/vendor/github.com/golangci/misspell \
		golangci:prealloc:215b22d4de21:golangci_prealloc/vendor/github.com/golangci/prealloc \
		golangci:revgrep:d9c87f5ffaf0:golangci_revgrep/vendor/github.com/golangci/revgrep \
		golangci:unconvert:28b1c447d1f4:golangci_unconvert/vendor/github.com/golangci/unconvert \
		google:go-cmp:v0.5.4:google_go_cmp/vendor/github.com/google/go-cmp \
		google:subcommands:v1.0.1:google_subcommands/vendor/github.com/google/subcommands \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		google:wire:v0.5.0:google_wire/vendor/github.com/google/wire \
		gorilla:css:v1.0.0:gorilla_css/vendor/github.com/gorilla/css \
		gostaticanalysis:analysisutil:v0.4.1:gostaticanalysis_analysisutil/vendor/github.com/gostaticanalysis/analysisutil \
		gostaticanalysis:comment:v1.4.1:gostaticanalysis_comment/vendor/github.com/gostaticanalysis/comment \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jgautheron:goconst:ccae5bf973f3:jgautheron_goconst/vendor/github.com/jgautheron/goconst \
		jingyugao:rowserrcheck:72ab7603b68a:jingyugao_rowserrcheck/vendor/github.com/jingyugao/rowserrcheck \
		jirfag:go-printf-func-name:45db9963cdd3:jirfag_go_printf_func_name/vendor/github.com/jirfag/go-printf-func-name \
		karrick:godirwalk:v1.16.1:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		kennygrant:sanitize:6a0bfdde8629:kennygrant_sanitize/vendor/github.com/kennygrant/sanitize \
		kisielk:gotool:v1.0.0:kisielk_gotool/vendor/github.com/kisielk/gotool \
		kr:pretty:v0.2.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		kulti:thelper:v0.2.1:kulti_thelper/vendor/github.com/kulti/thelper \
		kunwardeep:paralleltest:v1.0.2:kunwardeep_paralleltest/vendor/github.com/kunwardeep/paralleltest \
		kyoh86:exportloopref:v0.1.8:kyoh86_exportloopref/vendor/github.com/kyoh86/exportloopref \
		lann:builder:47ae307949d0:lann_builder/vendor/github.com/lann/builder \
		lann:ps:62de8c46ede0:lann_ps/vendor/github.com/lann/ps \
		leighmcculloch:gochecknoglobals:acfc0b28355a:leighmcculloch_gochecknoglobals/vendor/4d63.com/gochecknoglobals \
		lib:pq:v1.9.0:lib_pq/vendor/github.com/lib/pq \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		maratori:testpackage:v1.0.1:maratori_testpackage/vendor/github.com/maratori/testpackage \
		matoous:godox:5d6d842e92eb:matoous_godox/vendor/github.com/matoous/godox \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v2.0.3:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mbilski:exhaustivestruct:v1.1.0:mbilski_exhaustivestruct/vendor/github.com/mbilski/exhaustivestruct \
		microcosm-cc:bluemonday:v1.0.4:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.3.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moricho:tparallel:v0.2.1:moricho_tparallel/vendor/github.com/moricho/tparallel \
		mvdan:gofumpt:v0.1.0:mvdan_gofumpt/vendor/mvdan.cc/gofumpt \
		mvdan:interfacer:c20040233aed:mvdan_interfacer/vendor/mvdan.cc/interfacer \
		mvdan:lint:adc824a0674b:mvdan_lint/vendor/mvdan.cc/lint \
		mvdan:unparam:b37ab49443f7:mvdan_unparam/vendor/mvdan.cc/unparam \
		nakabonne:nestif:v0.3.0:nakabonne_nestif/vendor/github.com/nakabonne/nestif \
		nbutton23:zxcvbn-go:e56b841a3c88:nbutton23_zxcvbn_go/vendor/github.com/nbutton23/zxcvbn-go \
		nishanths:exhaustive:v0.1.0:nishanths_exhaustive/vendor/github.com/nishanths/exhaustive \
		nishanths:predeclared:v0.2.1:nishanths_predeclared/vendor/github.com/nishanths/predeclared \
		nxadm:tail:v1.4.4:nxadm_tail/vendor/github.com/nxadm/tail \
		ogier:pflag:v0.0.1:ogier_pflag/vendor/github.com/ogier/pflag \
		oklog:run:v1.1.0:oklog_run/vendor/github.com/oklog/run \
		onsi:ginkgo:v1.15.0:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.10.5:onsi_gomega/vendor/github.com/onsi/gomega \
		pelletier:go-toml:v1.8.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		phayes:checkstyle:bfd46e6a821d:phayes_checkstyle/vendor/github.com/phayes/checkstyle \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		polyfloyd:go-errorlint:19bd8db6546f:polyfloyd_go_errorlint/vendor/github.com/polyfloyd/go-errorlint \
		pressly:goose:v2.7.0:pressly_goose/vendor/github.com/pressly/goose \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		quasilyte:go-ruleguard:408e96760278:quasilyte_go_ruleguard/vendor/github.com/quasilyte/go-ruleguard \
		quasilyte:regex:30656e2c4a95:quasilyte_regex_syntax/vendor/github.com/quasilyte/regex \
		ryancurrah:gomodguard:v1.2.0:ryancurrah_gomodguard/vendor/github.com/ryancurrah/gomodguard \
		ryanrolds:sqlclosecheck:v0.3.0:ryanrolds_sqlclosecheck/vendor/github.com/ryanrolds/sqlclosecheck \
		securego:gosec:v2.6.1:securego_gosec_v2/vendor/github.com/securego/gosec/v2 \
		shazow:go-diff:b6b7b6733b8c:shazow_go_diff/vendor/github.com/shazow/go-diff \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sonatard:noctx:v0.0.1:sonatard_noctx/vendor/github.com/sonatard/noctx \
		sourcegraph:go-diff:v0.6.1:sourcegraph_go_diff/vendor/github.com/sourcegraph/go-diff \
		spf13:afero:v1.3.1:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.1.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.1:spf13_viper/vendor/github.com/spf13/viper \
		ssgreg:nlreturn:v2.1.0:ssgreg_nlreturn_v2/vendor/github.com/ssgreg/nlreturn/v2 \
		stretchr:objx:v0.1.1:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tdakkota:asciicheck:d7f85be797a2:tdakkota_asciicheck/vendor/github.com/tdakkota/asciicheck \
		tetafro:godot:v1.4.3:tetafro_godot/vendor/github.com/tetafro/godot \
		timakin:bodyclose:f7f2e9bca95e:timakin_bodyclose/vendor/github.com/timakin/bodyclose \
		tomarrell:wrapcheck:df9e8bcb914d:tomarrell_wrapcheck/vendor/github.com/tomarrell/wrapcheck \
		tommy-muehle:go-mnd:v2.3.1:tommy_muehle_go_mnd_v2/vendor/github.com/tommy-muehle/go-mnd/v2 \
		ultraware:funlen:v0.0.3:ultraware_funlen/vendor/github.com/ultraware/funlen \
		ultraware:whitespace:v0.0.4:ultraware_whitespace/vendor/github.com/ultraware/whitespace \
		unrolled:secure:v1.0.8:unrolled_secure/vendor/github.com/unrolled/secure \
		uudashr:gocognit:v1.0.1:uudashr_gocognit/vendor/github.com/uudashr/gocognit \
		wader:tag:d072771f6a51:wader_tag/vendor/github.com/dhowden/tag \
		xrash:smetrics:89a2a8a1fb0b:xrash_smetrics/vendor/github.com/xrash/smetrics \
		ziutek:mymysql:v1.5.4:ziutek_mymysql/vendor/github.com/ziutek/mymysql

USE_RC_SUBR=	${PORTNAME}

_BUILD_SHA=	8799358

GO_BUILDFLAGS=	-ldflags="-X github.com/navidrome/navidrome/consts.gitSha=${_BUILD_SHA} -X github.com/navidrome/navidrome/consts.gitTag=${GH_TAGNAME}-FREEBSD" -tags=embed,netgo

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

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/github.com/chris-ramon
	@${RLN} ${WRKSRC_aymerick_douceur} ${WRKSRC}/vendor/github.com/chris-ramon/douceur

pre-build:
	cd ${WRKSRC}/ui && ${SETENV} ${MAKE_ENV} npm ci
	cd ${WRKSRC}/ui && ${SETENV} ${MAKE_ENV} npm run build
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/go-bindata -fs -prefix "resources" -tags embed -ignore="\\\*.go" -pkg resources -o resources/embedded_gen.go resources/...
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/go-bindata -fs -prefix "ui/build" -tags embed -nocompress -pkg assets -o assets/embedded_gen.go ui/build/...

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
