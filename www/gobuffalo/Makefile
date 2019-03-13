# $FreeBSD$

PORTNAME=	gobuffalo
PORTVERSION=	0.14.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	dg@syrec.org
COMMENT=	Go web development eco-system, designed to make the life easier

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	go>=1.9.7:lang/go
RUN_DEPENDS=	go>=1.9.7:lang/go \
		git>=2.14.1:devel/git

USE_GITHUB=	yes
GH_PROJECT=	buffalo
GH_SUBDIR=	src/github.com/gobuffalo/buffalo
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/src/github.com/BurntSushi/toml \
		alexcesaro:quotedprintable:2caba25:alexcesaro_quotedprintable/src/gopkg.in/alexcesaro/quotedprintable.v3 \
		blang:semver:v3.5.1:blang_semver/src/github.com/blang/semver \
		cockroachdb:cockroach-go:e0a95df:cockroachdb_cockroach_go/src/github.com/cockroachdb/cockroach-go \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/src/github.com/dustin/go-humanize \
		fatih:color:v1.7.0:fatih_color/src/github.com/fatih/color \
		fatih:structs:v1.1.0:fatih_structs/src/github.com/fatih/structs \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/src/github.com/fsnotify/fsnotify \
		go-sql-driver:mysql:v1.4.1:go_sql_driver_mysql/src/github.com/go-sql-driver/mysql \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/src/gopkg.in/yaml.v2 \
		gobuffalo:attrs:a9411de:gobuffalo_attrs/src/github.com/gobuffalo/attrs \
		gobuffalo:buffalo-docker:v1.0.6:gobuffalo_buffalo_docker/src/github.com/gobuffalo/buffalo-docker \
		gobuffalo:buffalo-plugins:v1.13.1:gobuffalo_buffalo_plugins/src/github.com/gobuffalo/buffalo-plugins \
		gobuffalo:buffalo-pop:v1.9.0:gobuffalo_buffalo_pop/src/github.com/gobuffalo/buffalo-pop \
		gobuffalo:depgen:d0846c3:gobuffalo_depgen/src/github.com/gobuffalo/depgen \
		gobuffalo:envy:v1.6.15:gobuffalo_envy/src/github.com/gobuffalo/envy \
		gobuffalo:events:v1.2.0:gobuffalo_events/src/github.com/gobuffalo/events \
		gobuffalo:fizz:v1.5.1:gobuffalo_fizz/src/github.com/gobuffalo/fizz \
		gobuffalo:flect:v0.1.0:gobuffalo_flect/src/github.com/gobuffalo/flect \
		gobuffalo:genny:f262bb0:gobuffalo_genny/src/github.com/gobuffalo/genny \
		gobuffalo:github_flavored_markdown:v1.0.7:gobuffalo_github_flavored_markdown/src/github.com/gobuffalo/github_flavored_markdown \
		gobuffalo:gogen:1c60761:gobuffalo_gogen/src/github.com/gobuffalo/gogen \
		gobuffalo:logger:be78ebf:gobuffalo_logger/src/github.com/gobuffalo/logger \
		gobuffalo:makr:v1.1.5:gobuffalo_makr/src/github.com/gobuffalo/makr \
		gobuffalo:mapi:v1.0.1:gobuffalo_mapi/src/github.com/gobuffalo/mapi \
		gobuffalo:meta:50a99e0:gobuffalo_meta/src/github.com/gobuffalo/meta \
		gobuffalo:nulls:85f3c92:gobuffalo_nulls/src/github.com/gobuffalo/nulls \
		gobuffalo:packd:d04dd98:gobuffalo_packd/src/github.com/gobuffalo/packd \
		gobuffalo:packr:v1.22.0:gobuffalo_packr/src/github.com/gobuffalo/packr \
		gobuffalo:plush:v3.7.33:gobuffalo_plush/src/github.com/gobuffalo/plush \
		gobuffalo:plushgen:347ea23:gobuffalo_plushgen/src/github.com/gobuffalo/plushgen \
		gobuffalo:pop:v4.10.0:gobuffalo_pop/src/github.com/gobuffalo/pop \
		gobuffalo:syncx:558ac7d:gobuffalo_syncx/src/github.com/gobuffalo/syncx \
		gobuffalo:tags:v2.0.15:gobuffalo_tags/src/github.com/gobuffalo/tags \
		gobuffalo:uuid:v2.0.5:gobuffalo_uuid/src/github.com/gobuffalo/uuid \
		gobuffalo:validate:v2.0.3:gobuffalo_validate/src/github.com/gobuffalo/validate \
		gobuffalo:x:6bb1341:gobuffalo_x/src/github.com/gobuffalo/x \
		gofrs:uuid:v3.2.0:gofrs_uuid/src/github.com/gofrs/uuid \
		golang:appengine:v1.4.0:golang_appengine/src/google.golang.org/appengine \
		golang:crypto:8dd112b:golang_crypto/src/golang.org/x/crypto \
		golang:net:3a22650:golang_net/src/golang.org/x/net \
		golang:sync:e225da7:golang_sync/src/golang.org/x/sync \
		golang:sys:a9d3bda:golang_sys/src/golang.org/x/sys \
		golang:text:17ff2d5:golang_text/src/golang.org/x/text \
		golang:tools:00c44ba:golang_tools/src/golang.org/x/tools \
		gorilla:context:v1.1.1:gorilla_context/src/github.com/gorilla/context \
		gorilla:mux:v1.7.0:gorilla_mux/src/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/src/github.com/gorilla/securecookie \
		gorilla:sessions:v1.1.3:gorilla_sessions/src/github.com/gorilla/sessions \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/src/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/src/github.com/inconshreveable/mousetrap \
		jackc:pgx:v3.3.0:jackc_pgx/src/github.com/jackc/pgx \
		jmoiron:sqlx:v1.2.0:jmoiron_sqlx/src/github.com/jmoiron/sqlx \
		joho:godotenv:v1.3.0:joho_godotenv/src/github.com/joho/godotenv \
		karrick:godirwalk:v1.8.0:karrick_godirwalk/src/github.com/karrick/godirwalk \
		kballard:go-shellquote:95032a8:kballard_go_shellquote/src/github.com/kballard/go-shellquote \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/src/github.com/konsorten/go-windows-terminal-sequences \
		lib:pq:v1.0.0:lib_pq/src/github.com/lib/pq \
		magiconair:properties:v1.8.0:magiconair_properties/src/github.com/magiconair/properties \
		markbates:deplist:v1.1.3:markbates_deplist/src/github.com/markbates/deplist \
		markbates:going:v1.0.3:markbates_going/src/github.com/markbates/going \
		markbates:grift:v1.0.5:markbates_grift/src/github.com/markbates/grift \
		markbates:inflect:v1.0.4:markbates_inflect/src/github.com/markbates/inflect \
		markbates:oncer:bf2de49:markbates_oncer/src/github.com/markbates/oncer \
		markbates:refresh:v1.7.1:markbates_refresh/src/github.com/markbates/refresh \
		markbates:safe:v1.0.1:markbates_safe/src/github.com/markbates/safe \
		markbates:sigtx:v1.0.0:markbates_sigtx/src/github.com/markbates/sigtx \
		mattn:go-colorable:v0.1.1:mattn_go_colorable/src/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.5:mattn_go_isatty/src/github.com/mattn/go-isatty \
		mattn:go-sqlite3:v1.10.0:mattn_go_sqlite3/src/github.com/mattn/go-sqlite3 \
		microcosm-cc:bluemonday:v1.0.2:microcosm_cc_bluemonday/src/github.com/microcosm-cc/bluemonday \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/src/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/src/github.com/mitchellh/mapstructure \
		monoculum:formam:bc555ad:monoculum_formam/src/github.com/monoculum/formam \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/src/github.com/pelletier/go-toml \
		pkg:errors:v0.8.1:pkg_errors/src/github.com/pkg/errors \
		rogpeppe:go-internal:v1.2.2:rogpeppe_go_internal/src/github.com/rogpeppe/go-internal \
		serenize:snaker:a683aaf:serenize_snaker/src/github.com/serenize/snaker \
		sergi:go-diff:v1.0.0:sergi_go_diff/src/github.com/sergi/go-diff \
		sirupsen:logrus:v1.3.0:sirupsen_logrus/src/github.com/sirupsen/logrus \
		sourcegraph:annotate:f4cad6c:sourcegraph_annotate/src/github.com/sourcegraph/annotate \
		sourcegraph:syntaxhighlight:bd320f5:sourcegraph_syntaxhighlight/src/github.com/sourcegraph/syntaxhighlight \
		spf13:afero:v1.2.1:spf13_afero/src/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/src/github.com/spf13/cast \
		spf13:cobra:v0.0.3:spf13_cobra/src/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/src/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/src/github.com/spf13/pflag \
		spf13:viper:v1.3.1:spf13_viper/src/github.com/spf13/viper

PLIST_FILES=	bin/buffalo

OPTIONS_RADIO=	NODE
OPTIONS_RADIO_NODE=	NPM YARN
OPTIONS_DEFAULT=	YARN

NPM_DESC=	Use npm package manager
YARN_DESC=	Use yarn package manager

NPM_RUN_DEPENDS=	npm>=0:www/npm
YARN_RUN_DEPENDS=	yarn>=0:www/yarn

do-build:
	cd ${WRKSRC}/${GH_SUBDIR}/buffalo ; ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${GH_SUBDIR}/buffalo/buffalo \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
