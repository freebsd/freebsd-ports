PORTNAME=	bapu
PORTVERSION=	0.3.0
PORTREVISION=	28
CATEGORIES=	net
MASTER_SITES=	https://bitbucket.org/carlostrub/bapu/get/
PKGNAMEPREFIX=	go-
DISTNAME=	v${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	go-bapu

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Virtual Machine Controller for Gandi.net
WWW=		https://bitbucket.org/carlostrub/bapu

LICENSE=	BSD3CLAUSE

USES=		go:modules tar:bzip2

USE_GITHUB=	nodefault
GH_TUPLE=	\
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		gizak:termui:f63e0cdd3f66:gizak_termui/vendor/github.com/gizak/termui \
		go-check:check:8fa46927fb4f:go_check_check/vendor/gopkg.in/check.v1 \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		kolo:xmlrpc:0826b98aaa29:kolo_xmlrpc/vendor/github.com/kolo/xmlrpc \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		maruel:panicparse:ad661195ed0e:maruel_panicparse/vendor/github.com/maruel/panicparse \
		maruel:ut:v1.0.1:maruel_ut/vendor/github.com/maruel/ut \
		mattn:go-runewidth:737072b4e32b:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-wordwrap:ad45545899c7:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		niemeyer:pretty:a10e7caefd8e:niemeyer_pretty/vendor/github.com/niemeyer/pretty \
		nsf:termbox-go:abe82ce5fb7a:nsf_termbox_go/vendor/github.com/nsf/termbox-go \
		pelletier:go-buffruneio:v0.1.0:pelletier_go_buffruneio/vendor/github.com/pelletier/go-buffruneio \
		pelletier:go-toml:v1.8.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.0:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv

WRKSRC=		${WRKDIR}/carlostrub-bapu-23ca6b019fbc

post-install:
	${CP} -R ${WRKSRC}/bapu.toml.sample ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
