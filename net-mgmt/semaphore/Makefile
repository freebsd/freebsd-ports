PORTNAME=	semaphore
PORTVERSION=	2.8.53
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
GH_TUPLE=       ansible-semaphore:semaphore-vendor:a44f7be:ansible/vendor/github.com/ansible-semaphore/semaphore-vendor \
                Azure:go-ntlmssp:66371956d46c:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
                Sirupsen:logrus:v1.0.4:sirupsen_logrus/vendor/github.com/Sirupsen/logrus \
                airbrake:gobrake:v2.0.9:airbrake_gobrake/vendor/gopkg.in/airbrake/gobrake.v2 \
                etcd-io:bbolt:v1.3.2:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
                gemnasium:logrus-airbrake-hook:v2.1.2:gemnasium_logrus_airbrake_hook/vendor/gopkg.in/gemnasium/logrus-airbrake-hook.v2 \
                go-asn1-ber:asn1-ber:v1.5.1:go_asn1_ber_asn1_ber/vendor/github.com/go-asn1-ber/asn1-ber \
                go-gorp:gorp:v3.0.2:go_gorp_gorp_v3/vendor/github.com/go-gorp/gorp/v3 \
                go-ldap:ldap:v3.4.1:go_ldap_ldap_v3/vendor/github.com/go-ldap/ldap \
                go-sql-driver:mysql:v1.4.1:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
                gobuffalo:packr:v1.10.4:gobuffalo_packr/vendor/github.com/gobuffalo/packr \
                golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
                golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
                golang:sys:977fb7262007:golang_sys/vendor/golang.org/x/sys \
                google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
                google:go-querystring:v1.1.0:google_go_querystring/vendor/github.com/google/go-querystring \
                gorilla:context:1ea25387ff6f:gorilla_context/vendor/github.com/gorilla/context \
                gorilla:handlers:v1.4.2:gorilla_handlers/vendor/github.com/gorilla/handlers \
                gorilla:mux:v1.7.3:gorilla_mux/vendor/github.com/gorilla/mux \
                gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
                gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
                inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
                lann:builder:1b87b36280d0:lann_builder/vendor/github.com/lann/builder \
                lann:ps:62de8c46ede0:lann_ps/vendor/github.com/lann/ps \
                lib:pq:v1.2.0:lib_pq/vendor/github.com/lib/pq \
                masterminds:squirrel:a6b93000bd21:masterminds_squirrel/vendor/github.com/masterminds/squirrel \
                pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
                robfig:cron:v3.0.1:robfig_cron_v3/vendor/github.com/robfig/cron/v3 \
                sirupsen:logrus:v1.4.2:sirupsen_logrus_1/vendor/github.com/sirupsen/logrus \
                snikch:goodman:10e37e294daa:snikch_goodman/vendor/github.com/snikch/goodman \
                spf13:cobra:v1.2.1:spf13_cobra/vendor/github.com/spf13/cobra \
                spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag

post-patch:
	${REINPLACE_CMD} 's/%%PORTVERSION%%/${PORTVERSION}/g' \
	  ${WRKSRC}/util/config.go
	${REINPLACE_CMD} 's|%%DATADIR%%|${DATADIR}|g' \
	  ${WRKSRC}/db/sql/SqlDb.go

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${CP} ${WRKSRC}/config.json ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/config.json.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}
	${CP} ${WRKSRC}/db/sql/migrations/*.sql ${STAGEDIR}${PREFIX}/share/${PORTNAME}

.include <bsd.port.mk>
