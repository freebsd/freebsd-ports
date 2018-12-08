# $FreeBSD$

PORTNAME=	semaphore
PORTVERSION=	2.4.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	ports@FreeBSD.org
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
		bugsnag:panicwrap:8a46439:panicwrap/src/github.com/bugsnag/panicwrap \
		go-sql-driver:mysql:8fefef0:gomysql/src/github.com/go-sql-driver/mysql \
		golang:protobuf:6a1fa94:protobuf/src/github.com/golang/protobuf \
		google:go-github:4c4aea2:gogithub/src/github.com/google/go-github \
		google:go-querystring:53e6ce1:querystring/src/github.com/google/go-querystring \
		gorilla:securecookie:e59506c:securecookie/src/github.com/gorilla/securecookie \
		gorilla:websocket:7a8dacf:websocket/src/github.com/gorilla/websocket \
		kardianos:osext:ae77be6:osext/src/github.com/kardianos/osext \
		manucorporat:sse:ee05b12:sse/src/github.com/manucorporat/sse \
		masterminds:squirrel:36d675d:squirrel/src/github.com/masterminds/squirrel \
		lann:builder:f22ce00:builder/src/github.com/lann/builder \
		lann:ps:62de8c4:ps/src/github.com/lann/ps \
		mattn:go-isatty:fc9e8d8:go_isatty/src/github.com/mattn/go-isatty \
		russross:blackfriday:0ba0f2b:blackfriday/src/github.com/russross/blackfriday \
		shurcooL:sanitized_anchor_name:541ff5e:sanitized/src/github.com/shurcooL/sanitized_anchor_name \
		golang:net:1f92242:net/src/golang.org/x/net \
		golang:crypto:5ef0053:crypto/src/golang.org/x/crypto \
		go-playground:validator:fb68f39:playground/src/gopkg.in/go-playground/validator.v8 \
		go-gorp:gorp:2ae7d17:gorp/src/gopkg.in/gorp.v1 \
		go-yaml:yaml:e72f935:yaml/src/gopkg.in/yaml.v2 \
		Sirupsen:logrus:e66f229:logrus/src/github.com/Sirupsen/logrus \
		castawaylabs:mulekick:3a31c4b:mulekick/src/github.com/castawaylabs/mulekick \
		gorilla:context:aed02d1:context/src/github.com/gorilla/context \
		gorilla:mux:8c683ee:mux/src/github.com/gorilla/mux \
		gorilla:handlers:a4d79d4:handlers/src/github.com/gorilla/handlers \
		golang:sys:0e01648:sys/src/golang.org/x/sys \
		go-ldap:ldap:37f35d7:ldap2/src/gopkg.in/ldap.v2 \
		go-asn1-ber:asn1-ber:379148c:asn1/src/gopkg.in/asn1-ber.v1

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
