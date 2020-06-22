# $FreeBSD$

PORTNAME=	librespeed-go
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	net www

MAINTAINER=	driesm.michiels@gmail.com
COMMENT=	GO backend for LibreSpeed

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	librespeed-go
USE_GITHUB=	YES
GH_ACCOUNT=	librespeed
GH_PROJECT=	speedtest-go
GH_TUPLE=	etcd-io:bbolt:v1.3.3:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-chi:chi:v4.0.3:go_chi_chi/vendor/github.com/go-chi/chi \
		go-chi:cors:v1.0.0:go_chi_cors/vendor/github.com/go-chi/cors \
		go-chi:render:v1.0.1:go_chi_render/vendor/github.com/go-chi/render \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:v2.2.4:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:freetype:e2365dfdc4a0:golang_freetype/vendor/github.com/golang/freetype \
		golang:image:58c23975cae1:golang_image/vendor/golang.org/x/image \
		golang:sys:953cdadca894:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lib:pq:v1.3.0:lib_pq/vendor/github.com/lib/pq \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		oklog:ulid:v2.0.2:oklog_ulid_v2/vendor/github.com/oklog/ulid/v2 \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.6.2:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv

USERS=		librespeed
GROUPS=		librespeed

SUB_FILES=	pkg-message
PLIST_SUB=	LIBRESPEED_USER=${USERS} LIBRESPEED_GROUP=${GROUPS}
SUB_LIST=	LIBRESPEED_USER=${USERS} LIBRESPEED_GROUP=${GROUPS} PORTNAME=${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${REINPLACE_CMD} -e 's|"."|"${ETCDIR}"|g' ${WRKSRC}/config/config.go
	${REINPLACE_CMD} -e 's|"./assets"|"${WWWDIR}"|g' ${WRKSRC}/config/config.go

pre-install:
	${REINPLACE_CMD} -e 's|"./assets"|"${WWWDIR}"|g' ${WRKSRC}/settings.toml
	${REINPLACE_CMD} -e 's|"speedtest.db"|"/var/db/${PORTNAME}/speedtest.db"|g' ${WRKSRC}/settings.toml

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -a ${WRKSRC}/assets/*.js ${STAGEDIR}${WWWDIR}
	${CP} -a ${WRKSRC}/assets/*.ttf ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/settings.toml ${STAGEDIR}${ETCDIR}/settings.toml.sample
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -a ${WRKSRC}/assets/*.html ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
