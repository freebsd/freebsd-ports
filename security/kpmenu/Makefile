PORTNAME=	kpmenu
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.1
PORTREVISION=	28
CATEGORIES=	security

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Dmenu/rofi interface for KeePass
WWW=		https://www.alessiodp.com/kpmenu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dmenu:x11/dmenu \
		xsel:x11/xsel-conrad

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	AlessioDP

GH_TUPLE=	\
		aead:argon2:a87724528b07:aead_argon2/vendor/github.com/aead/argon2 \
		aead:chacha20:8b13a72661da:aead_chacha20/vendor/github.com/aead/chacha20 \
		fsnotify:fsnotify:v1.5.1:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-check:check:41f04d3bba15:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.66.3:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:30dcbda58838:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		google:shlex:e7afc7fbc510:google_shlex/vendor/github.com/google/shlex \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		kr:pretty:v0.2.0:kr_pretty/vendor/github.com/kr/pretty \
		magiconair:properties:v1.8.5:magiconair_properties/vendor/github.com/magiconair/properties \
		mitchellh:mapstructure:v1.4.3:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.9.4:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		spf13:afero:v1.8.0:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.4.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.10.1:spf13_viper/vendor/github.com/spf13/viper \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tobischo:gokeepasslib:v3.2.4:tobischo_gokeepasslib_v3/vendor/github.com/tobischo/gokeepasslib/v3

PLIST_FILES=	bin/kpmenu

.include <bsd.port.mk>
