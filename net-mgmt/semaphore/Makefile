PORTNAME=	semaphore
DISTVERSIONPREFIX=	v
DISTVERSION=	2.19.7
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES+=	https://github.com/joneum/FreeBSD-Semaphore/releases/download/${PORTNAME}-${DISTVERSION}/:webui
DISTFILES+=	${PORTNAME}-webui-${DISTVERSION}${EXTRACT_SUFX}:webui \
		${PORTNAME}-provendor-${DISTVERSION}${EXTRACT_SUFX}:webui

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Open Source alternative to Ansible Tower
WWW=		https://semaphoreui.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ansible:sysutils/py-ansible-core@${PY_FLAVOR} \
		git:devel/git

USES=		go:1.26,modules python:env
USE_GITHUB=	yes
GH_ACCOUNT=	semaphoreui
GH_TUPLE=	Azure:go-ntlmssp:v0.1.1:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		FiloSottile:edwards25519:v1.2.0:filosottile_edwards25519/vendor/filippo.io/edwards25519 \
		Masterminds:squirrel:v1.5.4:masterminds_squirrel/vendor/github.com/Masterminds/squirrel \
		Microsoft:go-winio:v0.6.2:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		ProtonMail:go-crypto:v1.4.1:protonmail_go_crypto/vendor/github.com/ProtonMail/go-crypto \
		boombuler:barcode:v1.1.0:boombuler_barcode/vendor/github.com/boombuler/barcode \
		cloudflare:circl:v1.6.3:cloudflare_circl/vendor/github.com/cloudflare/circl \
		coreos:go-oidc:v3.19.0:coreos_go_oidc_v3/vendor/github.com/coreos/go-oidc/v3 \
		creack:pty:v1.1.24:creack_pty/vendor/github.com/creack/pty \
		cyphar:filepath-securejoin:v0.6.1:cyphar_filepath_securejoin/vendor/github.com/cyphar/filepath-securejoin \
		davecgh:go-spew:d8f796af33cc:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		emirpasic:gods:v1.18.1:emirpasic_gods/vendor/github.com/emirpasic/gods \
		felixge:httpsnoop:v1.1.0:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		go-asn1-ber:asn1-ber:29230038a667:go_asn1_ber_asn1_ber/vendor/github.com/go-asn1-ber/asn1-ber \
		go-git:gcfg:3a3c6141e376:go_git_gcfg/vendor/github.com/go-git/gcfg \
		go-git:go-billy:v5.9.0:go_git_go_billy_v5/vendor/github.com/go-git/go-billy/v5 \
		go-git:go-git:v5.19.1:go_git_go_git_v5/vendor/github.com/go-git/go-git/v5 \
		go-gorp:gorp:v3.1.0:go_gorp_gorp_v3/vendor/github.com/go-gorp/gorp/v3 \
		go-jose:go-jose:v4.1.4:go_jose_go_jose_v4/vendor/github.com/go-jose/go-jose/v4 \
		go-ldap:ldap:v3.4.13:go_ldap_ldap_v3/vendor/github.com/go-ldap/ldap \
		go-sql-driver:mysql:v1.10.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-warnings:warnings:v0.1.2:go_warnings_warnings/vendor/gopkg.in/warnings.v0 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.53.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:2c02b8208cf8:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:v0.56.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.36.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sys:v0.46.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.44.0:golang_term/vendor/golang.org/x/term \
		google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:v1.2.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:handlers:v1.5.2:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.2:gorilla_securecookie/vendor/github.com/gorilla/securecookie \
		gorilla:websocket:e064f32e3674:gorilla_websocket/vendor/github.com/gorilla/websocket \
		imdario:mergo:v1.0.2:imdario_mergo/vendor/dario.cat/mergo \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jbenet:go-context:d14ea06fba99:jbenet_go_context/vendor/github.com/jbenet/go-context \
		kevinburke:ssh_config:v1.6.0:kevinburke_ssh_config/vendor/github.com/kevinburke/ssh_config \
		klauspost:cpuid:v2.3.0:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		lann:builder:47ae307949d0:lann_builder/vendor/github.com/lann/builder \
		lann:ps:62de8c46ede0:lann_ps/vendor/github.com/lann/ps \
		lib:pq:v1.12.3:lib_pq/vendor/github.com/lib/pq \
		mattn:go-isatty:v0.0.22:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mdp:qrterminal:v3.2.1:mdp_qrterminal_v3/vendor/github.com/mdp/qrterminal/v3 \
		natefinch:lumberjack:v2.2.1:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		ncruces:go-strftime:v1.0.0:ncruces_go_strftime/vendor/github.com/ncruces/go-strftime \
		pjbgf:sha1cd:v0.6.0:pjbgf_sha1cd/vendor/github.com/pjbgf/sha1cd \
		pmezard:go-difflib:5d4384ee4fb2:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pquerna:otp:v1.5.0:pquerna_otp/vendor/github.com/pquerna/otp \
		remyoudompheng:bigfft:24d4a6f8daec:remyoudompheng_bigfft/vendor/github.com/remyoudompheng/bigfft \
		robfig:cron:v3.0.1:robfig_cron_v3/vendor/github.com/robfig/cron/v3 \
		rsc:qr:v0.2.0:rsc_qr/vendor/rsc.io/qr \
		sergi:go-diff:v1.4.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		sirupsen:logrus:v1.9.4:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		skeema:knownhosts:v1.3.2:skeema_knownhosts/vendor/github.com/skeema/knownhosts \
		snikch:goodman:10e37e294daa:snikch_goodman/vendor/github.com/snikch/goodman \
		spf13:cobra:v1.10.2:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.10:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.11.1:stretchr_testify/vendor/github.com/stretchr/testify \
		thedevsaddam:gojsonq:v2.5.2:thedevsaddam_gojsonq_v2/vendor/github.com/thedevsaddam/gojsonq/v2 \
		xanzy:ssh-agent:v0.3.3:xanzy_ssh_agent/vendor/github.com/xanzy/ssh-agent
USE_GITLAB=	nodefault
GL_TUPLE=	cznic:libc:533f38d8beab45d5a69acb60903422d454f0fac1:cznic_libc/vendor/modernc.org/libc \
		cznic:mathutil:28129eec384c30a304561c3c8779e4bb29cbff12:cznic_mathutil/vendor/modernc.org/mathutil \
		cznic:memory:0a6f7544739330ad95572cc272626a60176f2faf:cznic_memory/vendor/modernc.org/memory \
		cznic:sqlite:66b4d20f42485b9823a2d35c86b08335d927d0e5:cznic_sqlite/vendor/modernc.org/sqlite
USE_RC_SUBR=	semaphore

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cli:${PORTNAME}
GO_BUILDFLAGS=	-trimpath \
		-ldflags '-s -w -X ${GO_PKGNAME}/util.Ver=${DISTVERSION}'

SUB_FILES=	pkg-message

post-extract:
	@${MV} ${WRKDIR}/public ${WRKSRC}/api/public
	@${MKDIR} ${WRKSRC}/vendor/github.com/semaphoreui/semaphore
	@${CP} -R ${WRKDIR}/vendor/github.com/semaphoreui/semaphore/pro \
		${WRKSRC}/vendor/github.com/semaphoreui/semaphore/pro
	@${CP} ${WRKDIR}/vendor/modules.txt ${WRKSRC}/vendor/modules.txt

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/config.json.sample \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}/config.json.sample

.include <bsd.port.mk>
