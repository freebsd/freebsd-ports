PORTNAME=	vuls
DISTVERSIONPREFIX=	v
DISTVERSION=		0.13.7
PORTREVISION=	4
CATEGORIES=	security

MAINTAINER=	iscandr@gmail.com
COMMENT=	Agentless vulnerability scanner

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/go-cve-dictionary:security/go-cve-dictionary

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	future-architect
GH_TUPLE=	\
		Azure:azure-sdk-for-go:v43.3.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:5bd9621f41a0:azure_go_autorest_date/vendor/github.com/Azure/go-autorest \
		Azure:go-autorest:aff029487b89:azure_go_autorest_adal \
		Azure:go-autorest:autorest/v0.9.3:azure_go_autorest_autorest \
		Azure:go-autorest:logger/v0.1.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.5.0:azure_go_autorest_tracing \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Masterminds:semver:v3.1.0:masterminds_semver_v3/vendor/github.com/Masterminds/semver/v3 \
		RackSec:srslog:a4725f04ec91:racksec_srslog/vendor/github.com/RackSec/srslog \
		VividCortex:ewma:v1.1.1:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		aquasecurity:bolt-fixtures:c0f517aea2ed:aquasecurity_bolt_fixtures/vendor/github.com/aquasecurity/bolt-fixtures \
		aquasecurity:fanal:6de62ef86882:aquasecurity_fanal/vendor/github.com/aquasecurity/fanal \
		aquasecurity:go-dep-parser:ea223f0ef24b:aquasecurity_go_dep_parser/vendor/github.com/aquasecurity/go-dep-parser \
		aquasecurity:trivy-db:6da6467703aa:aquasecurity_trivy_db/vendor/github.com/aquasecurity/trivy-db \
		aquasecurity:trivy:v0.12.0:aquasecurity_trivy/vendor/github.com/aquasecurity/trivy \
		asaskevich:govalidator:7a23bdc65eef:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		aws:aws-sdk-go:v1.33.21:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		boltdb:bolt:v1.3.1:boltdb_bolt/vendor/github.com/boltdb/bolt \
		briandowns:spinner:ac46072a5a91:briandowns_spinner/vendor/github.com/briandowns/spinner \
		caarlos0:env:v6.0.0:caarlos0_env_v6/vendor/github.com/caarlos0/env/v6 \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheggaaa:pb:v1.0.28:cheggaaa_pb/vendor/gopkg.in/cheggaaa/pb.v1 \
		cheggaaa:pb:v3.0.5:cheggaaa_pb_v3/vendor/github.com/cheggaaa/pb \
		d4l3k:messagediff:7e0a312ae40b:d4l3k_messagediff/vendor/github.com/d4l3k/messagediff \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dgryski:go-rendezvous:9f7001d12a5f:dgryski_go_rendezvous/vendor/github.com/dgryski/go-rendezvous \
		dominikh:go-tools:v0.0.1-2019.2.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		emersion:go-sasl:7bfe0ed36a21:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		emersion:go-smtp:v0.13.0:emersion_go_smtp/vendor/github.com/emersion/go-smtp \
		etcd-io:bbolt:v1.3.5:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		fatih:color:v1.10.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-redis:redis:v8.4.0:go_redis_redis_v8/vendor/github.com/go-redis/redis/v8 \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		goccy:go-yaml:v1.8.0:goccy_go_yaml/vendor/github.com/goccy/go-yaml \
		golang:appengine:v1.6.2:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:c1f2f97bffc9:golang_crypto/vendor/golang.org/x/crypto \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:net:69a78807bb2b:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:ba5294a509c7:golang_sys/vendor/golang.org/x/sys \
		golang:term:f5c789dd3221:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		golang:tools:1ace956b0e17:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-github:v28.1.1:google_go_github_v28/vendor/github.com/google/go-github/v28 \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:subcommands:v1.2.0:google_subcommands/vendor/github.com/google/subcommands \
		google:wire:v0.3.0:google_wire/vendor/github.com/google/wire \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		gosuri:uitable:v0.0.4:gosuri_uitable/vendor/github.com/gosuri/uitable \
		grokify:html-strip-tags-go:025bd760b278:grokify_html_strip_tags_go/vendor/github.com/grokify/html-strip-tags-go \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:go-version:v1.2.1:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		howeyc:gopass:7cb4b85ec19c:howeyc_gopass/vendor/github.com/howeyc/gopass \
		htcat:htcat:v1.0.2:htcat_htcat/vendor/github.com/htcat/htcat \
		inconshreveable:log15:8562bdadbbac:inconshreveable_log15/vendor/github.com/inconshreveable/log15 \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jesseduffield:gocui:v0.3.0:jesseduffield_gocui/vendor/github.com/jesseduffield/gocui \
		jinzhu:gorm:v1.9.16:jinzhu_gorm/vendor/github.com/jinzhu/gorm \
		jinzhu:inflection:v1.0.0:jinzhu_inflection/vendor/github.com/jinzhu/inflection \
		jmespath:go-jmespath:v0.3.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		k0kubun:pp:v3.0.1:k0kubun_pp/vendor/github.com/k0kubun/pp \
		knqyf263:go-apk-version:041fdbb8563f:knqyf263_go_apk_version/vendor/github.com/knqyf263/go-apk-version \
		knqyf263:go-cpe:659663f6eca2:knqyf263_go_cpe/vendor/github.com/knqyf263/go-cpe \
		knqyf263:go-deb-version:09fca494f03d:knqyf263_go_deb_version/vendor/github.com/knqyf263/go-deb-version \
		knqyf263:go-rpm-version:74609b86c936:knqyf263_go_rpm_version/vendor/github.com/knqyf263/go-rpm-version \
		knqyf263:gost:v0.1.7:knqyf263_gost/vendor/github.com/knqyf263/gost \
		konsorten:go-windows-terminal-sequences:v1.0.3:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kotakanbe:go-cve-dictionary:v0.5.5:kotakanbe_go_cve_dictionary/vendor/github.com/kotakanbe/go-cve-dictionary \
		kotakanbe:go-pingscanner:v0.1.0:kotakanbe_go_pingscanner/vendor/github.com/kotakanbe/go-pingscanner \
		kotakanbe:goval-dictionary:v0.2.15:kotakanbe_goval_dictionary/vendor/github.com/kotakanbe/goval-dictionary \
		kotakanbe:logrus-prefixed-formatter:928f7356cb96:kotakanbe_logrus_prefixed_formatter/vendor/github.com/kotakanbe/logrus-prefixed-formatter \
		kubernetes:utils:6e3d28b6ed19:kubernetes_utils/vendor/k8s.io/utils \
		labstack:gommon:v0.3.0:labstack_gommon/vendor/github.com/labstack/gommon \
		lib:pq:v1.8.0:lib_pq/vendor/github.com/lib/pq \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-colorable:v0.1.0:mattn_go_colorable_1/vendor/gopkg.in/mattn/go-colorable.v0 \
		mattn:go-colorable:v0.1.8:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty_1/vendor/github.com/mattn/go-isatty \
		mattn:go-isatty:v0.0.6:mattn_go_isatty/vendor/gopkg.in/mattn/go-isatty.v0 \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v2.0.3:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moul:http2curl:v1.0.0:moul_http2curl/vendor/moul.io/http2curl \
		mozqnet:go-exploitdb:v0.1.2:mozqnet_go_exploitdb/vendor/github.com/mozqnet/go-exploitdb \
		nlopes:slack:v0.6.0:nlopes_slack/vendor/github.com/nlopes/slack \
		nsf:termbox-go:38ba6e5628f1:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		olekukonko:tablewriter:v0.0.4:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		open-telemetry:opentelemetry-go:v0.14.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		parnurzeal:gorequest:v0.2.16:parnurzeal_gorequest/vendor/github.com/parnurzeal/gorequest \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rifflock:lfshook:b9218ef580f5:rifflock_lfshook/vendor/github.com/rifflock/lfshook \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		sirupsen:logrus:v1.6.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.3.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.0.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.0:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:objx:v0.3.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		takuzoo3868:go-msfdb:v0.1.3:takuzoo3868_go_msfdb/vendor/github.com/takuzoo3868/go-msfdb \
		uber-go:atomic:v1.5.1:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.4.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:tools:2cfd321de3ee:uber_go_tools/vendor/go.uber.org/tools \
		uber-go:zap:v1.13.0:uber_go_zap/vendor/go.uber.org/zap \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasttemplate:v1.2.1:valyala_fasttemplate/vendor/github.com/valyala/fasttemplate \
		ymomoi:goval-parser:0a0be1dd9d08:ymomoi_goval_parser/vendor/github.com/ymomoi/goval-parser

GO_TARGET=	./cmd/${PORTNAME}:${PREFIX}/bin/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"

PLIST_FILES=	bin/${PORTNAME} \
		"@sample ${ETCDIR}/config.toml.sample"

post-extract:
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/config.toml.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
