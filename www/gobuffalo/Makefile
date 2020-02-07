# $FreeBSD$

PORTNAME=	gobuffalo
PORTVERSION=	0.15.5
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Go web development eco-system, designed to make the life easier

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	git:devel/git

USES=		go:modules,run

USE_GITHUB=	yes
GH_PROJECT=	buffalo
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Masterminds:semver:v1.5.0:masterminds_semver/vendor/github.com/Masterminds/semver \
		alexcesaro:quotedprintable:2caba252f4dc:alexcesaro_quotedprintable/vendor/gopkg.in/alexcesaro/quotedprintable.v3 \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		cockroachdb:cockroach-go:606b3d062051:cockroachdb_cockroach_go/vendor/github.com/cockroachdb/cockroach-go \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:attrs:v1.0.0:gobuffalo_attrs/vendor/github.com/gobuffalo/attrs \
		gobuffalo:buffalo-pop:v1.23.1:gobuffalo_buffalo_pop/vendor/github.com/gobuffalo/buffalo-pop \
		gobuffalo:clara:v0.10.1:gobuffalo_clara/vendor/github.com/gobuffalo/clara \
		gobuffalo:envy:v1.9.0:gobuffalo_envy/vendor/github.com/gobuffalo/envy \
		gobuffalo:events:v1.4.1:gobuffalo_events/vendor/github.com/gobuffalo/events \
		gobuffalo:fizz:v1.9.5:gobuffalo_fizz/vendor/github.com/gobuffalo/fizz \
		gobuffalo:flect:v0.2.0:gobuffalo_flect/vendor/github.com/gobuffalo/flect \
		gobuffalo:genny:v0.6.0:gobuffalo_genny/vendor/github.com/gobuffalo/genny \
		gobuffalo:github_flavored_markdown:v1.1.0:gobuffalo_github_flavored_markdown/vendor/github.com/gobuffalo/github_flavored_markdown \
		gobuffalo:helpers:v0.6.1:gobuffalo_helpers/vendor/github.com/gobuffalo/helpers \
		gobuffalo:here:v0.6.0:gobuffalo_here/vendor/github.com/gobuffalo/here \
		gobuffalo:httptest:v1.4.1:gobuffalo_httptest/vendor/github.com/gobuffalo/httptest \
		gobuffalo:logger:v1.0.3:gobuffalo_logger/vendor/github.com/gobuffalo/logger \
		gobuffalo:meta:v0.3.0:gobuffalo_meta/vendor/github.com/gobuffalo/meta \
		gobuffalo:nulls:v0.2.0:gobuffalo_nulls/vendor/github.com/gobuffalo/nulls \
		gobuffalo:packd:v1.0.0:gobuffalo_packd/vendor/github.com/gobuffalo/packd \
		gobuffalo:packr:v2.7.1:gobuffalo_packr/vendor/github.com/gobuffalo/packr \
		gobuffalo:plush:v3.8.3:gobuffalo_plush/vendor/github.com/gobuffalo/plush \
		gobuffalo:pop:v4.13.1:gobuffalo_pop/vendor/github.com/gobuffalo/pop \
		gobuffalo:tags:v3.1.0:gobuffalo_tags/vendor/github.com/gobuffalo/tags/v3 \
		gobuffalo:validate:v2.0.4:gobuffalo_validate/vendor/github.com/gobuffalo/validate \
		gobuffalo:validate:v3.1.0:gobuffalo_validate_1/vendor/github.com/gobuffalo/validate/v3 \
		gofrs:uuid:v3.2.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		golang:crypto:a0c6ece9d31a:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:16171245cfb2:golang_net/vendor/golang.org/x/net \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:d101bd2416d5:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:tools:ecb101ed6550:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.4.0:google_go_cmp/vendor/github.com/google/go-cmp \
		gorilla:mux:v1.7.3:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:sessions:v1.2.0:gorilla_sessions/vendor/github.com/gorilla/sessions \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jackc:chunkreader:v2.0.0:jackc_chunkreader/vendor/github.com/jackc/chunkreader/v2 \
		jackc:pgconn:v1.3.1:jackc_pgconn/vendor/github.com/jackc/pgconn \
		jackc:pgio:v1.0.0:jackc_pgio/vendor/github.com/jackc/pgio \
		jackc:pgpassfile:v1.0.0:jackc_pgpassfile/vendor/github.com/jackc/pgpassfile \
		jackc:pgproto3:v2.0.1:jackc_pgproto3/vendor/github.com/jackc/pgproto3/v2 \
		jmoiron:sqlx:v1.2.0:jmoiron_sqlx/vendor/github.com/jmoiron/sqlx \
		joho:godotenv:v1.3.0:joho_godotenv/vendor/github.com/joho/godotenv \
		karrick:godirwalk:v1.15.2:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lib:pq:v1.3.0:lib_pq/vendor/github.com/lib/pq \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		markbates:grift:v1.5.0:markbates_grift/vendor/github.com/markbates/grift \
		markbates:oncer:v1.0.0:markbates_oncer/vendor/github.com/markbates/oncer \
		markbates:refresh:v1.10.0:markbates_refresh/vendor/github.com/markbates/refresh \
		markbates:safe:v1.0.1:markbates_safe/vendor/github.com/markbates/safe \
		markbates:sigtx:v1.0.0:markbates_sigtx/vendor/github.com/markbates/sigtx \
		mattn:go-colorable:v0.1.4:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v2.0.3:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		microcosm-cc:bluemonday:v1.0.2:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		monoculum:formam:952f0766a724:monoculum_formam/vendor/github.com/monoculum/formam \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rogpeppe:go-internal:v1.5.2:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sourcegraph:annotate:f4cad6c6324d:sourcegraph_annotate/vendor/github.com/sourcegraph/annotate \
		sourcegraph:syntaxhighlight:bd320f5d308e:sourcegraph_syntaxhighlight/vendor/github.com/sourcegraph/syntaxhighlight \
		spf13:afero:v1.2.1:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.6.2:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv

GO_TARGET=	./buffalo
GO_BUILDFLAGS=	-tags "${TAGS}"

PLIST_FILES=	bin/buffalo

OPTIONS_DEFINE=	SQLITE
OPTIONS_DEFAULT=	SQLITE YARN
OPTIONS_RADIO=	NODE
OPTIONS_RADIO_NODE=	NPM YARN

NPM_DESC=	Use npm package manager
YARN_DESC=	Use yarn package manager

SQLITE_VARS=	tags+=sqlite

NPM_RUN_DEPENDS=	npm>=0:www/npm
YARN_RUN_DEPENDS=	yarn>=0:www/yarn

.include <bsd.port.mk>
