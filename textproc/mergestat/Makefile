PORTNAME=	mergestat
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.6
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Query git repositories with SQL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2
BUILD_DEPENDS=	sqlite3>=3.0.0:databases/sqlite3

USES=		go:modules pkgconfig
USE_GITHUB=	yes
GH_TUPLE=	BurntSushi:toml:v0.4.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		DATA-DOG:go-sqlmock:v1.5.0:data_dog_go_sqlmock/vendor/github.com/DATA-DOG/go-sqlmock \
		Microsoft:go-winio:v0.5.0:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:52430bf6b52c:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		acomagu:bufpipe:v1.0.3:acomagu_bufpipe/vendor/github.com/acomagu/bufpipe \
		asaskevich:govalidator:f21760c49a8d:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		augmentable-dev:vtab:5c7659b723dd:augmentable_dev_vtab/vendor/github.com/augmentable-dev/vtab \
		clbanning:mxj:v2.5.5:clbanning_mxj_v2/vendor/github.com/clbanning/mxj/v2 \
		dnaeon:go-vcr:v2.0.1:dnaeon_go_vcr_v2/vendor/github.com/dnaeon/go-vcr \
		emirpasic:gods:v1.12.0:emirpasic_gods/vendor/github.com/emirpasic/gods \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-enry:go-enry:v2.7.1:go_enry_go_enry_v2/vendor/github.com/go-enry/go-enry/v2 \
		go-enry:go-oniguruma:v1.2.1:go_enry_go_oniguruma/vendor/github.com/go-enry/go-oniguruma \
		go-git:gcfg:v1.5.0:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.3.1:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.4.2:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-openapi:errors:v0.20.0:go_openapi_errors/vendor/github.com/go-openapi/errors \
		go-openapi:strfmt:v0.20.1:go_openapi_strfmt/vendor/github.com/go-openapi/strfmt \
		go-stack:stack:v1.8.1:go_stack_stack/vendor/github.com/go-stack/stack \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:32db794688a5:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.5.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:60bc85c4be6d:golang_net/vendor/golang.org/x/net \
		golang:oauth2:2bc19b11175f:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:41cdb8703e55:golang_sys/vendor/golang.org/x/sys \
		golang:term:6886f2dfbf5b:golang_term/vendor/golang.org/x/term \
		golang:time:1f47c861a9ac:golang_time/vendor/golang.org/x/time \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		imdario:mergo:v0.3.12:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		jedib0t:go-pretty:v4.3.0:jedib0t_go_pretty/vendor/github.com/jedib0t/go-pretty \
		kevinburke:ssh_config:v1.1.0:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		lib:pq:v1.10.2:lib_pq/vendor/github.com/lib/pq \
		libgit2:git2go:v31.4.14:libgit2_git2go_v31/vendor/github.com/libgit2/git2go/v31 \
		mattn:go-pointer:v0.0.1:mattn_go_pointer/vendor/github.com/mattn/go-pointer \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mattn:go-sqlite3:v1.14.8:mattn_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.4.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mongodb:mongo-go-driver:v1.7.1:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		oklog:ulid:v1.3.1:oklog_ulid/vendor/github.com/oklog/ulid \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		riyaz-ali:sqlite:b3ba44e2587a:riyaz_ali_sqlite/vendor/go.riyazali.net/sqlite \
		sergi:go-diff:v1.2.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		shurcooL:githubv4:83ba7b4c9228:shurcool_githubv4/vendor/github.com/shurcooL/githubv4 \
		shurcooL:graphql:18c5c3165e3a:shurcool_graphql/vendor/github.com/shurcooL/graphql \
		spf13:cobra:v1.2.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.6.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.17.0:uber_go_zap/vendor/go.uber.org/zap \
		xanzy:ssh-agent:v0.3.1:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent

GO_BUILDFLAGS=	-tags sqlite_vtable,sqlite_json1,system_libgit2
GO_TESTFLAGS=	${GO_BUILDFLAGS}

CGO_CFLAGS+=	-DUSE_LIBSQLITE3
CGO_LDFLAGS+=	-Wl,--unresolved-symbols=ignore-in-object-files

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
