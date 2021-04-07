PORTNAME=	semaphore
PORTVERSION=	2.6.8
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Open Source alternative to Ansible Tower

LICENSE=	MIT
LICENSE_FILE=	${GO_WRKSRC}/LICENSE

RUN_DEPENDS=	ansible:sysutils/ansible \
		git:devel/git

USES=		go:modules
USE_GITHUB=	yes
USE_RC_SUBR=	semaphore

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cli:${PORTNAME}

GH_ACCOUNT=	ansible-semaphore
GH_TUPLE=	ansible-semaphore:semaphore-vendor:a44f7be:ansible/vendor/github.com/ansible-semaphore/semaphore-vendor \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		Sirupsen:logrus:v1.0.4:sirupsen_logrus/vendor/github.com/Sirupsen/logrus \
		asaskevich:govalidator:475eaeb16496:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		go-asn1-ber:asn1-ber:379148ca0225:go_asn1_ber_asn1_ber/vendor/gopkg.in/asn1-ber.v1 \
		go-gorp:gorp:v1.7.1:go_gorp_gorp/vendor/gopkg.in/gorp.v1 \
		go-ldap:ldap:v2.5.1:go_ldap_ldap/vendor/gopkg.in/ldap.v2 \
		go-openapi:analysis:v0.19.7:go_openapi_analysis/vendor/github.com/go-openapi/analysis \
		go-openapi:errors:v0.19.3:go_openapi_errors/vendor/github.com/go-openapi/errors \
		go-openapi:jsonpointer:v0.19.3:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.3:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:loads:v0.19.4:go_openapi_loads/vendor/github.com/go-openapi/loads \
		go-openapi:spec:v0.19.6:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:strfmt:v0.19.4:go_openapi_strfmt/vendor/github.com/go-openapi/strfmt \
		go-openapi:swag:v0.19.7:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-sql-driver:mysql:v1.3.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:packr:v1.10.4:gobuffalo_packr/vendor/github.com/gobuffalo/packr \
		golang:crypto:ecb85df21340:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:6afb5195e5aa:golang_net/vendor/golang.org/x/net \
		golang:sys:d101bd2416d5:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-github:v15.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:53e6ce116135:google_go_querystring/vendor/github.com/google/go-querystring \
		gorilla:context:1ea25387ff6f:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:handlers:v1.4.2:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.7.3:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		lann:builder:1b87b36280d0:lann_builder/vendor/github.com/lann/builder \
		lann:ps:62de8c46ede0:lann_ps/vendor/github.com/lann/ps \
		mailru:easyjson:v0.7.0:mailru_easyjson/vendor/github.com/mailru/easyjson \
		masterminds:squirrel:a6b93000bd21:masterminds_squirrel/vendor/github.com/masterminds/squirrel \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mongodb:mongo-go-driver:v1.2.1:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		russross:blackfriday:v1.5.2:russross_blackfriday/vendor/github.com/russross/blackfriday

post-patch:
	${REINPLACE_CMD} 's/%%PORTVERSION%%/${PORTVERSION}/g' \
	  ${WRKSRC}/util/config.go

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${CP} ${WRKSRC}/config.json ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/config.json.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}
	${CP} ${WRKSRC}/db/migrations/*.sql ${STAGEDIR}${PREFIX}/share/${PORTNAME}

.include <bsd.port.mk>
