# $FreeBSD$

PORTNAME=	semaphore
PORTVERSION=	2.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Open Source alternative to Ansible Tower

LICENSE=	MIT
LICENSE_FILE=	${GO_WRKSRC}/LICENSE

RUN_DEPENDS=	ansible:sysutils/ansible \
		git:devel/git

USES=		go
USE_GITHUB=	yes
USE_RC_SUBR=	semaphore

GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}

GH_ACCOUNT=	ansible-semaphore
GH_TUPLE=	ansible-semaphore:semaphore-vendor:a44f7be:ansible/github.com/ansible-semaphore/semaphore-vendor \
		PuerkitoBio:purell:v1.1.0:PuerkitoBio/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2a:PuerkitoBio2/github.com/PuerkitoBio/urlesc \
		Sirupsen:logrus:v1.0.4:Sirupsen/github.com/Sirupsen/logrus \
		asaskevich:govalidator:v9:asaskevich/github.com/asaskevich/govalidator \
		castawaylabs:mulekick:7029fb3:castawaylabs/github.com/castawaylabs/mulekick \
		go-openapi:analysis:f59a71f:openapi/github.com/go-openapi/analysis \
		go-openapi:errors:7bcb96a:openapi2/github.com/go-openapi/errors \
		go-openapi:jsonpointer:3a0015a:openapi3/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:3fb327e:openapi4/github.com/go-openapi/jsonreference \
		go-openapi:loads:2a2b323:openapi5/github.com/go-openapi/loads \
		go-openapi:runtime:62281b6:openapi6/github.com/go-openapi/runtime \
		go-openapi:spec:370d9e0:openapi7/github.com/go-openapi/spec \
		go-openapi:strfmt:4818084:openapi8/github.com/go-openapi/strfmt \
		go-openapi:swag:811b108:openapi9/github.com/go-openapi/swag \
		go-openapi:validate:180bba5:openapi10/github.com/go-openapi/validate \
		go-sql-driver:mysql:v1.3:sqldriver/github.com/go-sql-driver/mysql \
		gobuffalo:packr:v1.10.4:buffalo/github.com/gobuffalo/packr \
		google:go-github:v15.0.0:google/github.com/google/go-github \
		google:go-querystring:53e6ce1:google2/github.com/google/go-querystring \
		gorilla:context:v1.1:gorilla/github.com/gorilla/context \
		gorilla:handlers:v1.3.0:gorilla2/github.com/gorilla/handlers \
		gorilla:mux:v1.6.1:gorilla3/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla4/github.com/gorilla/securecookie \
		gorilla:websocket:v1.2.0:gorilla5/github.com/gorilla/websocket \
		lann:builder:1b87b36:lann/github.com/lann/builder \
		lann:ps:62de8c4:lann2/github.com/lann/ps \
		mailru:easyjson:8b799c4:mailru/github.com/mailru/easyjson \
		masterminds:squirrel:v1.0:mastermindos/github.com/masterminds/squirrel \
		mitchellh:mapstructure:00c29f5:mitchellh/github.com/mitchellh/mapstructure \
		pkg:errors:v0.8.0:pkg/github.com/pkg/errors \
		russross:blackfriday:v1.5.1:russross/github.com/russross/blackfriday \
		golang:net:61147c4:golang/golang.org/x/net \
		golang:sys:7dca6fe:golang2/golang.org/x/sys \
		golang:text:v0.3.0:golang3/golang.org/x/text \
		golang:crypto:c7dcf10:golang4/golang.org/x/crypto \
		go-asn1-ber:asn1-ber:v1.2:pkgin/gopkg.in/asn1-ber.v1 \
		go-gorp:gorp:v1.7.1:pkgin2/gopkg.in/gorp.v1 \
		go-ldap:ldap:v2.5.1:pkgin3/gopkg.in/ldap.v2 \
		go-mgo:mgo:3f83fa5:pkgin4/gopkg.in/mgo.v2 \
		go-yaml:yaml:v2.2.1:pkgin5/gopkg.in/yaml.v2

OPTIONS_DEFINE=	MYSQL
MYSQL_USES=	mysql

post-patch:
	${REINPLACE_CMD} 's/%%PORTVERSION%%/${PORTVERSION}/g' \
	  ${WRKSRC}/util/config.go

do-build:
	${MKDIR} ${WRKSRC}/${GO_TARGET:H}
	${MKDIR} ${WRKSRC}/public
	${RLN} ${WRKSRC} ${WRKSRC}/${GO_TARGET}
	${RLN} ${WRKSRC} ${GO_WRKSRC}/src
	${RLN} ${WRKSRC} ${GO_WRKSRC}/public/vendor
	(cd ${WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GO_ENV} GOPATH=${WRKSRC} ${GO_CMD} \
	  build ${GO_BUILDFLAGS} -o ${WRKSRC}/bin/${PORTNAME} cli)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/semaphore
	${CP} ${WRKSRC}/config.json ${STAGEDIR}${PREFIX}/etc/semaphore/semaphore_config.json.sample

.include <bsd.port.mk>
