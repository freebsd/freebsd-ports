# $FreeBSD$

PORTNAME=	uchiwa
PORTVERSION=	0.16.0
CATEGORIES=	www
MASTER_SITES=	http://uchiwa.io/

MAINTAINER=	alexander@treg.io
COMMENT=	Simple dashboard for Sensu

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.6.0:lang/go

UCHIWA_LOGDIR=	/var/log/uchiwa
UCHIWA_CONFDIR=	${PREFIX}/etc/uchiwa
UCHIWA_SHAREDIR=	${PREFIX}/share/uchiwa/public
UCHIWA_RCDIR=	${PREFIX}/etc/rc.d

USE_RC_SUBR=	uchiwa
USE_GITHUB=	yes
GH_ACCOUNT=	sensu:DEFAULT
GH_TUPLE=	dgrijalva:jwt-go:61124b62ad244d655f87d944aefaa2ae5a0d2f16:jwtgo
GH_TUPLE+=	gorilla:context:215affda49addc4c8ef7e2534915df2c8c35c6cd:context
GH_TUPLE+=	mitchellh:mapstructure:f7d28d5aeab42b9b95d2e6d6b956f73a290077fc:mapstructure
GH_TUPLE+=	palourde:mergo:d931ffd2c07cb4caf7194e0f6af9ac6771c26d54:mergo
GH_TUPLE+=	stretchr:objx:cbeaeb16a013161a98496fad62933b1d21786672:objx
GH_TUPLE+=	stretchr:testify:e4ec8152c15fc46bd5056ce65997a07c7d415325:testify
GH_TUPLE+=	sensu:uchiwa-web:0.16.0:uchiwaweb
GH_TUPLE+=	angular:bower-angular-cookies:b89821e37d3011ad0bca9a4847a8fcc59f90fabb:bowerangularcookies
GH_TUPLE+=	urish:angular-moment:0.9.2:urishangularmoment
GH_TUPLE+=	angular:bower-angular:v1.4.11:angularbowerangular
GH_TUPLE+=	angular:bower-angular-route:v1.4.11:angularbowerangularroute
GH_TUPLE+=	angular:bower-angular-sanitize:v1.4.11:angularbowerangularsanitize
GH_TUPLE+=	twbs:bootstrap:v3.1.1:bootstrap
GH_TUPLE+=	twbs:bootstrap-sass:v3.1.1:bootstrapsass
GH_TUPLE+=	foxandxss:angular-toastr:1.6.0:forandxssangulartoastr
GH_TUPLE+=	wallin:angular-gravatar:0.3.2:wallinangulargravatar
GH_TUPLE+=	fortawesome:font-awesome:v4.4.0:fortawesomefontawesome
GH_TUPLE+=	components:highlightjs:08edd75426b52b165cc2b8a569870df4794c36dc:componentshighlightjs
GH_TUPLE+=	angular-ui:bootstrap-bower:0.13.4:angularuibootstrapbower
GH_TUPLE+=	moment:moment:2.8.4:momentmoment
GH_TUPLE+=	jquery:jquery-dist:3.0.0:jqueryjquery
GH_TUPLE+=	jashkenas:underscore:1f4bf626f23a99f7a676f5076dc1b1475554c8f7:jashkenasunderscore
USERS=	uchiwa
GROUPS=	uchiwa

STRIP=	#

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/sensu/uchiwa
	@${MKDIR} ${WRKSRC}/src/github.com/dgrijalva
	@${MKDIR} ${WRKSRC}/src/github.com/gorilla
	@${MKDIR} ${WRKSRC}/src/github.com/mitchellh
	@${MKDIR} ${WRKSRC}/src/github.com/palourde
	@${MKDIR} ${WRKSRC}/src/github.com/stretchr
	@${MKDIR} ${WRKSRC}/src/github.com/stretchr/testify
	@${MKDIR} ${WRKSRC}/src/github.com/tools

.for src in .travis.yml Gruntfile.js bower.json package.json uchiwa \
	Dockerfile LICENSE config.json.example public uchiwa.go .bowerrc \
	Godeps README.md fixtures
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.endfor
	@${MV} ${WRKSRC_jwtgo} ${WRKSRC}/src/github.com/dgrijalva/jwt-go
	@${MV} ${WRKSRC_context} ${WRKSRC}/src/github.com/gorilla/context
	@${MV} ${WRKSRC_mapstructure} ${WRKSRC}/src/github.com/mitchellh/mapstructure
	@${MV} ${WRKSRC_mergo} ${WRKSRC}/src/github.com/palourde/mergo
	@${MV} ${WRKSRC_objx} ${WRKSRC}/src/github.com/stretchr/objx
	@${MV} ${WRKSRC_testify}/assert ${WRKSRC}/src/github.com/stretchr/testify/assert
	@${MV} ${WRKSRC_testify}/mock ${WRKSRC}/src/github.com/stretchr/testify/mock
	@${MKDIR} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components
	@${MV} ${WRKSRC_bowerangularcookies} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/angular-cookies
	@${MV} ${WRKSRC_urishangularmoment} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/angular-moment
	@${MV} ${WRKSRC_angularbowerangular} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/angular
	@${MV} ${WRKSRC_angularbowerangularroute} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/angular-route
	@${MV} ${WRKSRC_angularbowerangularsanitize} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/angular-sanitize
	@${MV} ${WRKSRC_bootstrap} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/bootstrap
	@${MV} ${WRKSRC_bootstrapsass} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/bootstrap-sass-official
	@${MV} ${WRKSRC_forandxssangulartoastr} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/angular-toastr
	@${MV} ${WRKSRC_wallinangulargravatar} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/angular-gravatar
	@${MV} ${WRKDIR}/Font-Awesome-4.4.0 ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/fontawesome
	@${MV} ${WRKSRC_componentshighlightjs} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/highlightjs
	@${MV} ${WRKSRC_angularuibootstrapbower} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/angular-bootstrap
	@${MV} ${WRKSRC_jqueryjquery} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/jquery
	@${MV} ${WRKSRC_jashkenasunderscore} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/underscore
	@${MV} ${WRKSRC_momentmoment} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/moment
	@${MV} ${WRKSRC_uchiwaweb} ${WRKSRC}/src/github.com/sensu/uchiwa/public/bower_components/uchiwa-web

do-build:
	@cd ${WRKSRC}/src/github.com/sensu && ${SETENV} GOPATH=${WRKSRC} go install ./...

do-install:
	${MKDIR} ${STAGEDIR}${UCHIWA_LOGDIR} \
	${STAGEDIR}${UCHIWA_CONFDIR} \
	${STAGEDIR}${UCHIWA_SHAREDIR} \
	${STAGEDIR}${UCHIWA_RCDIR}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/uchiwa ${STAGEDIR}${PREFIX}/bin/uchiwa
	${INSTALL_DATA} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/config.json.example ${STAGEDIR}${PREFIX}/etc/uchiwa/config.json.sample
	(cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/public && ${COPYTREE_SHARE} . ${STAGEDIR}${UCHIWA_SHAREDIR})

.include <bsd.port.mk>
