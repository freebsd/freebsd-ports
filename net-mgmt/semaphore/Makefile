PORTNAME=	semaphore
PORTVERSION=	2.9.2
DISTVERSIONPREFIX=	v
PORTREVISION=	14
CATEGORIES=	net-mgmt

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Open Source alternative to Ansible Tower
WWW=		https://www.ansible-semaphore.com/

LICENSE=	MIT
LICENSE_FILE=	${GO_WRKSRC}/LICENSE

RUN_DEPENDS=	ansible:sysutils/py-ansible-core@${PY_FLAVOR} \
		git:devel/git

USES=		go:modules python:env
USE_GITHUB=	yes
USE_RC_SUBR=	semaphore

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cli:${PORTNAME}
GO_BUILDFLAGS=	-ldflags '-s -w -extldflags "-static"'

GH_ACCOUNT=	ansible-semaphore
GH_TUPLE=	ansible-semaphore:semaphore-vendor:a44f7be:ansible/vendor/github.com/ansible-semaphore/semaphore-vendor \
		Azure:go-ntlmssp:66371956d46c:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		Microsoft:go-winio:v0.5.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:cf6655e29de4:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		Sirupsen:logrus:v1.0.4:sirupsen_logrus/vendor/github.com/Sirupsen/logrus \
		acomagu:bufpipe:v1.0.3:acomagu_bufpipe/vendor/github.com/acomagu/bufpipe \
		airbrake:gobrake:v2.0.9:airbrake_gobrake/vendor/gopkg.in/airbrake/gobrake.v2 \
		cloudflare:circl:v1.1.0:cloudflare_circl/vendor/github.com/cloudflare/circl \
		coreos:go-oidc:v3.5.0:coreos_go_oidc_v3/vendor/github.com/coreos/go-oidc/v3 \
		emirpasic:gods:v1.18.1:emirpasic_gods/vendor/github.com/emirpasic/gods \
		etcd-io:bbolt:v1.3.2:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		gemnasium:logrus-airbrake-hook:v2.1.2:gemnasium_logrus_airbrake_hook/vendor/gopkg.in/gemnasium/logrus-airbrake-hook.v2 \
		go-asn1-ber:asn1-ber:v1.5.1:go_asn1_ber_asn1_ber/vendor/github.com/go-asn1-ber/asn1-ber \
		go-git:gcfg:v1.5.0:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.4.0:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.4.2:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-gorp:gorp:v3.0.2:go_gorp_gorp_v3/vendor/github.com/go-gorp/gorp/v3 \
		go-jose:go-jose:v3.0.0:go_jose_go_jose_v3/vendor/github.com/go-jose/go-jose/v3 \
		go-ldap:ldap:v3.4.1:go_ldap_ldap_v3/vendor/github.com/go-ldap/ldap \
		go-sql-driver:mysql:v1.4.1:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		gobuffalo:packr:v1.10.4:gobuffalo_packr/vendor/github.com/gobuffalo/packr \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:v0.3.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.9.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.7.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.7.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.7.0:golang_term/vendor/golang.org/x/term \
		google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:v1.1.0:google_go_querystring/vendor/github.com/google/go-querystring \
		gorilla:context:v1.1.1:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:handlers:v1.4.2:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.7.3:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		imdario:mergo:v0.3.13:imdario_mergo/vendor/github.com/imdario/mergo \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		kevinburke:ssh_config:v1.2.0:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		lann:builder:1b87b36280d0:lann_builder/vendor/github.com/lann/builder \
		lann:ps:62de8c46ede0:lann_ps/vendor/github.com/lann/ps \
		lib:pq:v1.2.0:lib_pq/vendor/github.com/lib/pq \
		masterminds:squirrel:a6b93000bd21:masterminds_squirrel/vendor/github.com/masterminds/squirrel \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		protocolbuffers:protobuf-go:v1.28.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		robfig:cron:v3.0.1:robfig_cron_v3/vendor/github.com/robfig/cron/v3 \
		sergi:go-diff:v1.1.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		snikch:goodman:10e37e294daa:snikch_goodman/vendor/github.com/snikch/goodman \
		spf13:cobra:v1.2.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		xanzy:ssh-agent:v0.3.3:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent

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
