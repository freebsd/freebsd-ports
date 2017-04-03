# $FreeBSD$

PORTNAME=	semaphore
PORTVERSION=	2.2.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Open Source alternative to Ansible Tower

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go \
		${LOCALBASE}/bin/go-bindata:devel/go-bindata \
		npm>=0:www/npm
RUN_DEPENDS=	ansible:sysutils/ansible \
		git:devel/git

USE_GITHUB=	yes
GH_SUBDIR=	src/github.com/ansible-semaphore/semaphore
GH_ACCOUNT=	ansible-semaphore
GH_TUPLE=	ansible-semaphore:semaphore-vendor:dcb3abe:vendor/public/vendor \
		swills:semaphore-node_modules:v${PORTVERSION}:modules/public/node_modules \
		swills:semaphore-rendered_files:v${PORTVERSION}:render/public.rendered \
		bugsnag:bugsnag-go:70e1420:bugsnag/src/github.com/bugsnag/bugsnag-go \
		bugsnag:panicwrap:aa7703c:panicwrap/src/github.com/bugsnag/panicwrap \
		gin-gonic:gin:e2212d4:gonic/src/github.com/gin-gonic/gin \
		go-sql-driver:mysql:9dee4ca:gomysql/src/github.com/go-sql-driver/mysql \
		golang:protobuf:c9c7427:protobuf/src/github.com/golang/protobuf \
		google:go-github:d683a1c:gogithub/src/github.com/google/go-github \
		google:go-querystring:53e6ce1:querystring/src/github.com/google/go-querystring \
		gorilla:securecookie:e59506c:securecookie/src/github.com/gorilla/securecookie \
		gorilla:websocket:a91eba7:websocket/src/github.com/gorilla/websocket \
		kardianos:osext:9d302b5:osext/src/github.com/kardianos/osext \
		manucorporat:sse:ee05b12:sse/src/github.com/manucorporat/sse \
		masterminds:squirrel:20f1922:squirrel/src/github.com/masterminds/squirrel \
		lann:builder:f22ce00:builder/src/github.com/lann/builder \
		lann:ps:62de8c4:ps/src/github.com/lann/ps \
		mattn:go-isatty:fc9e8d8:go_isatty/src/github.com/mattn/go-isatty \
		russross:blackfriday:5f33e7b:blackfriday/src/github.com/russross/blackfriday \
		shurcooL:sanitized_anchor_name:1dba4b3:sanitized/src/github.com/shurcooL/sanitized_anchor_name \
		golang:net:6c23252:net/src/golang.org/x/net \
		golang:crypto:459e265:crypto/src/golang.org/x/crypto \
		go-playground:validator:5f57d22:playground/src/gopkg.in/go-playground/validator.v8 \
		go-gorp:gorp:c87af80:gorp/src/gopkg.in/gorp.v1 \
		go-yaml:yaml:a3f3340:yaml/src/gopkg.in/yaml.v2

PLIST_FILES=	bin/semaphore \
		"@sample etc/semaphore/semaphore_config.json.sample"

USE_RC_SUBR=	semaphore

post-patch:
	@${CP} -R ${WRKSRC}/public.rendered/public/ ${WRKSRC}/public/

do-build:
	@(cd ${WRKSRC}/public ; node ./bundler.js )
	@(cd ${WRKSRC} ; go-bindata -o util/bindata.go -pkg util config.json db/migrations/ public/css public/html public/html/projects public/html/projects/repositories public/html/projects/inventory public/html/projects/templates public/html/projects/users public/html/projects/environment public/html/projects/keys public/html/users public/html/auth public/img public/js public/js/services public/js/controllers public/js/controllers/projects public/js/routes public/js/factories public/node_modules public/node_modules/lodash public/node_modules/lodash/fp public/node_modules/async public/node_modules/async/dist public/node_modules/async/internal public/vendor public/vendor/fontawesome public/vendor/fontawesome/less public/vendor/fontawesome/fonts public/vendor/sweetalert public/vendor/moment public/vendor/bootstrap public/vendor/bootstrap/fonts public/vendor/bootstrap/dist public/vendor/bootstrap/dist/css public/vendor/bootstrap/dist/fonts public/vendor/bootstrap/dist/js public/vendor/bootstrap/less public/vendor/bootstrap/less/mixins public/vendor/angular-loading-bar )
	@(cd ${WRKSRC}/cli ; ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build -o semaphore ./... )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cli/semaphore ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/semaphore
	${CP} ${WRKSRC}/config.json ${STAGEDIR}${PREFIX}/etc/semaphore/semaphore_config.json.sample

.include <bsd.port.mk>
