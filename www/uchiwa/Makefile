# $FreeBSD$

PORTNAME=		uchiwa
PORTVERSION=	0.18.2
CATEGORIES=		www
MASTER_SITES=	http://uchiwa.io/

MAINTAINER=	alexander@treg.io
COMMENT=	Simple dashboard for Sensu

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.6.0:lang/go

UCHIWA_LOGDIR=		/var/log/uchiwa
UCHIWA_CONFDIR=		${PREFIX}/etc/uchiwa
UCHIWA_SHAREDIR=	${PREFIX}/share/uchiwa/public

USE_RC_SUBR=	${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	sensu:DEFAULT
GH_TUPLE=	dgrijalva:jwt-go:61124b62ad244d655f87d944aefaa2ae5a0d2f16:jwtgo/src/github.com/dgrijalva/jwt-go
GH_TUPLE+=	gorilla:context:215affda49addc4c8ef7e2534915df2c8c35c6cd:context/src/github.com/gorilla/context
GH_TUPLE+=	mitchellh:mapstructure:f7d28d5aeab42b9b95d2e6d6b956f73a290077fc:mapstructure/src/github.com/mitchellh/mapstructure
GH_TUPLE+=	palourde:mergo:d931ffd2c07cb4caf7194e0f6af9ac6771c26d54:mergo/src/github.com/palourde/mergo
GH_TUPLE+=	stretchr:objx:cbeaeb16a013161a98496fad62933b1d21786672:objx/src/github.com/stretchr/objx
GH_TUPLE+=	stretchr:testify:e4ec8152c15fc46bd5056ce65997a07c7d415325:testify/src/github.com/stretchr/testify
GH_TUPLE+=	sensu:uchiwa-web:${PORTVERSION}:uchiwaweb/public/bower_components/uchiwa-web
GH_TUPLE+=	angular:bower-angular-cookies:b89821e37d3011ad0bca9a4847a8fcc59f90fabb:bowerangularcookies/public/bower_components/angular-cookies
GH_TUPLE+=	urish:angular-moment:0.9.2:urishangularmoment/public/bower_components/angular-moment
GH_TUPLE+=	angular:bower-angular:v1.4.11:angularbowerangular/public/bower_components/angular
GH_TUPLE+=	angular:bower-angular-route:v1.4.11:angularbowerangularroute/public/bower_components/angular-route
GH_TUPLE+=	angular:bower-angular-sanitize:v1.4.11:angularbowerangularsanitize/public/bower_components/angular-sanitize
GH_TUPLE+=	twbs:bootstrap:v3.1.1:bootstrap/public/bower_components/bootstrap
GH_TUPLE+=	twbs:bootstrap-sass:v3.1.1:bootstrapsass/public/bower_components/bootstrap-sass-official
GH_TUPLE+=	foxandxss:angular-toastr:1.6.0:forandxssangulartoastr/public/bower_components/angular-toastr
GH_TUPLE+=	wallin:angular-gravatar:0.3.2:wallinangulargravatar/public/bower_components/angular-gravatar
GH_TUPLE+=	fortawesome:Font-Awesome:v4.4.0:fortawesomefontawesome/public/bower_components/fontawesome
GH_TUPLE+=	components:highlightjs:08edd75426b52b165cc2b8a569870df4794c36dc:componentshighlightjs/public/bower_components/highlightjs
GH_TUPLE+=	angular-ui:bootstrap-bower:0.13.4:angularuibootstrapbower/public/bower_components/angular-bootstrap
GH_TUPLE+=	moment:moment:2.8.4:momentmoment/public/bower_components/moment
GH_TUPLE+=	jquery:jquery-dist:3.0.0:jqueryjquery/public/bower_components/jquery
GH_TUPLE+=	jashkenas:underscore:1f4bf626f23a99f7a676f5076dc1b1475554c8f7:jashkenasunderscore/public/bower_components/underscore
GH_TUPLE+=	kless:osutil:3ac994847c4376a4b905fc0a19f450c5a4bec647:klessosutil/src/github.com/kless/osutil

USERS=	uchiwa
GROUPS=	uchiwa

post-extract:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in .travis.yml Gruntfile.js bower.json package.json uchiwa \
	Dockerfile LICENSE config.json.example public uchiwa.go .bowerrc \
	Godeps README.md fixtures
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.endfor

do-build:
	@cd ${WRKSRC}/src/github.com/sensu && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go install ./...

do-install:
	${MKDIR} ${STAGEDIR}${UCHIWA_LOGDIR} \
	${STAGEDIR}${UCHIWA_CONFDIR} \
	${STAGEDIR}${UCHIWA_SHAREDIR}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/uchiwa ${STAGEDIR}${PREFIX}/bin/uchiwa
	${INSTALL_DATA} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/config.json.example ${STAGEDIR}${PREFIX}/etc/uchiwa/config.json.sample
	(cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/public && ${COPYTREE_SHARE} . ${STAGEDIR}${UCHIWA_SHAREDIR})

.include <bsd.port.mk>
