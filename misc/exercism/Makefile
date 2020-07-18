# $FreeBSD$

PORTNAME=	exercism
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.13
CATEGORIES=	misc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CLI client for exercism.io

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_TUPLE=	exercism:cli:v${PORTVERSION}:DEFAULT \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fsnotify:fsnotify:v1.4.2:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-yaml:yaml:25c4ec802a7d:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:net:f5079bd7f6f7:golang_net/vendor/golang.org/x/net \
		golang:sys:d8f5ea21b929:golang_sys/vendor/golang.org/x/sys \
		golang:text:3bd178b88a81:golang_text/vendor/golang.org/x/text \
		hashicorp:hcl:392dba7d905e:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:go-update:8152e7eb6ccf:inconshreveable_go_update/vendor/github.com/inconshreveable/go-update \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		magiconair:properties:v1.7.3:magiconair_properties/vendor/github.com/magiconair/properties \
		mitchellh:mapstructure:d0303fe80992:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		pelletier:go-buffruneio:v0.2.0:pelletier_go_buffruneio/vendor/github.com/pelletier/go-buffruneio \
		pelletier:go-toml:v1.0.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		spf13:afero:9be650865eab:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.1.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:b26b538f6930:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:0efa5202c046:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.0:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:15738813a09d:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:testify:v1.1.4:stretchr_testify/vendor/github.com/stretchr/testify

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./exercism
GO_BUILDFLAGS=	-ldflags="\
		-s -w \
		-X github.com/exercism/cli/cmd.BuildOS=freebsd \
		-X github.com/exercism/cli/cmd.BuildARCH=${ARCH}"

PLIST_FILES=	bin/exercism

.include <bsd.port.mk>
