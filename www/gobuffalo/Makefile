# $FreeBSD$

PORTNAME=	gobuffalo
PORTVERSION=	0.14.5
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	dg@syrec.org
COMMENT=	Go web development eco-system, designed to make the life easier

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	go:lang/go \
		git:devel/git

USES=		go:modules

GO_PKGNAME=	github.com/gobuffalo/buffalo
GO_TARGET=	./buffalo
GO_BUILDFLAGS=	-tags "${TAGS}"

USE_GITHUB=	yes
GH_PROJECT=	buffalo
GH_SUBDIR=	src/github.com/gobuffalo/buffalo
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Masterminds:semver:v1.4.2:masterminds_semver/vendor/github.com/Masterminds/semver \
		alexcesaro:quotedprintable:2caba252f4dc:alexcesaro_quotedprintable/vendor/gopkg.in/alexcesaro/quotedprintable.v3 \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		cockroachdb:cockroach-go:e0a95dfd547c:cockroachdb_cockroach_go/vendor/github.com/cockroachdb/cockroach-go \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-sql-driver:mysql:v1.4.1:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:attrs:a9411de4debd:gobuffalo_attrs/vendor/github.com/gobuffalo/attrs \
		gobuffalo:buffalo-docker:v1.0.7:gobuffalo_buffalo_docker/vendor/github.com/gobuffalo/buffalo-docker \
		gobuffalo:buffalo-plugins:v1.14.1:gobuffalo_buffalo_plugins/vendor/github.com/gobuffalo/buffalo-plugins \
		gobuffalo:buffalo-pop:v1.12.0:gobuffalo_buffalo_pop/vendor/github.com/gobuffalo/buffalo-pop \
		gobuffalo:clara:v0.4.1:gobuffalo_clara/vendor/github.com/gobuffalo/clara \
		gobuffalo:depgen:v0.1.1:gobuffalo_depgen/vendor/github.com/gobuffalo/depgen \
		gobuffalo:envy:v1.7.0:gobuffalo_envy/vendor/github.com/gobuffalo/envy \
		gobuffalo:events:v1.3.1:gobuffalo_events/vendor/github.com/gobuffalo/events \
		gobuffalo:fizz:v1.8.0:gobuffalo_fizz/vendor/github.com/gobuffalo/fizz \
		gobuffalo:flect:v0.1.3:gobuffalo_flect/vendor/github.com/gobuffalo/flect \
		gobuffalo:genny:v0.1.1:gobuffalo_genny/vendor/github.com/gobuffalo/genny \
		gobuffalo:github_flavored_markdown:v1.0.7:gobuffalo_github_flavored_markdown/vendor/github.com/gobuffalo/github_flavored_markdown \
		gobuffalo:gogen:v0.1.1:gobuffalo_gogen/vendor/github.com/gobuffalo/gogen \
		gobuffalo:helpers:8e6f634af7c3:gobuffalo_helpers/vendor/github.com/gobuffalo/helpers \
		gobuffalo:logger:86e12af44bc2:gobuffalo_logger/vendor/github.com/gobuffalo/logger \
		gobuffalo:makr:v1.1.5:gobuffalo_makr/vendor/github.com/gobuffalo/makr \
		gobuffalo:mapi:v1.0.2:gobuffalo_mapi/vendor/github.com/gobuffalo/mapi \
		gobuffalo:meta:e161e8a93e3b:gobuffalo_meta/vendor/github.com/gobuffalo/meta \
		gobuffalo:nulls:85f3c9250d87:gobuffalo_nulls/vendor/github.com/gobuffalo/nulls \
		gobuffalo:packd:v0.1.0:gobuffalo_packd/vendor/github.com/gobuffalo/packd \
		gobuffalo:packr:v2.3.2:gobuffalo_packr/vendor/github.com/gobuffalo/packr \
		gobuffalo:plush:v3.8.2:gobuffalo_plush/vendor/github.com/gobuffalo/plush \
		gobuffalo:plushgen:v0.1.0:gobuffalo_plushgen/vendor/github.com/gobuffalo/plushgen \
		gobuffalo:pop:v4.11.0:gobuffalo_pop/vendor/github.com/gobuffalo/pop \
		gobuffalo:syncx:33c29581e754:gobuffalo_syncx/vendor/github.com/gobuffalo/syncx \
		gobuffalo:tags:v2.1.0:gobuffalo_tags/vendor/github.com/gobuffalo/tags \
		gobuffalo:uuid:v2.0.5:gobuffalo_uuid/vendor/github.com/gobuffalo/uuid \
		gobuffalo:validate:v2.0.3:gobuffalo_validate/vendor/github.com/gobuffalo/validate \
		gobuffalo:x:6bb134105960:gobuffalo_x/vendor/github.com/gobuffalo/x \
		gofrs:uuid:v3.2.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		golang:appengine:v1.6.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:f99c8df09eb5:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:f3200d17e092:golang_net/vendor/golang.org/x/net \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:06a5c4944438:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:tools:8aaa1484dc10:golang_tools/vendor/golang.org/x/tools \
		gorilla:context:v1.1.1:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:mux:v1.7.2:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:sessions:v1.1.3:gorilla_sessions/vendor/github.com/gorilla/sessions \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jackc:pgx:v3.3.0:jackc_pgx/vendor/github.com/jackc/pgx \
		jmoiron:sqlx:v1.2.0:jmoiron_sqlx/vendor/github.com/jmoiron/sqlx \
		joho:godotenv:v1.3.0:joho_godotenv/vendor/github.com/joho/godotenv \
		karrick:godirwalk:v1.10.3:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lib:pq:v1.0.0:lib_pq/vendor/github.com/lib/pq \
		magiconair:properties:v1.8.0:magiconair_properties/vendor/github.com/magiconair/properties \
		markbates:deplist:v1.1.3:markbates_deplist/vendor/github.com/markbates/deplist \
		markbates:going:v1.0.3:markbates_going/vendor/github.com/markbates/going \
		markbates:grift:v1.0.6:markbates_grift/vendor/github.com/markbates/grift \
		markbates:inflect:v1.0.4:markbates_inflect/vendor/github.com/markbates/inflect \
		markbates:oncer:bf2de49a0be2:markbates_oncer/vendor/github.com/markbates/oncer \
		markbates:refresh:v1.7.1:markbates_refresh/vendor/github.com/markbates/refresh \
		markbates:safe:v1.0.1:markbates_safe/vendor/github.com/markbates/safe \
		markbates:sigtx:v1.0.0:markbates_sigtx/vendor/github.com/markbates/sigtx \
		mattn:go-colorable:v0.1.1:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.7:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v1.10.0:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		microcosm-cc:bluemonday:v1.0.2:microcosm_cc_bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		monoculum:formam:bc555adff0cd:monoculum_formam/vendor/github.com/monoculum/formam \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		rogpeppe:go-internal:v1.3.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		serenize:snaker:a683aaf2d516:serenize_snaker/vendor/github.com/serenize/snaker \
		sergi:go-diff:v1.0.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sourcegraph:annotate:f4cad6c6324d:sourcegraph_annotate/vendor/github.com/sourcegraph/annotate \
		sourcegraph:syntaxhighlight:bd320f5d308e:sourcegraph_syntaxhighlight/vendor/github.com/sourcegraph/syntaxhighlight \
		spf13:afero:v1.2.1:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v0.0.4:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.4.0:spf13_viper/vendor/github.com/spf13/viper

PLIST_FILES=	bin/buffalo

OPTIONS_DEFINE=	SQLITE
OPTIONS_RADIO=	NODE
OPTIONS_RADIO_NODE=	NPM YARN
OPTIONS_DEFAULT=	SQLITE YARN

NPM_DESC=	Use npm package manager
YARN_DESC=	Use yarn package manager

SQLITE_VARS=	tags+=sqlite

NPM_RUN_DEPENDS=	npm>=0:www/npm
YARN_RUN_DEPENDS=	yarn>=0:www/yarn

.include <bsd.port.mk>
