# $FreeBSD$

PORTNAME=	gobuffalo
PORTVERSION=	0.12.6
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	dg@syrec.org
COMMENT=	Go web development eco-system, designed to make the life easier

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	go>=1.8.1:lang/go
RUN_DEPENDS=	yarn>=0:www/yarn \
		go>=1.8.1:lang/go \
		git>=2.14.1:devel/git

USE_GITHUB=	yes
GH_PROJECT=	buffalo
GH_SUBDIR=	src/github.com/gobuffalo/buffalo
GH_TUPLE=	\
		cockroachdb:cockroach-go:59c0560:cockroach/vendor/github.com/cockroachdb/cockroach-go \
		dustin:go-humanize:9f541cc:humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:v1.7.0:color/vendor/github.com/fatih/color \
		fatih:structs:v1.0.0:structs/vendor/github.com/fatih/structs \
		fsnotify:fsnotify:v1.4.7:fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-mail:mail:2.0.0:gomail/vendor/gopkg.in/mail.v2 \
		go-sql-driver:mysql:v1.4.0:gmysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:v2.2.1:yaml/src/gopkg.in/yaml.v2 \
		gobuffalo:envy:v1.6.3:envy/vendor/github.com/gobuffalo/envy \
		gobuffalo:fizz:v1.0.7:fizz/vendor/github.com/gobuffalo/fizz \
		gobuffalo:github_flavored_markdown:v1.0.0:github_flavored_markdown/vendor/github.com/gobuffalo/github_flavored_markdown \
		gobuffalo:makr:v1.1.1:makr/vendor/github.com/gobuffalo/makr \
		gobuffalo:packr:v1.13.1:packr/vendor/github.com/gobuffalo/packr \
		gobuffalo:plush:2745528:plush/vendor/github.com/gobuffalo/plush \
		gobuffalo:pop:9f8bf0c:pop/vendor/github.com/gobuffalo/pop \
		gobuffalo:tags:v2.0.8:tags/vendor/github.com/gobuffalo/tags \
		gobuffalo:uuid:v2.0.2:uuid/vendor/github.com/gobuffalo/uuid \
		gobuffalo:validate:v2.0.0:validate/vendor/github.com/gobuffalo/validate \
		gobuffalo:x:11ca13c:https/vendor/github.com/gobuffalo/x \
		golang:crypto:de07523:crypto/vendor/golang.org/x/crypto \
		golang:net:c394268:net/vendor/golang.org/x/net \
		golang:sync:1d60e46:sync/vendor/golang.org/x/sync \
		golang:sys:4e1fef5:sys/vendor/golang.org/x/sys \
		gorilla:context:v1.1.1:context/vendor/github.com/gorilla/context \
		gorilla:mux:v1.6.2:mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:sessions:v1.1.1:sessions/vendor/github.com/gorilla/sessions \
		jmoiron:sqlx:0dae4fe:sqlx/vendor/github.com/jmoiron/sqlx \
		joho:godotenv:v1.2.0:godotenv/vendor/github.com/joho/godotenv \
		lib:pq:90697d6:libpq/vendor/github.com/lib/pq \
		markbates:deplist:v1.0.2:deplist/vendor/github.com/markbates/deplist \
		markbates:going:v1.0.1:going/vendor/github.com/markbates/going \
		markbates:grift:v1.0.1:grift/vendor/github.com/markbates/grift \
		markbates:inflect:v1.0.0:inflect/vendor/github.com/markbates/inflect \
		markbates:refresh:v1.4.1:refresh/vendor/github.com/markbates/refresh \
		markbates:sigtx:v1.0.0:sigtx/vendor/github.com/markbates/sigtx \
		mattn:go-colorable:v0.0.9:sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mattn:go-isatty:v0.0.3:sqlite3/vendor/github.com/mattn/go-sqlite3 \
		mattn:go-sqlite3:v1.9.0:sqlite3/vendor/github.com/mattn/go-sqlite3 \
		microcosm-cc:bluemonday:v1.0.0:bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mitchellh:go-homedir:5804607:ghomedir/vendor/github.com/mitchellh/go-homedir \
		monoculum:formam:99ca9dc:formam/vendor/github.com/monoculum/formam \
		nicksnyder:go-i18n:v1.10.0:i18n/vendor/github.com/nicksnyder/go-i18n \
		pelletier:go-toml:v1.2.0:gotom/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.0:errors/vendor/github.com/pkg/errors \
		russross:blackfriday:v1.5.1:blackfriday/vendor/gopkg.in/russross/blackfriday.v1 \
		serenize:snaker:a683aaf:snaker/vendor/github.com/serenize/snaker \
		sergi:go-diff:v1.0.0:gdiff/vendor/github.com/sergi/go-diff \
		shurcooL:github_flavored_markdown:8913699:gfm/vendor/github.com/shurcooL/github_flavored_markdown \
		shurcooL:highlight_diff:09bb405:hdiff/vendor/github.com/shurcooL/highlight_diff \
		shurcooL:highlight_go:78fb10f:hgo/vendor/github.com/shurcooL/highlight_go \
		shurcooL:octicon:c42b0e3:osvg/vendor/github.com/shurcooL/octicon \
		shurcooL:sanitized_anchor_name:86672fc:sanitized/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:v1.0.6:logrus/vendor/github.com/sirupsen/logrus \
		sourcegraph:annotate:f4cad6c:annotate/vendor/github.com/sourcegraph/annotate \
		sourcegraph:syntaxhighlight:bd320f5:syntaxhighlight/vendor/github.com/sourcegraph/syntaxhighlight \
		spf13:cobra:v0.0.3:cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.2:pflag/vendor/github.com/spf13/pflag \
		unrolled:secure:8287f38:secure/vendor/github.com/unrolled/secure

PLIST_FILES=	bin/buffalo

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR}/buffalo ; ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build

post-build:
	@${STRIP_CMD} ${WRKSRC}/${GH_SUBDIR}/buffalo/buffalo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${GH_SUBDIR}/buffalo/buffalo \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
