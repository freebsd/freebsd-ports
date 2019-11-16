# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	termshark
PORTVERSION=	1.0.0
PORTREVISION=	2
DISTVERSIONPREFIX=v
CATEGORIES=	net

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Terminal UI for tshark, inspired by Wireshark

LICENSE=	MIT

RUN_DEPENDS=	tshark>0:net/tshark

USES=		go:modules

USE_GITHUB=	yes

GH_ACCOUNT=	gcla
GH_TUPLE=	\
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fsnotify:fsnotify:c282820:fsnotify_fsnotify_gh/vendor/github.com/fsnotify/fsnotify \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/gopkg.in/fsnotify.v1 \
		gcla:deep:v1.0.2:gcla_deep/vendor/github.com/gcla/deep \
		gcla:gowid:v1.0.0:gcla_gowid/vendor/github.com/gcla/gowid \
		gdamore:encoding:v1.0.0:gdamore_encoding/vendor/github.com/gdamore/encoding \
		gdamore:tcell:dcf1bb30770e:gdamore_tcell/vendor/github.com/gdamore/tcell \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:sys:12500544f89f:golang_sys/vendor/golang.org/x/sys \
		golang:text:17ff2d5776d2:golang_text/vendor/golang.org/x/text \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		lucasb-eyer:go-colorful:v1.0.2:lucasb_eyer_go_colorful/vendor/github.com/lucasb-eyer/go-colorful \
		magiconair:properties:v1.8.0:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-isatty:v0.0.7:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		shibukawa:configdir:e180dbdc8da0:shibukawa_configdir/vendor/github.com/shibukawa/configdir \
		sirupsen:logrus:v1.4.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.3.2:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.3.0:stretchr_testify/vendor/github.com/stretchr/testify

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
