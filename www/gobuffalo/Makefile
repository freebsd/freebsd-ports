# $FreeBSD$

PORTNAME=	gobuffalo
PORTVERSION=	0.10.3
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Go web development eco-system, designed to make the life easier

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go
RUN_DEPENDS=	yarn>=0:www/yarn \
		${LOCALBASE}/bin/go:lang/go \
		git>=2.14.1:devel/git

USE_GITHUB=	yes
GH_PROJECT=	buffalo
GH_TUPLE=	\
		cockroachdb:cockroach-go:0d8b468:cockroach/vendor/github.com/cockroachdb/cockroach-go \
		daviddengcn:go-colortext:17e75f6:colortext/vendor/github.com/daviddengcn/go-colortext \
		dustin:go-humanize:bb3d318:humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:5df930a:color/vendor/github.com/fatih/color \
		fatih:structs:ebf56d3:structs/vendor/github.com/fatih/structs \
		fsnotify:fsnotify:c282820:fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-sql-driver:mysql:bc14601:gmysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:d670f94:yaml/src/gopkg.in/yaml.v2 \
		gobuffalo:envy:bac51f7:envy/vendor/github.com/gobuffalo/envy \
		gobuffalo:makr:aea1794:makr/vendor/github.com/gobuffalo/makr \
		gobuffalo:packr:64c3dd4:packr/vendor/github.com/gobuffalo/packr \
		gobuffalo:plush:ea63b97:plush/vendor/github.com/gobuffalo/plush \
		gobuffalo:tags:77cf949:tags/vendor/github.com/gobuffalo/tags \
		gobuffalo:x:11ca13c:https/vendor/github.com/gobuffalo/x \
		golang:crypto:9334d73:crypto/vendor/golang.org/x/crypto \
		gorilla:context:08b5f42:context/vendor/github.com/gorilla/context \
		gorilla:mux:c0091a0:mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:e59506c:securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:sessions:41ee504:sessions/vendor/github.com/gorilla/sessions \
		gorilla:websocket:4ac9097:websocket/vendor/github.com/gorilla/websocket \
		jmoiron:sqlx:05cef07:sqlx/vendor/github.com/jmoiron/sqlx \
		joho:godotenv:6bb0851:godotenv/vendor/github.com/joho/godotenv \
		lib:pq:88edab0:libpq/vendor/github.com/lib/pq \
		markbates:deplist:5ae023f:deplist/vendor/github.com/markbates/deplist \
		markbates:going:0576708:going/vendor/github.com/markbates/going \
		markbates:grift:5499956:grift/vendor/github.com/markbates/grift \
		markbates:inflect:1290f21:inflect/vendor/github.com/markbates/inflect \
		markbates:pop:2a4f22c:pop/vendor/github.com/markbates/pop \
		markbates:refresh:c22826c:refresh/vendor/github.com/markbates/refresh \
		markbates:sigtx:1c5462d:sigtx/vendor/github.com/markbates/sigtx \
		markbates:validate:cd8cc34:validate/vendor/github.com/markbates/validate \
		mattn:anko:fc8950f:anko/vendor/github.com/mattn/anko \
		mattn:go-sqlite3:3c6eef4:sqlite3/vendor/github.com/mattn/go-sqlite3 \
		microcosm-cc:bluemonday:542fd46:bluemonday/vendor/github.com/microcosm-cc/bluemonday \
		mitchellh:go-homedir:b8bc1bf:ghomedir/vendor/github.com/mitchellh/go-homedir \
		monoculum:formam:f25191a:formam/vendor/github.com/monoculum/formam \
		nicksnyder:go-i18n:ec04da4:i18n/vendor/github.com/nicksnyder/go-i18n \
		pkg:errors:30136e2:errors/vendor/github.com/pkg/errors \
		satori:go.uuid:36e9d2e:guuid/vendor/github.com/satori/go.uuid \
		serenize:snaker:a683aaf:snaker/vendor/github.com/serenize/snaker \
		sergi:go-diff:da64554:gdiff/vendor/github.com/sergi/go-diff \
		shurcooL:github_flavored_markdown:28433ea:gfm/vendor/github.com/shurcooL/github_flavored_markdown \
		shurcooL:highlight_diff:09bb405:hdiff/vendor/github.com/shurcooL/highlight_diff \
		shurcooL:highlight_go:78fb10f:hgo/vendor/github.com/shurcooL/highlight_go \
		shurcooL:octiconssvg:38b0212:osvg/vendor/github.com/shurcooL/octiconssvg \
		shurcooL:sanitized_anchor_name:86672fc:sanitized/vendor/github.com/shurcooL/sanitized_anchor_name \
		sirupsen:logrus:9f91ab2:logrus/vendor/github.com/sirupsen/logrus \
		sourcegraph:annotate:f4cad6c:annotate/vendor/github.com/sourcegraph/annotate \
		sourcegraph:syntaxhighlight:bd320f5:syntaxhighlight/vendor/github.com/sourcegraph/syntaxhighlight \
		spf13:cobra:9395926:cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:4c012f6:pflag/vendor/github.com/spf13/pflag \
		unrolled:secure:5b5ec9d:secure/vendor/github.com/unrolled/secure \
		pelletier:go-toml:acdc450:gotom/vendor/github.com/pelletier/go-toml \
		golang:net:f5dfe33:net/vendor/golang.org/x/net \
		golang:sync:fd80eb9:sync/vendor/golang.org/x/sync \
		golang:sys:37707fd:sys/vendor/golang.org/x/sys \
		go-mail:mail:c1980b5:gomail/vendor/gopkg.in/mail.v2

GH_SUBDIR=	src/github.com/gobuffalo/buffalo

PLIST_FILES=	bin/buffalo

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR}/buffalo ; ${SETENV} GOPATH=${WRKSRC} go build

post-build:
	@${STRIP_CMD} ${WRKSRC}/${GH_SUBDIR}/buffalo/buffalo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${GH_SUBDIR}/buffalo/buffalo \
		${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
