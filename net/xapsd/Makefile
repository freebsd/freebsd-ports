PORTNAME=	xapsd
DISTVERSION=	g20230329
CATEGORIES=	net

MAINTAINER=	PopularMoment@protonmail.com
COMMENT=	Apple push notifications daemon for dovecot
WWW=		https://github.com/freswa/dovecot-xaps-daemon

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	xapsd
USE_GITHUB=	yes
GH_ACCOUNT=	freswa
GH_PROJECT=	dovecot-xaps-daemon
GH_TAGNAME=	f6d5733

GH_TUPLE=	freswa:go-plist:900e8a7d907d:freswa_go_plist/vendor/github.com/freswa/go-plist \
		fsnotify:fsnotify:v1.6.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.67.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang-jwt:jwt:v4.5.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:net:v0.7.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.5.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.7.0:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		magiconair:properties:v1.8.7:magiconair_properties/vendor/github.com/magiconair/properties \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v2.0.6:pelletier_go_toml_v2/vendor/github.com/pelletier/go-toml/v2 \
		sideshow:apns2:v0.23.0:sideshow_apns2/vendor/github.com/sideshow/apns2 \
		sirupsen:logrus:v1.9.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.9.3:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.5.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.15.0:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.4.2:subosito_gotenv/vendor/github.com/subosito/gotenv

GO_TARGET=	./cmd/xapsd:${PREFIX}/sbin/xapsd

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

post-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/etc/xapsd
		${INSTALL_DATA} ${WRKSRC}/configs/xapsd/xapsd.yaml ${STAGEDIR}${PREFIX}/etc/xapsd/xapsd.yaml.sample

.include <bsd.port.mk>
