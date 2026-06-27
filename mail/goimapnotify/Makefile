PORTNAME=	goimapnotify
DISTVERSION=	2.5.6
CATEGORIES=	mail

MAINTAINER=	juw@posteo.de
COMMENT=	Execute scripts on IMAP mailbox changes using IDLE
WWW=		https://gitlab.com/shackra/goimapnotify

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	emersion:go-imap-id:f94a56b9ecde:emersion_go_imap_id/vendor/github.com/emersion/go-imap-id \
		emersion:go-imap-idle:db2568431445:emersion_go_imap_idle/vendor/github.com/emersion/go-imap-idle \
		emersion:go-imap:v1.2.1:emersion_go_imap/vendor/github.com/emersion/go-imap \
		emersion:go-sasl:e73c9f7bad43:emersion_go_sasl/vendor/github.com/emersion/go-sasl \
		fatih:color:v1.16.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.7.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:exp:921286631fa9:golang_exp/vendor/golang.org/x/exp \
		golang:sys:v0.18.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		magiconair:properties:v1.8.7:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v2.2.2:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		sagikazarmark:locafero:v0.4.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sagikazarmark:slog-shim:v0.1.0:sagikazarmark_slog_shim/vendor/github.com/sagikazarmark/slog-shim \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sourcegraph:conc:v0.3.0:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spf13:afero:v1.11.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.6.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.19.0:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.9.0:uber_go_multierr/vendor/go.uber.org/multierr
USE_GITLAB=	yes
GL_ACCOUNT=	shackra
USE_RC_SUBR=	${PORTNAME}

GO_TARGET=	./cmd/${PORTNAME}
_BUILD_COMMIT=	251292f1
_BUILD_XFLAGS=	main.commit=${_BUILD_COMMIT} \
		main.gittag=${DISTVERSIONFULL} \
		main.branch=master
GO_BUILDFLAGS=	-ldflags="${STRIP} ${_BUILD_XFLAGS:S!^!-X !}"

SUB_FILES=	pkg-message
SUB_LIST=	ETCDIR="${ETCDIR}" \
		GROUPS="${IMAPNOTIFYGROUP}" \
		USERS="${IMAPNOTIFYUSER}"

IMAPNOTIFYUSER?=	${PORTNAME}
IMAPNOTIFYGROUP?=	${PORTNAME}
.if ${IMAPNOTIFYUSER} == ${PORTNAME}
USERS=		${PORTNAME}
.endif
.if ${IMAPNOTIFYGROUP} == ${PORTNAME}
GROUPS=		${PORTNAME}
.endif

PLIST_FILES=	"@sample(${USERS},${GROUPS},640) ${ETCDIR}/${PORTNAME}.yaml.sample" \
		bin/${PORTNAME}

post-patch:
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.yaml.sample \
		${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
