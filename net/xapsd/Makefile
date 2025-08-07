PORTNAME=	xapsd
DISTVERSION=	g20241228
PORTREVISION=	4
CATEGORIES=	net

MAINTAINER=	PopularMoment@protonmail.com
COMMENT=	Apple push notifications daemon for dovecot
WWW=		https://github.com/freswa/dovecot-xaps-daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
USE_RC_SUBR=	xapsd
USE_GITHUB=	yes
GH_ACCOUNT=	freswa
GH_PROJECT=	dovecot-xaps-daemon
GH_TAGNAME=	8cf4e49

GH_TUPLE=	freswa:go-plist:900e8a7d907d:freswa_go_plist/vendor/github.com/freswa/go-plist \
		fsnotify:fsnotify:v1.8.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang-jwt:jwt:v4.5.1:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:exp:b2144cdd0a67:golang_exp/vendor/golang.org/x/exp \
		golang:net:v0.33.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.28.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.21.0:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		magiconair:properties:v1.8.9:magiconair_properties/vendor/github.com/magiconair/properties \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v2.2.3:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		sagikazarmark:locafero:v0.6.0:sagikazarmark_locafero/vendor/github.com/sagikazarmark/locafero \
		sagikazarmark:slog-shim:v0.1.0:sagikazarmark_slog_shim/vendor/github.com/sagikazarmark/slog-shim \
		sideshow:apns2:v0.25.0:sideshow_apns2/vendor/github.com/sideshow/apns2 \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		sourcegraph:conc:v0.3.0:sourcegraph_conc/vendor/github.com/sourcegraph/conc \
		spf13:afero:v1.11.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.7.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.19.0:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.6.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr

GO_TARGET=	./cmd/xapsd:${PREFIX}/sbin/xapsd

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PORTSCOUT=	ignore:1

post-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/xapsd
		${INSTALL_DATA} ${WRKSRC}/configs/xapsd/xapsd.yaml ${STAGEDIR}${PREFIX}/etc/xapsd/xapsd.yaml.sample

.include <bsd.port.mk>
