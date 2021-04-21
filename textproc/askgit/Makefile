PORTNAME=	askgit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.7
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Query git repositories with SQL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		go:modules pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	augmentable-dev
GH_TUPLE=	DATA-DOG:go-sqlmock:v1.5.0:data_dog_go_sqlmock/vendor/github.com/DATA-DOG/go-sqlmock \
		asaskevich:govalidator:7a23bdc65eef:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		gitsight:go-vcsurl:v1.0.0:gitsight_go_vcsurl/vendor/github.com/gitsight/go-vcsurl \
		go-openapi:errors:v0.19.9:go_openapi_errors/vendor/github.com/go-openapi/errors \
		go-openapi:strfmt:v0.19.11:go_openapi_strfmt/vendor/github.com/go-openapi/strfmt \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:eec23a3978ad:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:6772e930b67b:golang_net/vendor/golang.org/x/net \
		golang:oauth2:08078c50e5b5:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:09787c993a3a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:0d417f636930:golang_sys/vendor/golang.org/x/sys \
		golang:term:2321bbc49cbf:golang_term/vendor/golang.org/x/term \
		golang:time:7e3f01d25324:golang_time/vendor/golang.org/x/time \
		google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jedib0t:go-pretty:v4.3.0:jedib0t_go_pretty/vendor/github.com/jedib0t/go-pretty \
		jroimartin:gocui:v0.4.0:jroimartin_gocui/vendor/github.com/jroimartin/gocui \
		libgit2:git2go:v31.4.7:libgit2_git2go_v31/vendor/github.com/libgit2/git2go/v31 \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:mapstructure:v1.4.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mongodb:mongo-go-driver:v1.4.4:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		nsf:termbox-go:ed494de23a00:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		patrickdevivo:go-sqlite3:f024bb44eb6d:patrickdevivo_go_sqlite3/vendor/github.com/mattn/go-sqlite3 \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		spf13:cobra:v1.1.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag

GO_BUILDFLAGS=	-tags sqlite_vtable,sqlite_json1,system_libgit2
GO_TESTFLAGS=	${GO_BUILDFLAGS}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
